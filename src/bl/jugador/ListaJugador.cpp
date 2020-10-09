#include "ListaJugador.h"
ListaJugador::ListaJugador() {
    setTam(0);
    setFrente(nullptr);
    setFinal(nullptr);
}

ListaJugador::~ListaJugador() {

}

NodoJugador* ListaJugador::getFrente() const {
    return frente;
}

void ListaJugador::setFrente(NodoJugador* frente) {
    ListaJugador::frente = frente;
}

NodoJugador* ListaJugador::getFinal() const {
    return final;
}

void ListaJugador::setFinal(NodoJugador* final) {
    ListaJugador::final = final;
}

int ListaJugador::getTam() const {
    return tam;
}

void ListaJugador::setTam(int tam) {
    ListaJugador::tam = tam;
}

bool ListaJugador::insertarAlInicioDobleEnlaceCircular(Jugador& jugador) {
    if (getFrente() == nullptr) {
        setFrente(new NodoJugador(jugador));
        setFinal(getFrente()); // se asigna al atributo tail el valor del atributo head
        getFinal()->setNext(getFrente());
        getFrente()->setPrev(getFinal());
    }
    else {
        NodoJugador* nuevo = new NodoJugador(jugador); // se crea un nuevo nodo, que está aislado
        nuevo->setNext(getFrente()); // se pone al nuevo nodo a apuntar al nodo que aún es head
        nuevo->setPrev(getFinal());
        getFinal()->setNext(nuevo);
        getFrente()->setPrev(nuevo);
        setFrente(nuevo); // se reasigna el atributo head una nuevo posición de memoria, y que correspon al nuevo nodo
    }
    setTam(getTam() + 1); // se incrementa el tamaño de la lista1, tomando el tamaño anterior + 1
    renumerarPosicionNodos(getFrente(), 1); // invocando este método permite acoplarse con los 3 tipos de inserción
    return true;
}

bool ListaJugador::insertarAlFinalDobleEnlaceCircular(Jugador& jugador) {
    if (getFrente() == nullptr) {
        setFrente(new NodoJugador(jugador));
        setFinal(getFrente()); // se asigna al atributo tail el valor del atributo head
        getFinal()->setNext(getFrente());
        getFrente()->setPrev(getFinal());
    }
    else {
        NodoJugador* nuevo = new NodoJugador(jugador); // se crea un nuevo nodo, que está aislado
        nuevo->setNext(getFrente());
        nuevo->setPrev(getFinal());
        //        getTail()->setPrev(nuevo);
        getFinal()->setNext(nuevo); // se pone al nodo anterior, que simpre será tail a apuntar al nuevo nodo
        setFinal(nuevo); // se reasigna el atributo tail con el nuevo nodo
        getFrente()->setPrev(getFinal()); // se agrega el previo
//        setFinal(nuevo); // se reasigna el atributo tail con el nuevo nodo
    }
    setTam(getTam() + 1); // se incrementa el tamaño de la lista1, tomando el tamaño anterior + 1
    getFinal()->setPos(getTam());
    return true;

    //    (getFinal()); // invocando este método permite acoplarse con los 3 tipos de inserción
}

