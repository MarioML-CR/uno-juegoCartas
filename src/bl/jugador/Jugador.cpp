//
// Created by Mario Martinez on 09/10/20.
//

#include "Jugador.h"
Jugador::Jugador() : nombre(""), id(0) {}

Jugador::Jugador(const string& nombre, int id) : nombre(nombre), id(id) {}

Jugador::~Jugador() {}

int Jugador::getId() const {
    return id;
}

void Jugador::setId(int id) {
    Jugador::id = id;
}

const string& Jugador::getNombre() const {
    return nombre;
}

void Jugador::setNombre(const string& nombre) {
    Jugador::nombre = nombre;
}

string Jugador::toString() const {
    return "Jugador: " + this->getNombre() + " id: " + to_string(this->getId()) + "\n";
}
