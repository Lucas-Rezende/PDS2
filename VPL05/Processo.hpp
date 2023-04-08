#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include <iostream>
#include <string>

class Processo
{
private:
    unsigned int _id;
    std::string _nome;
    unsigned int _prioridade;
public:
    Processo(unsigned int id, std::string nome, unsigned int prioridade);
    void imprimir_dados();
    unsigned int MinhaPrioridade();
    unsigned int MeuID();
};

#endif