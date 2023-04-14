#ifndef DISCIPLINA_HPP
#define DISCIPLINA_HPP

#include <map>
#include <string>
#include <vector>

#include "Alocacao.hpp"

class Disciplina
{
private:
    std::string _codigo;
    std::string _nome;
    std::vector<Alocacao> _alocacaosave;
public:
    Disciplina(std::string codigo, std::string nome);
    void inserir_alocacao(std::string dia, std::string horario, std::string sala);
    void remover_alocacao(std::string horario);
    void imprimir_alocacao();
    std::string MeuCodigo();
};

#endif