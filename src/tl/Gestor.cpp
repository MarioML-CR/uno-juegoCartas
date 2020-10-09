//
// Created by Mario Martinez on 09/10/20.
//

#include "Gestor.h"
#include "../bl/jugador/ListaJugador.h"

Gestor::Gestor() {
    cola = new ColaJugador();
    pilaBasura = new PilaCarta();
    mazoBarajado = new PilaCarta();
    lista1 = new ListaCarta();
    lista2 = new ListaCarta();
    lista3 = new ListaCarta();
    lista4 = new ListaCarta();
    Jugador jugadores[4];
    listaJugador = new ListaJugador();
    listaJugadorConScore = new ListaJugadorOrdenada();
    jugadorActual = "";
    miReglas = new ReglasJuego();
}

ColaJugador *Gestor::getCola() const {
    return cola;
}

void Gestor::setCola(ColaJugador *cola) {
    Gestor::cola = cola;
}

PilaCarta *Gestor::getPila1() const {
    return mazoBarajado;
}

void Gestor::setPila1(PilaCarta * mazoBarajado) {
    Gestor::mazoBarajado = mazoBarajado;
}

PilaCarta *Gestor::getPila2() const {
    return pilaBasura;
}

void Gestor::setPila2(PilaCarta * pilaBasura) {
    Gestor::pilaBasura = pilaBasura;
}

ListaCarta *Gestor::getLista1() const {
    return lista1;
}

void Gestor::setLista1(ListaCarta *lista1) {
    Gestor::lista1 = lista1;
}

ListaCarta *Gestor::getLista2() const {
    return lista2;
}

void Gestor::setLista2(ListaCarta *lista2) {
    Gestor::lista2 = lista2;
}

ListaCarta *Gestor::getLista3() const {
    return lista3;
}

void Gestor::setLista3(ListaCarta *lista3) {
    Gestor::lista3 = lista3;
}

ListaCarta *Gestor::getLista4() const {
    return lista4;
}

void Gestor::setLista4(ListaCarta *lista4) {
    Gestor::lista4 = lista4;
}

ListaJugador *Gestor::getListaJugador() const {
    return listaJugador;
}

void Gestor::setListaJugador(ListaJugador *listaJugador) {
    Gestor::listaJugador = listaJugador;
}

ListaJugadorOrdenada *Gestor::getListaJugadorConScore() const {
    return listaJugadorConScore;
}

void Gestor::setListaJugadorConScore(ListaJugadorOrdenada *listaJugadorConScore) {
    Gestor::listaJugadorConScore = listaJugadorConScore;
}

/*Metodos Jugadores*/
void Gestor::cargarJugadores(string nombre, int indice) {


}

/**
 * Método:          getJugadorActual
 * Descripción:     método que permite obtener el jugador actual
 * @return          Devuelve el nombre del jugador actual
 */
const string &Gestor::getJugadorActual() const {
    return jugadorActual;
}
/**
 * Método:              setJugadorActual
 * Descripción:         método que permite definir el jugador actual
 * @param jugadorActual variable de tipo string que contiene el nombre
 * del jugador actual
 */
void Gestor::setJugadorActual(const string &jugadorActual) {
    Gestor::jugadorActual = jugadorActual;
}
/**
 * Método:              cargarJugador
 * Descripción:         método que permite crear un objeto de tipo Jugador
 * y enviarlo a listar.
 * @param nombre        variable de tipo string que representa el nombre del jugador
 * @param pId           variable de tipo int que representa el id del jugador
 */
void Gestor::cargarJugador(string nombre, int pId) {
    Jugador jugador = Jugador(nombre, pId + 1);
    listarJugador(jugador);
}
/**
 * Método:              inicializarJugadorActual
 * Descripción:         método que permite la inicialización del jugador actual
 * al inicio del juego
 */
void Gestor::inicializarJugadorActual() {
    setJugadorActual(listaJugador->getJugadorUno());
}
/**
 * Método:              listarJugador
 * Descripción:         método que permite enviar a la lista circular
 * doblemente enlazada el objeto de tipo jugador.
 * @param j             objeto de tipo Jugador
 */
void Gestor::listarJugador(Jugador & j) {
    listaJugador->insertarAlFinalDobleEnlaceCircular(j);
}
/**
 * Método:              mostrarJugadorActual
 * Descripción:         método que mostrar el jugador actual
 * @return              varibale de tipo string mostrando el nombre del jugador actual
 */
