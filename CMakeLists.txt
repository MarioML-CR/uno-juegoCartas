cmake_minimum_required(VERSION 3.17)
project(uno_juegoCartas)

set(CMAKE_CXX_STANDARD 20)

add_executable(uno_juegoCartas src/ui/main.cpp src/ui/utilitario/Validar.cpp src/ui/utilitario/Validar.h src/tl/Gestor.cpp src/tl/Gestor.h src/bl/carta/Carta.cpp src/bl/carta/Carta.h src/bl/carta/ListaCarta.cpp src/bl/carta/ListaCarta.h src/bl/carta/NodoCarta.cpp src/bl/carta/NodoCarta.h src/bl/carta/PilaCarta.cpp src/bl/carta/PilaCarta.h src/bl/juego/ReglasJuego.cpp src/bl/juego/ReglasJuego.h src/bl/jugador/ColaJugador.cpp src/bl/jugador/ColaJugador.h src/bl/jugador/Jugador.cpp src/bl/jugador/Jugador.h src/bl/jugador/ListaJugador.cpp src/bl/jugador/ListaJugador.h src/bl/jugador/ListaJugadorOrdenada.cpp src/bl/jugador/ListaJugadorOrdenada.h src/bl/jugador/NodoJugador.cpp src/bl/jugador/NodoJugador.h)