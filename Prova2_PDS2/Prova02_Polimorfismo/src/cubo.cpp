#include "cubo.h"

#include <cmath>

Cubo::Cubo(std::string cor, double tamanhodaaresta) : _nome("cubo"), _cor(cor), _tamanhodaaresta(tamanhodaaresta) {
    if (_tamanhodaaresta <= 0) {
        throw CuboInvalidoException();
    }
}

double Cubo::get_volume() {
    return pow(_tamanhodaaresta, 3);
}

std::string Cubo::get_cor() {
    return _cor;
}

std::string Cubo::get_nome() {
    return _nome;
}

Cubo::~Cubo() {}