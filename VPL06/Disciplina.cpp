#include "Alocacao.hpp"
#include "Disciplina.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>

Disciplina::Disciplina(std::string codigo, std::string nome)
{
    _codigo = codigo;
    _nome = nome;
}

void Disciplina::inserir_alocacao(std::string dia, std::string horario, std::string sala)
{
    Alocacao nova_alocacao(dia, horario, sala);
    _alocacaosave.push_back(nova_alocacao);
}

void Disciplina::remover_alocacao(std::string horario)
{
    for (auto it = _alocacaosave.begin(); it != _alocacaosave.end(); ++it)
    {
        if (it->MeuHorario() == horario)
        {
            _alocacaosave.erase(it);
            break;
        }
    }
}

void Disciplina::imprimir_alocacao()
{
    for (Alocacao percorrealocacao : _alocacaosave)
    {
        std::cout << _codigo << " " << _nome << " " << percorrealocacao.MeuDia() << " " << percorrealocacao.MeuHorario() << " " << percorrealocacao.MinhaSala() << std::endl;
    }
}

std::string Disciplina::MeuCodigo() {
    return _codigo;
}