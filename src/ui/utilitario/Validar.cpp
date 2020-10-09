//
// Created by Mario Martinez on 09/10/20.
//

#include "Validar.h"

int Validar::ingresarInt(string pValor) {
    try {
        return stoi(pValor);
    } catch (exception e) {
//        cout << e.what();
        return -1;
    }
}
string Validar::ingresarString(string pValor) {
    try {
        return pValor;
    }
    catch (exception e) {
        //        cout << e.what();
        return "-1";
    }
}

int Validar::ingresarIntRango(string pValor, int limInf, int limSup) {
    int num;
    try {
        num = stoi(pValor);
        if (num > limInf && num < limSup){
            return num;
        }
    } catch (exception e) {
//        cout << e.what();
        return -1;
    }
}