void ListaJugador::eliminarPorPosicionDobleEnlaceCircular(int posicion) {
    if (getFrente() == nullptr) { // No se han agregado elementos al nodo
    }
    else { // hay elementos en el nodo
        NodoJugador* borrar = getFrente();
        NodoJugador* previo = nullptr;
        while (borrar->getPos() != posicion) {
            previo = borrar;
            borrar = borrar->getNext();
            if (previo == getFinal()) { // lista circular
                break;
            }
        }
        if (previo == getFinal()) { // el valor no existe en la lista
        }
        else if (previo == nullptr) { // el elemento a eliminar es el primero
            if (getFinal()->getNext() == getFrente()) { // para lista circular
                getFinal()->setNext(getFrente()->getNext());
                getFrente()->getNext()->setPrev(getFinal());
            }
            setTam(getTam() - 1);
            setFrente(borrar->getNext());
            if (borrar == getFinal()) { // solo hay un nodo
                setFinal(nullptr);
            }
            else if (getFrente() != nullptr) { // hay varios nodos
                renumerarPosicionNodos(getFrente(), 1);
            }
            delete borrar;
            delete previo;
        }
        else { // el elemento a eliminar no es el primero
            previo->setNext(borrar->getNext());
            previo->getNext()->setPrev(previo);
            if (borrar != getFinal()) { // el nodo a borrar no es el tail
                renumerarPosicionNodos(previo, previo->getPos());
            }
            else { // el nodo a eliminar es tail
                setFinal(previo);
            }
            setTam(getTam() - 1);
            delete borrar;
        }
    }
}
/**
 * Método:          renumerarPosicionNodos
 * Descripción:     método que permite renumerar el valor de la posición de los nodos a poartir del valor
 * de posición recibido por parámetro.
 * @param nodo      representa el nodo a partir del cual se hará la renumeración de las posiciones.
 * @param posicion  valor de la posición del último nodo conocido, y que se debe modificar.
 */
void ListaJugador::renumerarPosicionNodos(NodoJugador* nodo, int posicion) {
    NodoJugador* aux2 = nodo;
    int i = posicion;
    do { // ajustar numeración
        aux2->setPos(i);
        aux2 = aux2->getNext();
        i++;
        if (aux2 == nullptr) { // aplica a la lista convencional
            break;
        }
        if (aux2 == getFrente()) { // aplica a la lista circular
            break;
        }
    } while (true);
}
string ListaJugador::getJugadorUno() {
    if (getFrente() == nullptr) { // No se han agregado elementos al nodo
        return "No hay jugadores aún\n";
    }
    else { // ya hay elementos en el nodo
        return getFrente()->getJugador().getNombre();
    }
}
string ListaJugador::getSiguiente(string nombre) {
    if (getFrente() == nullptr) { // No se han agregado elementos al nodo
        return "";
    }
    else { // ya hay elementos en el nodo
        NodoJugador* aux = getFrente();
        do {
            if (aux->getJugador().getNombre() == nombre) {
                return aux->getNext()->getJugador().getNombre();
            }
            aux = aux->getNext();
        } while (aux != nullptr);
    }
}
NodoJugador* ListaJugador::getObtenerJugador(string nombre) {
    NodoJugador* salida;
    NodoJugador* aux = getFrente();
    do {
        if (aux->getJugador().getNombre() == nombre) {
            salida= aux;
            break;
        }
        aux = aux->getNext();
    } while (aux->getJugador().getNombre() == nombre);

    return salida;
}
string ListaJugador::obtenerNombreJugador(int posicion) {
    string datos = "";
    if (getFrente() == nullptr){
        return datos;
    } else {
        NodoJugador* aux = getFrente();
        do {
            if (aux->getPos() == posicion) {
                return aux->getJugador().getNombre();
            }
            aux = aux->getNext();
        } while (aux != nullptr);
    }
}
int ListaJugador::obtenerIdJugador(int posicion) {
    int id = 0;
    if (getFrente() == nullptr){
        return id;
    } else {
        NodoJugador* aux = getFrente();
        do {
            if (aux->getPos() == posicion) {
                return aux->getJugador().getId();
            }
            aux = aux->getNext();
        } while (aux != nullptr);
    }
}
string ListaJugador::getAnterior(string nombre) {
    if (getFrente() == nullptr) { // No se han agregado elementos al nodo
        return "";
    }
    else { // ya hay elementos en el nodo
        NodoJugador* aux = getFrente();
        do {
            if (aux->getJugador().getNombre() == nombre) {
                return aux->getPrev()->getJugador().getNombre();
            }
            aux = aux->getNext();
        } while (aux != nullptr);
    }
}
