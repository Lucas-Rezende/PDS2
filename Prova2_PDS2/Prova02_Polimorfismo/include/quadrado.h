#ifndef QUADRADO_H
#define QUADRADO_H

#include "forma2d.h"

#include <stdexcept>
#include <exception>
#include <string>

class QuadradoInvalidoException : public std::runtime_error {
public:
    QuadradoInvalidoException() : std::runtime_error("Quadrado inválido") {}
};

class Quadrado : public Forma2D
{
private:
    std::string _nome;
    std::string _cor;
    double _tamanhodaaresta;
public:
    Quadrado(std::string cor, double tamanhodaaresta);
    ~Quadrado();
    double get_area() override;
    double get_perimetro() override;
    std::string get_cor() override;
    std::string get_nome() override;
};

#endif