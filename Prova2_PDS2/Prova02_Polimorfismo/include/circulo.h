#ifndef CIRCULO_H
#define CIRCULO_H

#include "forma2d.h"

#include <stdexcept>
#include <string>

class CirculoInvalidoException : public std::runtime_error {
public:
    CirculoInvalidoException() : std::runtime_error("Círculo inválido") {}
};

class Circulo : public Forma2D
{
private:
    std::string _nome;
    std::string _cor;
    double _raio;
public:
    Circulo(std::string cor, double raio);
    ~Circulo();
    double get_area() override;
    double get_perimetro() override;
    std::string get_cor() override;
    std::string get_nome() override;
};

#endif