//
// Created by Mario Martinez on 09/10/20.
//

#ifndef UNO_JUEGOCARTAS_NODOJUGADOR_H
#define UNO_JUEGOCARTAS_NODOJUGADOR_H
#include <iostream>
#include<sstream>
#include "../carta/Carta.h"
#include "Jugador.h"


using namespace std;

class NodoJugador {
public:
    NodoJugador();

    NodoJugador(const Jugador &jugador);

    int getPos() const;

    void setPos(int pos);

    int getPuntaje() const;

    void setPuntaje(int puntaje);

    const Jugador &getJugador() const;

    void setJugador(const Jugador &jugador);

    NodoJugador *getNext() const;

    void setNext(NodoJugador *next);

    NodoJugador *getPrev() const;

    void setPrev(NodoJugador *prev);

private:
    int pos;
    int puntaje;
    Jugador jugador;
    NodoJugador *next;
    NodoJugador * prev;
};

#endif //UNO_JUEGOCARTAS_NODOJUGADOR_H
