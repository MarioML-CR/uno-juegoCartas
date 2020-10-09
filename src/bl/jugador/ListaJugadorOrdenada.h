//
// Created by Mario Martinez on 09/10/20.
//

#ifndef UNO_JUEGOCARTAS_LISTAJUGADORORDENADA_H
#define UNO_JUEGOCARTAS_LISTAJUGADORORDENADA_H


#include "NodoJugador.h"

class ListaJugadorOrdenada {
public:
    ListaJugadorOrdenada();

    virtual ~ListaJugadorOrdenada();

    NodoJugador *getFrente() const;

    void setFrente(NodoJugador *frente);

    NodoJugador *getFinal() const;

    void setFinal(NodoJugador *final);

    int getTam() const;

    void setTam(int tam);

    string mostrarListaRecursiva();
    string mostrarInfoJugador(int);
    int buscarPosicion(string);
    void eliminarLista();
    bool insertarAlInicio(Jugador &, int); // al inicio
    bool insertarOrdenado(Jugador &, int);
    bool insertarAlFinal(Jugador &, int); // al final
    bool eliminarPorContenido(string);
    bool eliminarPorPosicion(int);
private:
    NodoJugador* frente;
    NodoJugador* final;
    int tam;
    void posicionNodo(NodoJugador * nodo);
    void renumerarPosicionNodos(NodoJugador * nodo, int);
    string recorrerListaRecursiva(NodoJugador * nodo);
};


#endif //UNO_JUEGOCARTAS_LISTAJUGADORORDENADA_H
