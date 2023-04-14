#include "Alocacao.hpp"
#include <iostream>

Alocacao::Alocacao(std::string dia, std::string horario, std::string sala) {
    _dia = dia;
    _horario = horario;
    _sala = sala;
}

void Alocacao::imprimir_dados() {
    std::cout << _dia << " " << _horario << " " << _sala << std::endl;
}

std::string Alocacao::MeuHorario() {
    return _horario;
}

std::string Alocacao::MeuDia() {
    return _dia;
}

std::string Alocacao::MinhaSala() {
    return _sala;
}