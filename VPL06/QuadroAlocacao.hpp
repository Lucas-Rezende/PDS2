#ifndef QUADROALOCACAO_HPP
#define QUADROALOCACAO_HPP

#include <iostream>
#include <map>

class QuadroAlocacao
{
private:
    std::map<std::string, Disciplina> _alocacaoMap; 
public:
    void inserir_alocacao(string codigo, string nome, string dia, string horario, string sala);
    remover_alocacao_disciplina(string codigo, string horario);
    vector<Disciplina> recuperar_disciplinas_mais_ofertadas();
    imprimir_alocacao_completa();
};

#endif