//
// Created by Mario Martinez on 09/10/20.
//

#include "Carta.h"

Carta::Carta() : descripcion(""), color(""), puntos(0){}

Carta::Carta(const string &descripcion, const string &color, int puntos) : descripcion(descripcion), color(color),
                                                                           puntos(puntos) {}

Carta::~Carta() {

}

const string &Carta::getDescripcion() const {
    return descripcion;
}

void Carta::setDescripcion(const string &descripcion) {
    Carta::descripcion = descripcion;
}

const string &Carta::getColor() const {
    return color;
}

void Carta::setColor(const string &color) {
    Carta::color = color;
}

int Carta::getPuntos() const {
    return puntos;
}

void Carta::setPuntos(int puntos) {
    Carta::puntos = puntos;
}

string Carta::toString() const {
    return " Carta numero: " + this->getDescripcion()+
           " color: " + this->getColor()+
           " puntos: " + to_string(this->getPuntos());
}
