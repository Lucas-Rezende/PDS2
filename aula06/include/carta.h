#ifndef PDS2_CARTA_H //se não ouver sido definido uma carta 
#define PDS2_CARTA_H //Defina um módulo com esse nome PDS2_CARTA_H

enum naipe {
    COPAS, ESPADAS, OURO, PAUS
};

enum num {
    AS, _2, _3, _4, _5, _6, _7, _8, _9, _10, J, Q, K
};

class Carta
{
private:
    num _numero;
    naipe _naipe;
public:
    Carta(num numero, naipe naipe) {
        _numero = numero;
        _naipe = naipe;
    }
    unsigned int get_numero();
    naipe get_naipe();
};

#endif //Finalização da definição