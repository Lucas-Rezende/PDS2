#include "esfera.h"

#include <cmath>

Esfera::Esfera(std::string cor, double raio) : _nome("esfera"), _cor(cor), _raio(raio) {
    if (_raio <= 0) {
        throw EsferaInvalidaException();
    }
}

double Esfera::get_volume()
{
    return (4.0 / 3.0) * M_PI * pow(_raio, 3);
}

std::string Esfera::get_cor()
{
    return _cor;
}

std::string Esfera::get_nome()
{
    return _nome;
}

Esfera::~Esfera() {}