string Gestor::mostrarJugadorActual() {
    return getJugadorActual();
}
/**
 * Método:              cargarJugadorSiguiente
 * Descripción:         método que permite establecer el siguiente jugador como el actual
 */
void Gestor::cargarJugadorSiguiente() {
    jugadorActual = listaJugador->getSiguiente(getJugadorActual());
}
/**
 * Método:              cargarJugadorAnterior
 * Descripción:         método que permite establecer el anterior jugador como el actual
 */
void Gestor::cargarJugadorAnterior() {
    jugadorActual = listaJugador->getAnterior(getJugadorActual());

}

string Gestor::turnosSegunCarta() {
    string msg ="";
    if (!reverso) {
        switch (miReglas->validarEfecto(getPila2()->getTope()->getCarta())) {
            case 0:
                cargarJugadorSiguiente();
                msg = "Carta normal desechada, turno del siguiente jugador...";
                break;
            case 1://+2
                cargarJugadorSiguiente();
                comerCarta();
                comerCarta();
                msg = "El proximo jugador come 2 cartas";
                break;

            case 2://bloqueo
                msg = "Se bloqueo el turno del jugador siguiente";
                cargarJugadorSiguiente();
                cargarJugadorSiguiente();
                break;

            case 3://cambioturno
                reverso = false;
                cargarJugadorAnterior();
                msg = "Se invirtieron el orden de los turnos";
                break;

            case 4://cambioColor
                cargarJugadorSiguiente();
                msg = "Se cambiaron los colores";
                break;

            case 5://comacuatro
                cargarJugadorSiguiente();
                comerCarta();
                comerCarta();
                comerCarta();
                comerCarta();
                msg = "El proximo jugador come 4 cartas";
                break;
        }
    }
    else {
        switch (miReglas->validarEfecto(getPila2()->getTope()->getCarta())) {
            case 0:
                cargarJugadorAnterior();
                msg = "Carta normal desechada, turno del siguiente jugador...";
                break;
            case 1://+2
                cargarJugadorAnterior();
                comerCarta();
                comerCarta();
                msg = "El proximo jugador come 2 cartas";
                break;
            case 2://bloqueo
                cargarJugadorAnterior();
                cargarJugadorAnterior();
                msg = "Se bloqueo el turno del jugador siguiente";
                break;
            case 3://cambioturno
                reverso = true;
                cargarJugadorSiguiente();
                msg = "Se invirtieron el orden de los turnos";
                break;
            case 4://cambioColor
                cargarJugadorAnterior();
                msg = "Se cambiaron los colores";
                break;
            case 5://comacuatro
                cargarJugadorAnterior();
                comerCarta();
                comerCarta();
                comerCarta();
                comerCarta();
                msg = "El proximo jugador come 4 cartas";
                break;
        }
    }
    return msg;
}

/*
 * métodos de pila
 */
bool Gestor::esVaciaPila(int nPila) {
    switch (nPila) {
        case 1:
            return getPila1()->esVaciaPila();
        case 2:
            return getPila2()->esVaciaPila();
        default:
            return "Entrada inválida\n";
    }
}

void Gestor::push(Carta micarta, int nPila) {
    switch (nPila) {
        case 1:
            getPila1()->push(micarta);
            break;
        case 2:
            getPila2()->push(micarta);
            break;
        default:
            break;
    }
}

Carta Gestor::pop(int nPila) {
    switch (nPila) {
        case 1:
            return getPila1()->pop();
        case 2:
            return getPila2()->pop();
        default:
            return Carta();
    }
}

int Gestor::longitudPila(int nPila) {
    switch (nPila) {
        case 1:
            return getPila1()->longitudPila();
        case 2:
            return getPila2()->longitudPila();
        default:
            return 0;
    }
}

Carta Gestor::topePila(int nPila) {
    switch (nPila) {
        case 1:
            return getPila1()->topePila();
        case 2:
            return getPila2()->topePila();
        default:
            return Carta();
    }
}

string Gestor::destruirPila(int nPila) {
    switch (nPila) {
        case 1:
            return getPila1()->destruirPila();
        case 2:
            return getPila2()->destruirPila();
        default:
            return "";
    }
}

