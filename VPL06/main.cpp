#include "Alocacao.hpp"
#include "Disciplina.hpp"
#include "QuadroAlocacao.hpp"
#include "avaliacao_basica_alocacao.hpp"

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    QuadroAlocacao meuquadro;

    char comando;
    while (std::cin >> comando) {
        switch (comando) {
            case 'a':
            {
                string nome, codigo, horario, dia, sala;
                std::cin >> codigo >> nome >> dia >> horario >> sala;
                meuquadro.inserir_alocacao(codigo, nome, dia, horario, sala);
                break;
            }
            case 'm':
            {
                std::vector<Disciplina> maisOfertadas = meuquadro.recuperar_disciplinas_mais_ofertadas();
                for (Disciplina disciplina : maisOfertadas)
                {
                    disciplina.imprimir_alocacao();
                }
                break;
            }
            case 'r':
            {
                std::string codigo, horario;
                std::cin >> codigo >> horario;
                meuquadro.remover_alocacao_disciplina(codigo, horario);
                break;
            }
            case 'p':
            {
                meuquadro.imprimir_alocacao_completa();
                break;
            }
            case 'b':
            {
                avaliacao_basica();
                break;
            }
            default:
            {
                break;
            }
        }
    }
    return 0;
}