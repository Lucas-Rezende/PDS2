#ifndef LISTAPROCESSOS_HPP
#define LISTAPROCESSOS_HPP

#include "Processo.hpp"
#include <iostream>
#include <vector>

class ListaProcessos
{
private:
    std::vector<Processo> processos;
public:
    unsigned int local_add(unsigned int prioridade);
    void adicionar_processo(Processo proc);
    Processo remover(int x);
    Processo remover_processo_maior_prioridade();
    Processo remover_processo_menor_prioridade();
    Processo remover_processo_por_id(unsigned int id);
    void imprimir_lista();
};

#endif