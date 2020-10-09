//
// Created by Mario Martinez on 09/10/20.
//

#ifndef UNO_JUEGOCARTAS_PILACARTA_H
#define UNO_JUEGOCARTAS_PILACARTA_H


#include "Carta.h"
#include "NodoCarta.h"

class PilaCarta {
public:
    PilaCarta();

    virtual ~PilaCarta();

    NodoCarta *getTope() const;

    void setTope(NodoCarta *tope);

    int getTam() const;

    void setTam(int tam);

    bool esVaciaPila();

    void push(Carta); // insertar elemento en la pila

    Carta pop();

    int longitudPila(); // obtener el tamaño de la pila

    Carta topePila();

    string destruirPila();
private:
    NodoCarta *tope;
    int tam;
    void updatePosiciones();
};


#endif //UNO_JUEGOCARTAS_PILACARTA_H
