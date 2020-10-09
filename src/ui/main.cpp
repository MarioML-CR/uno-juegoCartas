#include <iostream>
#include <string>
#include <stdlib.h>
#include "../ui/utilitario/Validar.h"
#include "../tl/Gestor.h"
using namespace std;
void mostrarCartaTope();
void iniciarJuego();
void mostrarCartasJugador();
void inicializarJugadorPrimerJugador();
void ingresarCantidad();
void datosPersonales(int);
void menuInicioJuego();
void procesarMenuOpcion(int);
void inicializarJuego();
void mostrarRecord();
string *datos;
int numJugadores;
int cartaEscogida;
Gestor gestor;
Validar validar;

int main() {
    menuInicioJuego();
    string valor = " ";
    cin >> valor;
    procesarMenuOpcion(validar.ingresarInt(valor));
    return 0;
}
void menuInicioJuego() {
    cout << "\nMenu" << endl;
    cout << "1.Iniciar Juego" << endl;
    cout << "2.Mostrar Record Jugadores"<<endl;
    cout << "3.Salir" << endl;
    cout << "Elija una opcion" << endl;
}
void procesarMenuOpcion(int op) {
    switch (op)
    {
        case 1:
            inicializarJuego();
            break;
        case 2:
            mostrarRecord();
            break;
        case 3:
            cout << "Saliendo....." << endl;
            break;
        default:
            cout << "Error Capa 8" << endl;
            main();
            break;
    }
}

void inicializarJuego() {
    ingresarCantidad();
    cout << gestor.barajarMazo();
    cout << gestor.repartirCartas(numJugadores);
    inicializarJugadorPrimerJugador();
    iniciarJuego();
    main();
}

void iniciarJuego() {
    cout << "\n========================================================";
    mostrarCartaTope();
    mostrarCartasJugador();
    mostrarRecord();
    iniciarJuego();
}
void mostrarCartaTope() {
    cout<<"\nCarta actual: "+gestor.mostrarCartaActual()<<endl;
}
void mostrarCartasJugador() {
    cout << gestor.mostrarCartasJugadorActual();
    if (gestor.mostrarCartasJugadorActual()=="No hay cartas") {

    }
    else {
        if (!gestor.validarListaJugador()) {
            cout << "Escoja una carta:" << endl;
            cin >> cartaEscogida;
            cout << "\n" + gestor.validarCarta(cartaEscogida) << endl;
        }
    }
}
void inicializarJugadorPrimerJugador() {
    gestor.inicializarJugadorActual();
}
void ingresarCantidad() {
    cout << "Numero de jugadores (minimo 2, maximo 4)\n";
    cin >> numJugadores;
    for (int i = 0; i < numJugadores; ++i) {
        datosPersonales(i);
    }
}
void datosPersonales(int indice) {
    string nombre;
    if (indice <= 3) {
        cout << "Ingrese el Nombre del jugador numero " + to_string(indice + 1) + "\n";
        getline(cin >> ws, nombre);
        gestor.cargarJugador(nombre, indice);
    }
    else {
        cout << "Ingrese el Nombre del jugador que estara el cola " + to_string(indice + 1) + "\n";
        getline(cin >> ws, nombre);
        cout << gestor.cargarJugadorCola(nombre, indice)<<endl;

    }
}
void mostrarRecord(){
    cout << gestor.mostrarPuntajeJuegadores(numJugadores);
}
