//
// Created by Mario Martinez on 09/10/20.
//


#include "ListaJugadorOrdenada.h"

ListaJugadorOrdenada::ListaJugadorOrdenada() {
    setTam(0);
    setFrente(nullptr);
    setFinal(nullptr);
}

ListaJugadorOrdenada::~ListaJugadorOrdenada() {

}

NodoJugador *ListaJugadorOrdenada::getFrente() const {
    return frente;
}

void ListaJugadorOrdenada::setFrente(NodoJugador *frente) {
    ListaJugadorOrdenada::frente = frente;
}

NodoJugador *ListaJugadorOrdenada::getFinal() const {
    return final;
}

void ListaJugadorOrdenada::setFinal(NodoJugador *final) {
    ListaJugadorOrdenada::final = final;
}

int ListaJugadorOrdenada::getTam() const {
    return tam;
}

void ListaJugadorOrdenada::setTam(int tam) {
    ListaJugadorOrdenada::tam = tam;
}

void ListaJugadorOrdenada::posicionNodo(NodoJugador *nodo) {
    nodo->setPos(getTam()); // se incrementa al valor de la posición que es igual al tamaño
}
/**
 * Método:          renumerarPosicionNodos
 * Descripción:     método que permite renumerar el valor de la posición de los nodos a poartir del valor
 * de posición recibido por parámetro.
 * @param nodo      representa el nodo a partir del cual se hará la renumeración de las posiciones.
 * @param posicion  valor de la posición del último nodo conocido, y que se debe modificar.
 */
void ListaJugadorOrdenada::renumerarPosicionNodos(NodoJugador *nodo, int posicion) {
    NodoJugador * aux2 = nodo;
    int i = posicion;
    do { // ajustar numeración
        aux2->setPos(i);
        aux2 = aux2->getNext();
        i++;
    } while (aux2 != nullptr);
}
/**
 * Método:          recorrerListaRecursiva
 * Descripción:     Método que permite recorrer la lisa de forma recursiva
 * @param nodo      variable de tipo Nodo, que contiene la lista
 * @return          variable de tipo string que contiene la información de la lista
 */
string ListaJugadorOrdenada::recorrerListaRecursiva(NodoJugador *nodo) {
    string resultado = "El ranking por jugador es:\n";
    if (getFrente() == nullptr) {
        return "La lista está vacía\n";
    } else if(nodo == getFinal()) {
        return nodo->getJugador().getNombre() + " puntos: " + to_string(nodo->getPuntaje()) + "\n"; // se agrega para que en el último ciclo incluya el dato de tail
    } else {
        resultado += recorrerListaRecursiva(nodo->getNext()) +
                     nodo->getJugador().getNombre() + " puntos: " + to_string(nodo->getPuntaje()) + "\n";
    }
    return resultado;
}
/**
 * Método:          mostrarListaRecursiva
 * Descripción:     método que permite invocar un métod privado para recorrer
 * la lista utilizando recursividad, este método es público, e invoca un método
 * privado, de forma que se mantenga
 * el encapsulamiento de la función.
 * @return          una variable de tipo string con el valor de la información de
 * cada nodo.
 */
string ListaJugadorOrdenada::mostrarListaRecursiva() {
    return recorrerListaRecursiva(getFrente());
}
/**
 * Método:          buscarPosicion
 * Descripción:     método que permite buscar la posición de nodo recibiendo como parámetro
 * el nombre del jugador. Si existen dos nodos con la misma información, retorna la posición
 * del primero.
 * @param nombre       variable de tipo int que representa la información que contiene el nodo a buscar.
 * @return          variable de tipo int que retorna el valor de la posición del nodo
 */
int ListaJugadorOrdenada::buscarPosicion(string nombre) {
    int pos = -1;
    if (getFrente() == nullptr) { // No se han agregado elementos al nodo
        return 0;
    } else { // ya hay elementos en el nodo
        NodoJugador *aux = getFrente();
        do {
            if (aux->getJugador().getNombre() == nombre) {
                pos = aux->getPos();
                break;
            }
            aux = aux->getNext();
        } while (aux != nullptr);
    }
    return pos;
}
/**
 * Método:          eliminarLista
 * Descripción:     método que permite eliminar una lista
 */
void ListaJugadorOrdenada::eliminarLista() {
    NodoJugador * borrar = getFrente();
    while (borrar != nullptr){
        setFrente(getFrente()->getNext());
        delete borrar;
        borrar = getFrente();
    }
    setFinal(nullptr);
    setTam(0);

}

bool ListaJugadorOrdenada::insertarAlInicio(Jugador & jugador, int puntaje) {
    if (getFrente() == nullptr){
        setFrente(new NodoJugador(jugador));
        setFinal(getFrente());
    } else {
        NodoJugador * nuevo = new NodoJugador(jugador);
        nuevo->setNext(getFrente());
        setFrente(nuevo);
    }
    getFrente()->setPuntaje(puntaje);
    setTam(getTam() + 1);
    renumerarPosicionNodos(getFrente(), 1);
    return true;
}

