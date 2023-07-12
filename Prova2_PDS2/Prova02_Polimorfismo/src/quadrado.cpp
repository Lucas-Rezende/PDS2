#include "quadrado.h"

#include <cmath>

Quadrado::Quadrado(std::string cor, double tamanhodaresta) : _nome("quadrado"), _cor(cor), _tamanhodaaresta(tamanhodaresta) {
    if (_tamanhodaaresta <= 0) {
        throw QuadradoInvalidoException();
    }
}

double Quadrado::get_area() {
    return pow(_tamanhodaaresta, 2);
}

double Quadrado::get_perimetro() {
    return 4*_tamanhodaaresta;
}

std::string Quadrado::get_cor() {
    return _cor;
}

std::string Quadrado::get_nome() {
    return _nome;
}

Quadrado::~Quadrado() {}