//
// Created by Mario Martinez on 09/10/20.
//

#ifndef UNO_JUEGOCARTAS_REGLASJUEGO_H
#define UNO_JUEGOCARTAS_REGLASJUEGO_H

#include "../carta/ListaCarta.h"
#include "../carta/PilaCarta.h"
class ReglasJuego {
public:
    ReglasJuego();
    int ordenMasoRandom[56];
    int validarEfecto(Carta cartaTirada);


    bool cartaValidaparaJugada(Carta anterior, Carta nueva);

    int validarPuntosTotalesJugador(ListaCarta Mano);

    bool victoriaPorNumCartas(ListaCarta Mano);

    void agregarCartasAlMazo();

    int numRandomRango(int nMin, int nMax);
};

#endif //UNO_JUEGOCARTAS_REGLASJUEGO_H