string Gestor::barajarMazo()
{
    Carta* tmpCarta = new Carta();
    //ListaCarta* tmpLista = new ListaCarta();
    vector<Carta> arrayCartas;
    string desc, color;
    int puntos, tamMazo;
    ifstream inFile;

    int SO = sistemaOperativo();
    if (SO == 1){
        inFile.open(pathCartas);
    } else {
        inFile.open(pathCartasMac);
    }

    if (inFile.fail())
    {
        return "Error leyendo archivo de Cartas";
    }
    else {
        while (inFile >> desc >> color >> puntos) {
            tmpCarta = new Carta(desc, color, puntos);
            arrayCartas.push_back(*tmpCarta);
        }
        //Se define el tamanho del mazo
        tamMazo = arrayCartas.size();

        //for (int i = 0; i < arrayCartas.size(); ++i) {
        //    cout << arrayCartas[i].toString() << endl;
        //}
        //Se van agregando carta al objeto Lista, con los valores del vector al azar
        do {
            srand(time(NULL)); //Si no llamamos el srand antes del rand() me genera siempre la misma secuencia de numeros random
            int randomNum = (rand() % arrayCartas.size()) + 0; // Genera numero random
            for (int i = 0; i < arrayCartas.size(); ++i) {
                if (i == randomNum) {
                    //tmpLista->insertarAlInicio(arrayCartas[i]); insert con lista
                    mazoBarajado->push(arrayCartas[i]);
                    arrayCartas.erase(arrayCartas.begin() + randomNum);
                }
            }
        } while (mazoBarajado->getTam()<tamMazo);

        return "\nMazo barajado al azar.\n";
    }
}
string Gestor::mostrarCartaActual() {
    if (getPila2()->getTam() == 0) {
        getPila2()->push(getPila1()->pop());
    }
    return getPila2()->getTope()->getCarta().toString();
}
string Gestor::comerCarta() {
    string msg ="Se ha comido una carta";
    NodoJugador* miJugador = listaJugador->getObtenerJugador(jugadorActual);

    Carta cartaActual;
    cartaActual = getPila1()->pop();

    switch (miJugador->getJugador().getId())
    {
        case 1:
            getLista1()->insertarAlInicio(cartaActual);
            break;
        case 2:
            getLista2()->insertarAlInicio(cartaActual);
            break;
        case 3:
            getLista3()->insertarAlInicio(cartaActual);
            break;
        case 4:
            getLista4()->insertarAlInicio(cartaActual);
            break;
        default:
            break;
    }
    return msg;
}
string Gestor::repartirCartas(int num) {


    Carta cartaActual;
    if (num>4) {
        num = 4;
    }
    if (num == 1) {
        for (int i = 0; i < 7; i++) {
            cartaActual = mazoBarajado->pop();
            getLista1()->insertarAlInicio(cartaActual);
        }
        actualizarPuntaje(1, 1);
        return "Cartas repartidas a los jugadores.\n";
    }
    else if (num == 2) {
        for (int i = 0; i < 7; i++) {
            cartaActual = mazoBarajado->pop();
            getLista1()->insertarAlInicio(cartaActual);
        }
        actualizarPuntaje(1, 1);
        for (int i = 0; i < 7; i++) {
            cartaActual = mazoBarajado->pop();
            getLista2()->insertarAlInicio(cartaActual);
        }
        actualizarPuntaje(2, 2);
        return "Cartas repartidas a los jugadores.\n";
    }
    else if (num == 3) {
        for (int i = 0; i < 7; i++) {
            cartaActual = mazoBarajado->pop();
            getLista1()->insertarAlInicio(cartaActual);
        }
        actualizarPuntaje(1, 1);
        for (int i = 0; i < 7; i++) {
            cartaActual = mazoBarajado->pop();
            getLista2()->insertarAlInicio(cartaActual);
        }
        actualizarPuntaje(2, 2);
        for (int i = 0; i < 7; i++) {
            cartaActual = mazoBarajado->pop();
            getLista3()->insertarAlInicio(cartaActual);
        }
        actualizarPuntaje(3, 3);
        return "Cartas repartidas a los jugadores.\n";
    }
    else if(num == 4) {
        for (int i = 0; i < 7; i++) {
            cartaActual = mazoBarajado->pop();
            getLista1()->insertarAlInicio(cartaActual);
        }
        actualizarPuntaje(1, 1);
        for (int i = 0; i < 7; i++) {
            cartaActual = mazoBarajado->pop();
            getLista2()->insertarAlInicio(cartaActual);
        }
        actualizarPuntaje(2, 2);
        for (int i = 0; i < 7; i++) {
            cartaActual = mazoBarajado->pop();
            getLista3()->insertarAlInicio(cartaActual);
        }
        actualizarPuntaje(3, 3);
        for (int i = 0; i < 7; i++) {
            cartaActual = mazoBarajado->pop();
            getLista4()->insertarAlInicio(cartaActual);
        }
        actualizarPuntaje(4, 4);
        return "Cartas repartidas a los jugadores.\n";
    }
    else {
        return "Numero de jugadores invalido.";
    }
}

