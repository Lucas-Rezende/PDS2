#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "../include/forma2d.h"

#include <stdexcept>
#include <exception>
#include <string>

class TrianguloInvalidoException : public std::runtime_error {
public:
    TrianguloInvalidoException() : std::runtime_error("Triangulo inválido") {}
};

class Triangulo : public Forma2D
{
private:
    std::string _nome;
    std::string _cor;
    double _aresta1, _aresta2, _aresta3;

public:
    Triangulo(std::string cor, double _aresta1, double _aresta2, double _aresta3);
    ~Triangulo();
    double get_area() override;
    double get_perimetro() override;
    std::string get_cor() override;
    std::string get_nome() override;

    double get_a1();
    double get_a2();
    double get_a3();
};

#endif