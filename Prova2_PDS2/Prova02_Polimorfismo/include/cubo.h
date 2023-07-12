#ifndef CUBO_H
#define CUBO_H

#include "forma3d.h"

#include <stdexcept>
#include <string>

class CuboInvalidoException : public std::runtime_error {
public:
    CuboInvalidoException() : std::runtime_error("Cubo inválido") {}
};

class Cubo : public Forma3D
{
private:
    std::string _nome;
    std::string _cor;
    double _tamanhodaaresta;
public:
    Cubo(std::string cor, double tamanhodaresta);
    ~Cubo();
    double get_volume() override;
    std::string get_cor() override;
    std::string get_nome() override;
};

#endif