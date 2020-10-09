//
// Created by Mario Martinez on 09/10/20.
//

#include "NodoJugador.h"

NodoJugador::NodoJugador() {
    setPos(0);
    setPuntaje(0);
    setJugador(jugador);
    setNext(nullptr);
    setPrev(nullptr);
}

NodoJugador::NodoJugador(const Jugador &jugador) : pos(0), puntaje(0), jugador(jugador), next(nullptr), prev(nullptr) {}

int NodoJugador::getPos() const {
    return pos;
}

void NodoJugador::setPos(int pos) {
    NodoJugador::pos = pos;
}

int NodoJugador::getPuntaje() const {
    return puntaje;
}

void NodoJugador::setPuntaje(int puntaje) {
    NodoJugador::puntaje = puntaje;
}

const Jugador &NodoJugador::getJugador() const {
    return jugador;
}

void NodoJugador::setJugador(const Jugador &jugador) {
    NodoJugador::jugador = jugador;
}

NodoJugador *NodoJugador::getNext() const {
    return next;
}

void NodoJugador::setNext(NodoJugador *next) {
    NodoJugador::next = next;
}

NodoJugador *NodoJugador::getPrev() const {
    return prev;
}

void NodoJugador::setPrev(NodoJugador *prev) {
    NodoJugador::prev = prev;
}
