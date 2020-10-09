//
// Created by Mario Martinez on 09/10/20.
//

#ifndef UNO_JUEGOCARTAS_GESTOR_H
#define UNO_JUEGOCARTAS_GESTOR_H


#include "../bl/jugador/ColaJugador.h"
#include "../bl/carta/PilaCarta.h"
#include "../bl/carta/ListaCarta.h"
#include "../bl/jugador/Jugador.h"
#include "../bl/jugador/ListaJugador.h"
#include "../bl/juego/ReglasJuego.h"
#include "../bl/jugador/ListaJugadorOrdenada.h"
#include <fstream>
#include <vector>
#include <ctime>
#include <iostream>

class Gestor {
public:
    Gestor();
    /*
     * Getter and setter generales
     */
    ColaJugador *getCola() const;
    void setCola(ColaJugador *);
    PilaCarta* getPila1() const;
    void setPila1(PilaCarta* pila1);
    PilaCarta* getPila2() const;
    void setPila2(PilaCarta* pila2);
    ListaCarta* getLista1() const;
    void setLista1(ListaCarta *lista1);
    ListaCarta *getLista2() const;
    void setLista2(ListaCarta *lista2);
    ListaCarta *getLista3() const;
    void setLista3(ListaCarta *lista3);
    ListaCarta *getLista4() const;
    void setLista4(ListaCarta *lista4);
    string mostrarCartasJugadorActual();
    string validarsiguienteJugada();
    bool validarListaJugador();
    Carta  eliminarCartaEscogida(int carta);
    void actualizarPuntaje(int, int); // obtener el puntaje de cada jugador
    string mostrarPuntajeJugador(int);
    string mostrarPuntajeJuegadores(int);

    /*
    * métodos de jugadores
    */
    void cargarJugadores(string, int);
    const string &getJugadorActual() const;
    void setJugadorActual(const string &jugadorActual);
    void cargarJugador(string nombre, int indice);
    void inicializarJugadorActual();
    void listarJugador(Jugador &);
    void cargarJugadorSiguiente();
    void  cargarJugadorAnterior();
    string  mostrarJugadorActual();
    string turnosSegunCarta();

    /*
     * métodos de pila
     */
    bool esVaciaPila(int);
    void push(Carta, int); // insertar elemento en la pila
    Carta pop(int);
    int longitudPila(int); // obtener el tamaño de la pila
    Carta topePila(int);
    string destruirPila(int);
    string barajarMazo(); //Obtiene las cartas registradas en el txt y las escribe en arrCartasTxt
    string repartirCartas(int numJugadores);
    string validarCarta(int);
    string mostrarCartaActual();
    string comerCarta();
    ListaJugador *getListaJugador() const;
    void setListaJugador(ListaJugador *listaJugador);
    ListaJugadorOrdenada *getListaJugadorConScore() const;
    void setListaJugadorConScore(ListaJugadorOrdenada *listaJugadorConScore);
    string cargarJugadorCola(string nombre, int indice);
private:
    ColaJugador *cola;
    PilaCarta* mazoBarajado;
    PilaCarta* pilaBasura;
    ListaCarta * lista1;
    ListaCarta * lista2;
    ListaCarta * lista3;
    ListaCarta * lista4;
    ListaCarta* actual;
    ListaJugador * listaJugador;
    ListaJugadorOrdenada * listaJugadorConScore;
    bool reverso = false;
    //Atributos de lectura de archivo texto cartas
    const char* pathCartas = "../../../Cartas.txt";
    const char *pathCartasMac = "../Cartas.txt";
    ifstream my_input_file; // an input file stream object
    ofstream my_output_file; // an output file stream object
    Carta arrCartasTxt[54];
    string jugadorActual;

    //implementancion de reglas
    ReglasJuego* miReglas;
    int sistemaOperativo();
    int obtenerPuntaje(int);
};


#endif //UNO_JUEGOCARTAS_GESTOR_H
