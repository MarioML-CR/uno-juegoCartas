//
// Created by Mario Martinez on 09/10/20.
//

#ifndef UNO_JUEGOCARTAS_NODOCARTA_H
#define UNO_JUEGOCARTAS_NODOCARTA_H
#include <iostream>
#include<sstream>
#include "Carta.h"

using namespace std;

class NodoCarta {
public:
    NodoCarta();

    NodoCarta(const Carta &carta);

    virtual ~NodoCarta();

    int getPos() const;

    void setPos(int pos);

    const Carta &getCarta() const;

    void setCarta(const Carta &carta);

    NodoCarta *getNext() const;

    void setNext(NodoCarta *next);

    NodoCarta *getPrev() const;

    void setPrev(NodoCarta *prev);

private:
    int pos;
    Carta carta;
    NodoCarta *next;
    NodoCarta * prev;
};


#endif //UNO_JUEGOCARTAS_NODOCARTA_H
