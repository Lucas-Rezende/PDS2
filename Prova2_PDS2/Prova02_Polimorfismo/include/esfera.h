#ifndef ESFERA_H
#define ESFERA_H

#include "forma3d.h"

#include <stdexcept>
#include <string>

class EsferaInvalidaException : public std::runtime_error {
public:
    EsferaInvalidaException() : std::runtime_error("Esfera inválida") {}
};

class Esfera : public Forma3D
{
private:
    std::string _nome;
    std::string _cor;
    double _raio;
public:
    Esfera(std::string cor, double raio);
    ~Esfera();
    double get_volume() override;
    std::string get_cor() override;
    std::string get_nome() override;
};

#endif