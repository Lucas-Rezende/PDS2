#include "Alocacao.hpp"
#include "Disciplina.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

Disciplina::Disciplina() {
    // evita os erros candidate expects x arguments, 0 provided
}

Disciplina::Disciplina(std::string codigo, std::string nome) {
    _codigo = codigo;
    _nome = nome;
}

void Disciplina::inserir_alocacao(std::string dia, std::string horario, std::string sala) {
    Alocacao alocacao(dia, horario, sala);
    _alocacao.push_back(alocacao);
}

void Disciplina::remover_alocacao(std::string horario) {
    _alocacao.erase(std::remove_if(_alocacao.begin(), _alocacao.end(),
        [&horario](const Alocacao& a) { return a.meuHorario() == horario; }),
        _alocacao.end());
}

void Disciplina::imprimir_alocacao() {
    for(Alocacao percorre : minhasAlocacoesOrdenadas())
        std::cout << _codigo << " " << _nome << " " << percorre.meuDia() << " " << percorre.meuHorario() << " " << percorre.minhaSala() << std::endl;
}

std::string Disciplina::meuCodigo() {
    return _codigo;
}

std::string Disciplina::meuNome() {
    return _nome;
}

std::vector<Alocacao> Disciplina::minhasAlocacoes() {
    return _alocacao;
}

std::vector<Alocacao> Disciplina::minhasAlocacoesOrdenadas() {
    std::vector<Alocacao> minhasAlocOrdenadas(_alocacao);

    std::sort(minhasAlocOrdenadas.begin(), minhasAlocOrdenadas.end(), 
              [](Alocacao a1, Alocacao a2) { 
                    return a1.meuHorario() < a2.meuHorario(); 
                });
    return minhasAlocOrdenadas;
}