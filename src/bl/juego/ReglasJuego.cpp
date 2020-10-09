//
// Created by Mario Martinez on 09/10/20.
//

#include "ReglasJuego.h"

ReglasJuego::ReglasJuego() {}
int ReglasJuego::validarEfecto(Carta cartaTirada) {
    // Agregar Validaciones con la logica del juego.
    int opcion = 0;
    if (cartaTirada.getDescripcion() == "comados" ){
        opcion = 1;
    } else if (cartaTirada.getDescripcion() == "bloqueo" ){
        opcion = 2;
    }else if (cartaTirada.getDescripcion() == "cambioturno" ){
        opcion = 3;
    }else if (cartaTirada.getDescripcion() == "cambioColor" ){
        opcion = 4;
    }else if (cartaTirada.getDescripcion() == "comacuatro" ){
        opcion = 5;
    }
    return opcion;
}


bool ReglasJuego::cartaValidaparaJugada(Carta anterior, Carta nueva) {
    bool jugadaValida;
    if ( anterior.getDescripcion() == nueva.getDescripcion()  || anterior.getColor() == nueva.getColor() || anterior.getColor() == "negra"||nueva.getColor()=="negra"){
        jugadaValida = true;
    } else {
        jugadaValida = false;
    }
    return jugadaValida;
}

int ReglasJuego::validarPuntosTotalesJugador(ListaCarta manoJugador) { // pasar a listaCarta se busca sumar pasar a ListaCarta
    int sumatoria;
    for (int i = 0; i < manoJugador.getTam(); i++){
        Carta cartaActual =  manoJugador.getFrente()->getCarta();
        sumatoria = sumatoria + cartaActual.getPuntos();
    }
    return sumatoria;
}

bool ReglasJuego::victoriaPorNumCartas(ListaCarta mano) {
    bool ganador = false;
    if (mano.getTam() == 1){
        ganador = true;
    }else {
        ganador = false;
    }
    return ganador;
}

void ReglasJuego::agregarCartasAlMazo() {
    Carta masoOrdenado[56];
    for (int i = 0; i < 9; i++){
        string iString= to_string(i);
        Carta cartaActual;
        cartaActual.setColor("Red");
        cartaActual.setDescripcion(iString);
        cartaActual.setPuntos(i+1);
        masoOrdenado[i] = cartaActual;
    }
    for (int i = 0; i < 9; i++){
        string iString= to_string(i);
        Carta cartaActual;
        cartaActual.setColor("Green");
        cartaActual.setDescripcion(iString);
        cartaActual.setPuntos(i+1);
        masoOrdenado[i+10] = cartaActual;
    }
    for (int i = 0; i < 9; i++){
        string iString= to_string(i);
        Carta cartaActual;
        cartaActual.setColor("Blue");
        cartaActual.setDescripcion(iString);
        cartaActual.setPuntos(i+1);
        masoOrdenado[i+20] = cartaActual;
    }
    for (int i = 0; i < 9; i++){
        string iString= to_string(i);
        Carta cartaActual;
        cartaActual.setColor("Yellow");
        cartaActual.setDescripcion(iString);
        cartaActual.setPuntos(i+1);
        masoOrdenado[i+30] = cartaActual;
    }
    // Cartas especiales
    for (int i = 0; i < 3; i++){
        string iString= to_string(i);
        Carta cartaActual;
        if ( i == 0){
            cartaActual.setColor("Red");
        } else if ( i == 1){
            cartaActual.setColor("Green");
        } else if ( i == 2){
            cartaActual.setColor("Blue");
        }else if ( i == 3){
            cartaActual.setColor("Yellow");
        }
        cartaActual.setDescripcion("Block");
        cartaActual.setPuntos(8);
        masoOrdenado[i+40] = cartaActual;
    }
    for (int i = 0; i < 3; i++){
        string iString= to_string(i);
        Carta cartaActual;
        if ( i == 0){
            cartaActual.setColor("Red");
        } else if ( i == 1){
            cartaActual.setColor("Green");
        } else if ( i == 2){
            cartaActual.setColor("Blue");
        }else if ( i == 3){
            cartaActual.setColor("Yellow");
        }
        cartaActual.setDescripcion("+2");
        cartaActual.setPuntos(12);
        masoOrdenado[i+44] = cartaActual;
    }
    for (int i = 0; i < 3; i++){
        string iString= to_string(i);
        Carta cartaActual;
        if ( i == 0){
            cartaActual.setColor("Red");
        } else if ( i == 1){
            cartaActual.setColor("Green");
        } else if ( i == 2){
            cartaActual.setColor("Blue");
        }else if ( i == 3){
            cartaActual.setColor("Yellow");
        }
        cartaActual.setDescripcion("Reverse");
        cartaActual.setPuntos(8);
        masoOrdenado[i+48] = cartaActual;
    }
    for (int i = 0; i < 3; i++){
        string iString= to_string(i);
        Carta cartaActual;
        if ( i == 0){
            cartaActual.setDescripcion("ChangeColor");
            cartaActual.setPuntos(15);
        } else if ( i == 1){
            cartaActual.setDescripcion("ChangeColor");
            cartaActual.setPuntos(15);
        } else if ( i >= 2){
            cartaActual.setDescripcion("+4");
            cartaActual.setPuntos(20);
        }else if ( i == 3){
            cartaActual.setDescripcion("+4");
            cartaActual.setPuntos(20);
        }
        cartaActual.setColor("Black");
        masoOrdenado[i+52] = cartaActual;
    }
    // Reordenar Mazo
    int ordenMasoRandom[56];
    for (int i = 0; i < 56; i++){
        int numSelec = numRandomRango(0,56);
        for (int j = 0; j < 56 ; ++j) {
            if( ordenMasoRandom[j] != numSelec ){
                ordenMasoRandom[i] = numSelec;
            } else {
                // Falta depurar está funcion para que vaya quitando más cartas.
                numSelec = numRandomRango(0,56);
                ordenMasoRandom[i] = numSelec;
            }
        }
    }
    for (int a = 0; a < 56; a++) {
        ordenMasoRandom[a] = ordenMasoRandom[a];
    }
}

int ReglasJuego::numRandomRango(int nMin, int nMax) {
    return nMin + (int)((double)rand() / (RAND_MAX+1) * (nMax-nMin+1));
}