string Gestor::validarCarta(int carta) {
    string msg="No se encontro la carta seleccionada. o es invalida";
    NodoCarta* micartaNueva=new NodoCarta();
    NodoCarta* miCartaAn= getPila2()->getTope();
    ListaCarta* miListaCarta;
    switch (listaJugador->getObtenerJugador(jugadorActual)->getJugador().getId()) {
        case 1:
            miListaCarta = getLista1();
            micartaNueva = getLista1()->cartaEscogida(carta);
            break;
        case 2:
            miListaCarta = getLista2();
            micartaNueva = getLista2()->cartaEscogida(carta);
            break;
        case 3:
            miListaCarta = getLista3();
            micartaNueva = getLista3()->cartaEscogida(carta);
            break;
        case 4:
            miListaCarta = getLista4();
            micartaNueva = getLista4()->cartaEscogida(carta);
            break;
        default:
            break;
    }

    if (miReglas->cartaValidaparaJugada(miCartaAn->getCarta(), micartaNueva->getCarta())) {
        getPila2()->push(eliminarCartaEscogida(carta));
        msg = turnosSegunCarta();
    }
    if (miReglas->victoriaPorNumCartas(*miListaCarta)) {
        msg += "\n ¡===UNO==!";
    }
    return msg;

}
Carta Gestor::eliminarCartaEscogida(int carta) {
    Carta micartaEliminada;
    switch (listaJugador->getObtenerJugador(jugadorActual)->getJugador().getId()) {
        case 1:
            micartaEliminada = getLista1()->eliminarPorPosicion(carta);
            break;
        case 2:
            micartaEliminada = getLista2()->eliminarPorPosicion(carta);
            break;
        case 3:
            micartaEliminada = getLista3()->eliminarPorPosicion(carta);
            break;
        case 4:
            micartaEliminada = getLista4()->eliminarPorPosicion(carta);
            break;
        default:
            break;
    }
    return micartaEliminada;
}

string Gestor::mostrarCartasJugadorActual() {
    string cartas= "Jugador Actual: "+jugadorActual+"\n";
    string lista = "";
    NodoJugador* miJugador = listaJugador->getObtenerJugador(jugadorActual);
    NodoCarta* micartaNueva = new NodoCarta();
    NodoCarta* miCartaAn = getPila2()->getTope();
    ListaCarta* miListaCarta = new ListaCarta();
    switch (miJugador->getJugador().getId() )
    {
        case 1:
            miListaCarta = getLista1();
            cartas += getLista1()->mostrarLista();
            break;
        case 2:
            miListaCarta = getLista2();
            cartas += getLista2()->mostrarLista();
            break;
        case 3:
            miListaCarta = getLista3();
            cartas += getLista3()->mostrarLista();
            break;
        case 4:
            miListaCarta = getLista4();
            cartas += getLista4()->mostrarLista();
            break;
        default:
            break;
    }
    actual = miListaCarta;
    if (actual->getTam() != 0) {
        lista = validarsiguienteJugada();
        cartas += lista;
    }
    return cartas;
}
string Gestor::validarsiguienteJugada()
{
    string cartasC = "";
    NodoCarta* micartaNueva = actual->getFrente();
    bool debeComer = validarListaJugador();
    if (debeComer) {
        if ((miReglas->victoriaPorNumCartas(*actual) &&
             miReglas->cartaValidaparaJugada(getPila2()->getTope()->getCarta(), micartaNueva->getCarta())))
        {
            cartasC = "\n La carta o las cartas que posee es invalida \n Se le ha agregado una a su maso \n";
            if (reverso) {
                comerCarta();
                cargarJugadorSiguiente();
            }
            else {
                comerCarta();
                cargarJugadorAnterior();
            }
        }
        else {
            cartasC = "\n La carta o las cartas que posee es invalida \n Se le ha agregado una a su maso \n";
            if (reverso) {
                comerCarta();
                cargarJugadorSiguiente();

            }
            else {
                comerCarta();
                cargarJugadorAnterior();
            }
        }
    }

    return cartasC;
}


