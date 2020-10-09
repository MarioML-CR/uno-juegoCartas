//
// Created by Mario Martinez on 09/10/20.
//

#include "ListaCarta.h"

ListaCarta::ListaCarta() {
    setFrente(nullptr);
    setFinal(nullptr);
    setTam(0);
}

ListaCarta::~ListaCarta() {

}

NodoCarta *ListaCarta::getFrente() const {
    return frente;
}

void ListaCarta::setFrente(NodoCarta *frente) {
    ListaCarta::frente = frente;
}

NodoCarta *ListaCarta::getFinal() const {
    return final;
}

void ListaCarta::setFinal(NodoCarta *final) {
    ListaCarta::final = final;
}

int ListaCarta::getTam() const {
    return tam;
}

void ListaCarta::setTam(int tam) {
    ListaCarta::tam = tam;
}
/**
 * Método:              mostrarLista
 * Descripción:         Método que permite recorrer la lista guardando los valores de su información
 * para retornarlos como string
 * @return              variable de tipo string que contiene el valor (informción) de cada nodo
 */
string ListaCarta::mostrarLista() {
    string msg;

    if (getFrente() == nullptr) {
        msg = "No hay cartas\n";
    } else {
        NodoCarta *aux = getFrente();
        msg += "Sus cartas son: \n";
        do {
            for (int i = 0; i < getTam();i++) {
                msg +=to_string(i+1)+"-" + aux->getCarta().toString() + "\n";
                aux = aux->getNext();
            }
            if (aux == nullptr) { // para lista regular
                break;
            } else if (aux == getFrente()){ // para lista circular
                break;
            }
        } while (true);
    }
    return msg;
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
string ListaCarta::mostrarListaRecursiva() {
    return recorrerListaRecursiva(getFrente());
}
/**
 * Método:          eliminarLista
 * Descripción:     método que permite eliminar una lista
 */
void ListaCarta::eliminarLista() {
    NodoCarta *borrar = getFrente();
    if (getFinal()->getNext() == getFrente() && getFrente()->getPrev() == nullptr) { // lista circular simple
        getFinal()->setNext(nullptr);;
    }
    if (getFrente()->getPrev() == getFinal() && getFinal()->getNext() == getFrente()) { // lista circular doble
        getFrente()->setPrev(nullptr);
        getFinal()->setNext(nullptr);
    }
    while (borrar != nullptr) {
        setFrente(getFrente()->getNext());
        delete borrar;
        borrar = getFrente();
    }
    setFrente(nullptr);
    setTam(0);
}

void ListaCarta::insertarAlInicio(Carta & c) {
    if (getFrente() == nullptr) {
        setFrente(new NodoCarta(c)); // se asigna al atributo head un nuevo nodo
        setFinal(getFrente()); // se asigna al atributo tail el valor del atributo head
    } else {
        NodoCarta *nuevo = new NodoCarta(c); // se crea un nuevo nodo, que está aislado
        nuevo->setNext(getFrente()); // se pone al nuevo nodo a apuntar al nodo que aún es head
        setFrente(nuevo); // se reasigna el atributo head una nuevo posición de memoria, y que correspon al nuevo nodo
    }
    setTam(getTam() + 1); // se incrementa el tamaño de la lista1, tomando el tamaño anterior + 1
    renumerarPosicionNodos(getFrente(), 1); // invocando este método permite acoplarse con los 3 tipos de inserción
}



void ListaCarta::insertarAlFinal(Carta & c) {
    if (getFrente() == nullptr) {
        setFrente(new NodoCarta(c)); // se asigna al atributo head un nuevo nodo
        setFinal(getFrente());        // se asigna al atributo tail el valor del atributo head
    } else {
        NodoCarta *nuevo = new NodoCarta(c); // se crea un nuevo nodo, que está aislado
        getFinal()->setNext(nuevo); // se pone al nodo anterior, que simpre será tail a apuntar al nuevo nodo
        setFinal(nuevo); // se reasigna el atributo tail con el nuevo nodo
    }
    setTam(getTam() + 1); // se incrementa el tamaño de la lista1, tomando el tamaño anterior + 1
    getFinal()->setPos(getTam()); // invocando este método permite acoplarse con los 3 tipos de inserción
}

Carta ListaCarta::eliminarPorPosicion(int pPosicion) {
    Carta* salida=new Carta();
    NodoCarta* borrar = getFrente();
    NodoCarta* previo = nullptr;
    if (getFrente() == nullptr) { // No se han agregado elementos al nodo

    } else { // hay elementos en el nodo


        while (borrar != nullptr & borrar->getPos() != pPosicion) {
            previo = borrar;
            borrar = borrar->getNext();
        }
        if (borrar == nullptr){ // el valor no existe en la lista
        } else if (previo == nullptr){ // el elemento a eliminar es el primero
            setTam(getTam() - 1);
            setFrente(borrar->getNext());

            if (borrar == getFinal()) { // solo hay un nodo
                setFinal(nullptr);
            } else if (getFrente() != nullptr) { // hay varios nodos
                renumerarPosicionNodos(getFrente(), 1);
            }
            *salida = borrar->getCarta();
            delete borrar;
            delete previo;
        } else { // el elemento a eliminar no es el primero
            previo->setNext(borrar->getNext());
            if (borrar != getFinal()) { // el nodo a borrar no es el tail
                renumerarPosicionNodos(previo, previo->getPos());
            } else { // el nodo a eliminar es tail
                setFinal(previo);
            }
            setTam(getTam() - 1);
            *salida = borrar->getCarta();
            delete borrar;
        }
    }
    return *salida;
}

void ListaCarta::renumerarPosicionNodos(NodoCarta *nodo, int posicion) {
    NodoCarta *aux2 = nodo;
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
string ListaCarta::recorrerListaRecursiva(NodoCarta *nodo) {
    string resultado;
    if (getFrente() == nullptr) {
        return "La lista está vacía\n";
    } else if(nodo == getFinal()) {
        return nodo->getCarta().toString() + "\n"; // se agrega para que en el último ciclo incluya el dato de tail
    } else {
        resultado += recorrerListaRecursiva(nodo->getNext()) + nodo->getCarta().toString() + "\n";
    }
    return resultado;
}
NodoCarta* ListaCarta::cartaEscogida(int carta) {
    NodoCarta* salida;
    NodoCarta* aux = getFrente();
    while (aux->getPos() != carta) {
        aux->getNext();
        aux = aux->getNext();
    }
    if (aux->getPos() == carta) {
        salida = aux;
    }
    return salida;
}


int ListaCarta::obtenerPuntaje() {
    int puntaje = 0;
    if (getFrente() == nullptr) {
        puntaje = 0;
    } else {
        NodoCarta *aux = getFrente();
        do {
            puntaje +=  aux->getCarta().getPuntos();
            aux = aux->getNext();
        } while (aux != nullptr);
    }
    return puntaje;
}
