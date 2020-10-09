//
// Created by Mario Martinez on 09/10/20.
//

#ifndef UNO_JUEGOCARTAS_COLAJUGADOR_H
#define UNO_JUEGOCARTAS_COLAJUGADOR_H
#include "NodoJugador.h"
#include "Jugador.h"
#include <iostream>
using namespace std;

class ColaJugador {
public:
    ColaJugador();

    virtual ~ColaJugador();

    NodoJugador *getFrente() const;

    void setFrente(NodoJugador *frente);

    NodoJugador *getFinal() const;

    void setFinal(NodoJugador *final);

    int getTam() const;

    void setTam(int tam);

    bool esVaciaCola();

    int getLongitudCola();

    Jugador ultimoElemCola();

    void insertElemCola(Jugador&); // insertar elementos

    Jugador atenderElemCola(); // atender elemento

    string destruirCola();

    void updatePosicion();

    string mostrarListaRecursiva();
private:
    NodoJugador *frente;
    NodoJugador *final;
    int tam;
    string recorrerListaRecursiva(NodoJugador * nodo);
};


#endif //UNO_JUEGOCARTAS_COLAJUGADOR_H
