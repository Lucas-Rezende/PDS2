Disciplina.cpp

#include "Disciplina.hpp"
#include <algorithm>
#include <iostream>

Disciplina::Disciplina(std::string codigo, std::string nome)
{
    this->codigo = codigo;
    this->nome = nome;
}

void Disciplina::inserir_alocacao(std::string dia, std::string horario, std::string sala)
{
    Alocacao nova_alocacao(dia, horario, sala);
    alocacoes.push_back(nova_alocacao);
    std::sort(alocacoes.begin(), alocacoes.end(), [](const Alocacao &a1, const Alocacao &a2)
              { return a1.imprimir_dados() < a2.imprimir_dados(); });
}

void Disciplina::remover_alocacao(std::string horario)
{
    for (auto it = alocacoes.begin(); it != alocacoes.end(); ++it)
    {
        if (it->horario == horario)
        {
            alocacoes.erase(it);
            break;
        }
    }
}

void Disciplina::imprimir_alocacao()
{
    for (const auto &alocacao : alocacoes)
    {
        std::cout << codigo << " " << nome << " ";
        alocacao.imprimir_dados();
    }
}