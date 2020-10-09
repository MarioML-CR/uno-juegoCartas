//
// Created by Mario Martinez on 09/10/20.
//

#ifndef UNO_JUEGOCARTAS_VALIDAR_H
#define UNO_JUEGOCARTAS_VALIDAR_H

#include <iostream>
#include <string>
using namespace std;

class Validar {
public:
    int ingresarInt(string pValor);
    string ingresarString(string pValor);
    int ingresarIntRango(string pValor, int, int);
};



#endif //UNO_JUEGOCARTAS_VALIDAR_H