bool Gestor::validarListaJugador() {
    bool debeComer = true;
    NodoCarta* micartaNueva = actual->getFrente();
    for (int i = 0; i < actual->getTam(); i++) {
        if (miReglas->cartaValidaparaJugada(getPila2()->getTope()->getCarta(), micartaNueva->getCarta()))
        {
            debeComer = false;
        }
        micartaNueva = micartaNueva->getNext();
    }
    return debeComer;
}
/**
 * Método:                  actualizarPuntaje
 * Descripción:             Método que permite actualizar el puntaje del jugador, proceso en el cual
 * queda enlistado de forma ordenada, con relación a los puntos del scor del mazo de cartas que tiene.
 * @param nJugador          variable de tipo int que representa el número de jugador
 * @param lista             Objeto de tipo ListaCarta que respresenta el mazo del jugador.
 */
void Gestor::actualizarPuntaje(int nJugador, int lista) {
    int puntaje = obtenerPuntaje(lista);
    string nombre = getListaJugador()->obtenerNombreJugador(nJugador);
    int id = getListaJugador()->obtenerIdJugador(nJugador);
    getListaJugadorConScore()->eliminarPorPosicion(nJugador);
    Jugador jugador = Jugador(nombre, id);
    getListaJugadorConScore()->insertarOrdenado(jugador, puntaje);
}
/**
 * Método:                  obtenerPuntaje
 * Descripción:             Método que permite obtner el puntaje del jugador
 * @param lista             variable de tipo ListaCarta que respresenta el mazo de cartas del jugador
 * @return                  variable de tipo int que representa la suma de los puentos de las cartas
 * del mazo del jugador.
 */
int Gestor::obtenerPuntaje(int lista) {
    switch (lista) {
        case 1:
            return getLista1()->obtenerPuntaje();
        case 2:
            return getLista2()->obtenerPuntaje();
        case 3:
            return getLista3()->obtenerPuntaje();
        case 4:
            return getLista4()->obtenerPuntaje();
        default:
            return 0;
    }
}
/**
 * Método:                  sistemaOperativo
 * Descripción:             Método que permite establecer el sistema operativo del equipo en el que se
 * está corriendo el programa.
 * @return                  variable de tipo int que representa el sistema operativo detectado.
 */
int Gestor::sistemaOperativo() {
    int num;
#if defined(_WIN64)
    num = 1;
#elif defined(_MACH_)
    num = 2;
#endif
    return num;
}
/**
 * Método:                  mostrarPuntajeJugador
 * Descripción:             Método que permite mostrar el puntaje de un jugador determinado
 * considerando su posición en el juego.
 * @param poscionJugador    variable de tipo int que representa la posición de entrada al juego
 * esta no está relacionada con su puntaje, sino con el orden de registro al sistema.
 * @return                  variable de tipo string con la información del jugador y sus puntos.
 */
string Gestor::mostrarPuntajeJugador(int poscionJugador) {
    return getListaJugadorConScore()->mostrarInfoJugador(poscionJugador) + "\n";
}
/**
 * Método:                  mostrarPuntajeJugador
 * Descripción:             Método que permite mostrar la información de todos los jugadores del juego
 * @param nJugadores        variable de tipo int que representa el número de jugadores registrados en el juego
 * @return                  variable de tipo string con la información de cada jugador del juego.
 */
string Gestor::mostrarPuntajeJuegadores(int nJugadores) {
    string msg = "Resumen del puntaje por jugador:\n";
    for (int i = 0; i < nJugadores; ++i) {
        msg += mostrarPuntajeJugador(i + 1);
    }
    return msg;
}

string Gestor::cargarJugadorCola(string nombre, int indice) {
    Jugador jugador = Jugador(nombre, indice + 1);
    getCola()->insertElemCola(jugador);
    return "Se ha guardado jugador en la cola";
}