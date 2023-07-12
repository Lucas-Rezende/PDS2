#include "../include/carro.h"

#include <string>

Carro::Carro(std::string cor, int id)
{
    _cor = cor;
    _id = id;
    _ocupado = NULL;
}

std::string Carro::get_cor()
{
    return _cor;
}

unsigned int Carro::get_id() const
{
    return _id;
}

void Carro::seta_ocupado() {
    _ocupado = true;
}

bool Carro::ocupado()
{
    return _ocupado;
}