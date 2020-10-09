//
// Created by Mario Martinez on 09/10/20.
//

#include "ColaJugador.h"

ColaJugador::ColaJugador() {
    setTam(0);
    setFrente(nullptr);
    setFinal(nullptr);
}

ColaJugador::~ColaJugador() {

}

NodoJugador *ColaJugador::getFrente() const {
    return frente;
}

void ColaJugador::setFrente(NodoJugador *frente) {
    ColaJugador::frente = frente;
}

NodoJugador *ColaJugador::getFinal() const {
    return final;
}

void ColaJugador::setFinal(NodoJugador *final) {
    ColaJugador::final = final;
}

int ColaJugador::getTam() const {
    return tam;
}

void ColaJugador::setTam(int tam) {
    ColaJugador::tam = tam;
}

bool ColaJugador::esVaciaCola() {
    if (getTam() == 0){
        return true;
    } else {
        return false;
    }
}

int ColaJugador::getLongitudCola() {
    return getTam();
}

Jugador ColaJugador::ultimoElemCola() {
    if (getFinal() != nullptr) {
        return getFinal()->getJugador();
    } else {
        return Jugador();
    }
}

void ColaJugador::insertElemCola(Jugador & c) {
    if (getTam() == 0){
        setFrente(new NodoJugador(c));
        setFinal(getFrente());
    } else {
        NodoJugador *nuevo = new NodoJugador(c);
        getFinal()->setNext(nuevo);
        setFinal(nuevo);
    }
    setTam(getTam() + 1);
    getFinal()->setPos(getTam());
}

Jugador ColaJugador::atenderElemCola() {
    Jugador c;
    if (getTam() == 0) {
        c = Jugador();
    } else if (getTam() == 1) {
        NodoJugador *atender = getFrente();
        c = getFrente()->getJugador();
        setFrente(getFrente()->getNext());
        setFinal(getFrente());
        delete atender;
        setTam(getTam() - 1);
    } else {
        NodoJugador *atender = getFrente();
        setFrente(getFrente()->getNext());
        c = atender->getJugador();
        delete atender;
        updatePosicion();
        setTam(getTam() - 1);
    }
    return c;
}

string ColaJugador::destruirCola() {
    if (getTam() == 0) {
        return "La Cola está vacía, no hay elementos que eliminar\n";
    } else {
        NodoJugador *destruir = getFrente();
        while (destruir != nullptr) {
            setFrente(getFrente()->getNext());
            delete destruir;
            destruir = getFrente();
        }
        setFinal(nullptr);
        setTam(0);
        return "La Cola ha sido eliminada\n";
    }
}

void ColaJugador::updatePosicion() {
    NodoJugador *aux = getFrente();
    int i = 1;
    do {
        aux->setPos(i);
        aux = aux->getNext();
        i++;
    } while (aux != nullptr);
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
string ColaJugador::mostrarListaRecursiva() {
    return recorrerListaRecursiva(getFrente());
}
/**
 * Método:          recorrerListaRecursiva
 * Descripción:     Método que permite recorrer la lisa de forma recursiva
 * @param nodo      variable de tipo Nodo, que contiene la lista
 * @return          variable de tipo string que contiene la información de la lista
 */
string ColaJugador::recorrerListaRecursiva(NodoJugador *nodo) {
    string resultado;
    if (getFrente() == nullptr) {
        return "La lista está vacía\n";
    } else if(nodo == getFinal()) {
        return nodo->getJugador().toString() + "\n"; // se agrega para que en el último ciclo incluya el dato de tail
    } else {
        resultado += recorrerListaRecursiva(nodo->getNext()) + nodo->getJugador().toString() + "\n";
    }
    return resultado;
}