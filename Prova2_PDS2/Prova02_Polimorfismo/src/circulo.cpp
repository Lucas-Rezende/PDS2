#include "circulo.h"

#include <cmath>

Circulo::Circulo(std::string cor, double raio) : _nome("circulo"), _cor(cor), _raio(raio) {
    if (_raio <= 0) {
        throw CirculoInvalidoException();
    }
}

double Circulo::get_area() {
    return M_PI*pow(_raio, 2);
}

double Circulo::get_perimetro() {
    return 2*M_PI*_raio;
}

std::string Circulo::get_cor() {
    return _cor;
}

std::string Circulo::get_nome() {
    return _nome;
}

Circulo::~Circulo() {}