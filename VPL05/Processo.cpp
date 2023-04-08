#include "Processo.hpp"

Processo::Processo(unsigned int id, std::string nome, unsigned int prioridade)
{
    _id = id;
    _nome = nome;
    _prioridade = prioridade;
}

void Processo::imprimir_dados()
{
    std::cout << _id << " " << _nome << " " << _prioridade << std::endl;
}

unsigned int Processo::MinhaPrioridade()
{
    return _prioridade;
}

unsigned int Processo::MeuID()
{
    return _id;
}