//
// Created by Mario Martinez on 09/10/20.
//

#ifndef UNO_JUEGOCARTAS_LISTAJUGADOR_H
#define UNO_JUEGOCARTAS_LISTAJUGADOR_H

#include "NodoJugador.h"
#include "Jugador.h"

class ListaJugador {
public:
    ListaJugador();

    virtual ~ListaJugador();

    NodoJugador* getFrente() const;

    void setFrente(NodoJugador* frente);

    NodoJugador* getFinal() const;

    void setFinal(NodoJugador* final);

    int getTam() const;

    void setTam(int tam);

    bool insertarAlInicioDobleEnlaceCircular(Jugador&);

    bool insertarAlFinalDobleEnlaceCircular(Jugador&);

    void eliminarPorPosicionDobleEnlaceCircular(int);

    NodoJugador* getObtenerJugador(string nombre);

    string obtenerNombreJugador(int);

    int obtenerIdJugador(int);

    string getJugadorUno();

    string getSiguiente(string);

    string getAnterior(string);
private:
    NodoJugador* frente;
    NodoJugador* final;
    int tam;
    void renumerarPosicionNodos(NodoJugador* nodo, int);
};

#endif //UNO_JUEGOCARTAS_LISTAJUGADOR_H
