//
// Created by Mario Martinez on 09/10/20.
//

#include "PilaCarta.h"
PilaCarta::PilaCarta() {
    setTope(nullptr);
    setTam(0);
}

PilaCarta::~PilaCarta() {

}

NodoCarta *PilaCarta::getTope() const {
    return tope;
}

void PilaCarta::setTope(NodoCarta *tope) {
    PilaCarta::tope = tope;
}

int PilaCarta::getTam() const {
    return tam;
}

void PilaCarta::setTam(int tam) {
    PilaCarta::tam = tam;
}
bool PilaCarta::esVaciaPila() {
    if (getTam() == 0){
        return true;
    } else {
        return false;
    }
}
/**
 * Método:      push
 * Descripción  método que permite agregar elementos a la pila
 */
void PilaCarta::push(Carta c) {
    if (getTam() == 0){
        setTope(new NodoCarta(c));
    } else {
        NodoCarta *nuevo = new NodoCarta(c);
        nuevo->setNext(getTope());
        setTope(nuevo);
    }
    setTam(getTam() + 1);
    updatePosiciones();
}
Carta PilaCarta::pop() {
    Carta *c = new Carta();
    if (getTam() == 0){
        c = NULL;
    } else {
        NodoCarta *eliminar = getTope();
        *c = getTope()->getCarta();
        setTope(getTope()->getNext());
        delete eliminar;
        updatePosiciones();
        setTam(getTam() - 1);
    }
    return *c;
}
/**
 * Método:          updatePosiciones
 * Descripción      método que permite numerar las posiciones de la lista.
 */
void PilaCarta::updatePosiciones() {
    NodoCarta *aux2 = getTope();
    int i = 1;
    do { // ajustar numeración
        aux2->setPos(i);
        aux2 = aux2->getNext();
        i++;
    } while (aux2 != nullptr);
}

int PilaCarta::longitudPila() {
    return getTam();
}

Carta PilaCarta::topePila() {
    if (getTam() == 0) {
        return Carta();
    } else {
        return getTope()->getCarta();
    }
}

string PilaCarta::destruirPila() {
    if (getTam() == 0){
        return "La pila está vacía, no hay elementos que eliminar\n";
    } else {
        NodoCarta *destruir = getTope();
        while (destruir != nullptr){
            setTope(getTope()->getNext());
            delete destruir;
            destruir = getTope();
        }
        setTam(0);
        return "La pila se ha destruido satisfactoriamente\n";
    }
}