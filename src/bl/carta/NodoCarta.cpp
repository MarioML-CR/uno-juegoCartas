//
// Created by Mario Martinez on 09/10/20.
//

#include "NodoCarta.h"
#include "NodoCarta.h"
NodoCarta::NodoCarta() {
    setPos(0);
    setCarta(carta);
    setNext(nullptr);
    setPrev(nullptr);
}

NodoCarta::NodoCarta(const Carta &carta) : carta(carta), pos(0), next(nullptr), prev(nullptr) {}

NodoCarta::~NodoCarta() {

}

int NodoCarta::getPos() const {
    return pos;
}

void NodoCarta::setPos(int pos) {
    NodoCarta::pos = pos;
}

const Carta &NodoCarta::getCarta() const {
    return carta;
}

void NodoCarta::setCarta(const Carta &carta) {
    NodoCarta::carta = carta;
}

NodoCarta *NodoCarta::getNext() const {
    return next;
}

void NodoCarta::setNext(NodoCarta *next) {
    NodoCarta::next = next;
}

NodoCarta *NodoCarta::getPrev() const {
    return prev;
}

void NodoCarta::setPrev(NodoCarta *prev) {
    NodoCarta::prev = prev;
}