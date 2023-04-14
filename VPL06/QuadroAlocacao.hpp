#ifndef QUADROALOCACAO_HPP
#define QUADROALOCACAO_HPP

#include <iostream>
#include <map>
#include <string>
#include <vector>

class QuadroAlocacao
{
private:
    std::map<std::string, Disciplina> _alocacaoMap; 
public:
    void inserir_alocacao(string codigo, string nome, string dia, string horario, string sala);
    void remover_alocacao_disciplina(string codigo, string horario);
    void imprimir_alocacao_completa();
    vector<Disciplina> recuperar_disciplinas_mais_ofertadas();
};

#endif