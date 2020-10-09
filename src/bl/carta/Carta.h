//
// Created by Mario Martinez on 09/10/20.
//

#ifndef UNO_JUEGOCARTAS_CARTA_H
#define UNO_JUEGOCARTAS_CARTA_H
#include <iostream>
#include <string>
using namespace std;

class Carta {
public:
    Carta();

    Carta(const string &descripcion, const string &color, int puntos);

    virtual ~Carta();

    const string &getDescripcion() const;

    void setDescripcion(const string &descripcion);

    const string &getColor() const;

    void setColor(const string &color);

    int getPuntos() const;

    void setPuntos(int puntos);

    string toString() const;

private:
    string descripcion;
    string color;
    int puntos;
};


#endif //UNO_JUEGOCARTAS_CARTA_H
