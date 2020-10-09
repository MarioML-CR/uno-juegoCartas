//
// Created by Mario Martinez on 09/10/20.
//

#ifndef UNO_JUEGOCARTAS_LISTACARTA_H
#define UNO_JUEGOCARTAS_LISTACARTA_H
#include "NodoCarta.h"
#include "Carta.h"
#include <string>
using namespace std;

class ListaCarta {
public:
    ListaCarta();

    virtual ~ListaCarta();

    NodoCarta *getFrente() const;

    void setFrente(NodoCarta *frente);

    NodoCarta *getFinal() const;

    void setFinal(NodoCarta *final);

    int getTam() const;

    void setTam(int tam);

    string mostrarLista();

    string mostrarListaRecursiva();

    void eliminarLista();
    NodoCarta* cartaEscogida(int);
    /*
     * Lista Simple
     */
    void insertarAlInicio(Carta &); // al inicio

    void insertarAlFinal(Carta &); // al inicio

    Carta eliminarPorPosicion(int);

    int obtenerPuntaje(); // obtener el puntaje de cada jugador


private:
    NodoCarta *frente;
    NodoCarta *final;
    int tam;
    void renumerarPosicionNodos(NodoCarta * nodo, int);

    string recorrerListaRecursiva(NodoCarta * nodo);
};


#endif //UNO_JUEGOCARTAS_LISTACARTA_H
