//
// Created by Mario Martinez on 09/10/20.
//

#ifndef UNO_JUEGOCARTAS_JUGADOR_H
#define UNO_JUEGOCARTAS_JUGADOR_H

#include <iostream>
#include <string>
using namespace std;

class Jugador {
public:
    Jugador();

    Jugador(const string& nombre, int id);

    virtual ~Jugador();

    const string& getNombre() const;

    void setNombre(const string& nombre);

    int getId() const;

    void setId(int id);

    string toString() const;
private:
    string nombre;
    int id;
};


#endif //UNO_JUEGOCARTAS_JUGADOR_H