bool ListaJugadorOrdenada::insertarAlFinal(Jugador & jugador, int puntaje) {
    if (getFrente() == nullptr){
        setFrente(new NodoJugador(jugador));
        setFinal(getFrente());
    } else {
        NodoJugador * nuevo = new NodoJugador(jugador);
        getFinal()->setNext(nuevo);
        setFinal(nuevo);
    }
    getFinal()->setPuntaje(puntaje);
    setTam(getTam() + 1);
    posicionNodo(getFinal());
    return true;
}

bool ListaJugadorOrdenada::insertarOrdenado(Jugador & jugador, int puntaje) {
    if (getFrente() == nullptr){
        setFrente(new NodoJugador(jugador));
        setFinal(getFrente());
        setTam(getTam() + 1);
        getFrente()->setPos(getTam());
        getFrente()->setPuntaje(puntaje);
    } else {
        if (getFrente()->getPuntaje() <= puntaje) { // insertar al inicio
            insertarAlInicio(jugador, puntaje);
        } else if (getFinal()->getPuntaje() >= puntaje) { // insertar al final
            insertarAlFinal(jugador, puntaje);
        } else {
            NodoJugador * aux = getFrente();
            do {
                if (aux->getPuntaje() >= puntaje & aux->getNext()->getPuntaje() <= puntaje) {
                    NodoJugador * nuevo = new NodoJugador(jugador);
                    nuevo->setPuntaje(puntaje);
                    nuevo->setNext(aux->getNext());
                    aux->setNext(nuevo);
                    setTam(getTam() + 1);
                    renumerarPosicionNodos(aux, aux->getPos());
                    break;
                }
                aux = aux->getNext();
            } while (aux->getNext() != nullptr);
        }
    }
    return true;
}
/**
 * Método:          eliminarPorContenido
 * Descripción:     Método que permite eliminar un nodo recibiendo como parámetro
 * el valor de la información contenida, si dos nodos tienen la misma información
 * se elimina el primer nodo que la contenga.
 * @param nombreJugador    variable de tipo string que representa el nombre del
 * del Objeto jugador que se va a eliminar.
 * @return          variable de tipo boolean que representa la respuesta a la solicitud
 * si es true, la información se ubicó y fue eliminada, si fue false, no se ubicó.
 */
bool ListaJugadorOrdenada::eliminarPorContenido(string nombreJugador) {
    if (getFrente() == nullptr){
        return false;
    } else { // hay elementos en el nodo
        NodoJugador * borrar = getFrente();
        NodoJugador * previo = nullptr;
        do {
            if (borrar->getJugador().getNombre() == nombreJugador){
                break;
            }
            previo = borrar;
            borrar = borrar->getNext();
        } while (borrar != nullptr);
        if (borrar == nullptr){ // el valor no existe en la lista
            return false;
        } else if (previo == nullptr) {
            setTam(getTam() - 1);
            setFrente(borrar->getNext());
            if (borrar == getFinal()) {
                setFinal(nullptr);
            } else if (getFrente() != nullptr){
                renumerarPosicionNodos(getFrente(), 1);
            }
            delete borrar;
            delete previo;
            return true;
        } else {
            previo->setNext(borrar->getNext());
            if (borrar != getFinal()) {
                renumerarPosicionNodos(previo, previo->getPos());
            } else {
                setFinal(previo);
            }
            setTam(getTam() - 1);
            delete borrar;
            return true;
        }
    }
    return false;
}

bool ListaJugadorOrdenada::eliminarPorPosicion(int pPosicion) {
    if (getFrente() == nullptr) { // No se han agregado elementos al nodo
        return false;
    } else { // hay elementos en el nodo
        NodoJugador *borrar = getFrente();
        NodoJugador *previo = nullptr;
        do {
            if (borrar->getPos() == pPosicion){
                break;
            }
            previo = borrar;
            borrar = borrar->getNext();
        } while (borrar != nullptr);
        if (borrar == nullptr){ // el valor no existe en la lista
            return false;
        } else if (previo == nullptr){ // el elemento a eliminar es el primero
            setTam(getTam() - 1);
            setFrente(borrar->getNext());
            if (borrar == getFinal()) { // solo hay un nodo
                setFinal(nullptr);
            } else if (getFrente() != nullptr) { // hay varios nodos
                renumerarPosicionNodos(getFrente(), 1);
            }
            delete borrar;
            delete previo;
            return true;
        } else { // el elemento a eliminar no es el primero
            previo->setNext(borrar->getNext());
            if (borrar != getFinal()) { // el nodo a borrar no es el tail
                renumerarPosicionNodos(previo, previo->getPos());
            } else { // el nodo a eliminar es tail
                setFinal(previo);
            }
            setTam(getTam() - 1);
            delete borrar;
            return true;
        }
    }
}

string ListaJugadorOrdenada::mostrarInfoJugador(int num) {
    string info = "Posición: " + to_string(num) + " ";
    if (getFrente() == nullptr) { // No se han agregado elementos al nodo
        return "";
    } else { // ya hay elementos en el nodo
        NodoJugador *aux = getFrente();
        do {
            if (aux->getPos() == num) {
                info += aux->getJugador().getNombre() +
                        " puntos: " + to_string(aux->getPuntaje());
                break;
            }
            aux = aux->getNext();
        } while (aux != nullptr);
    }
    return info;
}
