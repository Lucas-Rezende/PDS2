#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "Alocacao.hpp"

#include <map>
#include <string>
#include <vector>

class Disciplina
{
    private:
        // Atributos: codigo e nome (ambos do tipo string), e alocacao (que guarda uma coleção de elementos do tipo Alocacao, você deve escolher a estrutura que julgar mais adequada para usar).
        std::string _codigo;
        std::string _nome;
        std::vector<Alocacao> _alocacao;
    public:
        Disciplina();
        Disciplina(std::string codigo, std::string nome);

        //void inserir_alocacao(string dia, string horario, string sala): cria uma nova alocação para a disciplina a partir dos dados informados e insere na coleção.
        void inserir_alocacao(std::string dia, std::string horario, std::string sala);

        // void remover_alocacao(string horario): remove uma alocação da coleção. Para facilitar, vamos assumir que existe apenas uma única alocação em cada horário.
        void remover_alocacao(std::string horario);

        // void imprimir_alocacao(): imprime todas as alocações para a disciplina. Cada alocação deve ser impressa em uma linha separada e seguindo o formato "codigo nome dia horario sala". Além disso, a alocação deve ser impressa ordenada de acordo com o horário.
        void imprimir_alocacao();

        // outros
        std::string meuCodigo();
        std::string meuNome();
        std::vector<Alocacao> minhasAlocacoes();
        std::vector<Alocacao> minhasAlocacoesOrdenadas();
};

#endif