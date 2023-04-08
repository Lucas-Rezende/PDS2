// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_escalonador.hpp"
#include "ListaProcessos.hpp"
#include "Processo.hpp"

#include <iostream>
#include <vector>
#include <string>

int main() {
    ListaProcessos lista;
    char comando;
    int id, prioridade;
    std::string nome;
    while (std::cin >> comando) {
        switch (comando) {
            case 'a':
                std::cin >> id >> nome >> prioridade;
                lista.adicionar_processo(Processo(id, nome, prioridade));
                break;
            case 'm':
                lista.remover_processo_maior_prioridade();
                //lista.imprimir_lista();
                break;
            case 'n':
                lista.remover_processo_menor_prioridade();
                //lista.imprimir_lista();
                break;
            case 'r':
                std::cin >> id;
                lista.remover_processo_por_id(id);
                //lista.imprimir_lista();
                break;
            case 'p':
                lista.imprimir_lista();
                break;
            case 'b' :
                avaliacao_basica();
            /*default:
                std::cout << "Comando inválido." << std::endl;
                break;*/
        }
    }
    return 0;
}