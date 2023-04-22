#include "Alocacao.hpp"
#include "Disciplina.hpp"
#include "QuadroAlocacao.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void QuadroAlocacao::inserir_alocacao(std::string codigo, std::string nome, std::string dia, std::string horario, std::string sala) {
    if (_disciplinas.find(codigo) == _disciplinas.end()) {
        _disciplinas[codigo] = Disciplina(codigo, nome);
    }

    _disciplinas[codigo].inserir_alocacao(dia, horario, sala);
    _alocacoes[codigo].emplace_back(dia, horario, sala);
}

bool VerifiqueAlocacao(const std::pair<std::string, std::vector<Alocacao>>& a, const std::pair<std::string, std::vector<Alocacao>>& b) {
    return a.second.size() > b.second.size();
}

std::vector<Disciplina> QuadroAlocacao::recuperar_disciplinas_mais_ofertadas()
{
    std::map<std::string, std::vector<Alocacao>> PercorreAlocacoes;

    for (auto const& pair : _disciplinas)
    {
        Disciplina PercorreDisciplinas = pair.second;
        for (auto const& aloc : PercorreDisciplinas.minhasAlocacoes())
        {
            PercorreAlocacoes[PercorreDisciplinas.meuCodigo()].push_back(aloc);
        }
    }

    std::vector<std::pair<std::string, std::vector<Alocacao>>> MapaOrdenado(PercorreAlocacoes.begin(), PercorreAlocacoes.end());
    std::sort(MapaOrdenado.begin(), MapaOrdenado.end(), VerifiqueAlocacao);

    std::vector<Disciplina> disciplinasMaisOfertadas;

    int maxNumAlocacoes = 0;
    auto it = MapaOrdenado.begin();

    while (it != MapaOrdenado.end()) {
        Disciplina disciplina = _disciplinas[it->first];
        int numAlocacoes = disciplina.minhasAlocacoes().size();

        if (disciplinasMaisOfertadas.empty() || numAlocacoes >= maxNumAlocacoes) {
            disciplinasMaisOfertadas.push_back(disciplina);
            maxNumAlocacoes = numAlocacoes;
        }
        else {
            break;
        }

        it++;
    }

    return disciplinasMaisOfertadas;
}

void QuadroAlocacao::imprimir_alocacao_completa() {
    std::vector<std::string> address;
    for (auto pair : _disciplinas) {
        address.push_back(pair.first);
    }

    std::sort(address.begin(), address.end());
    
    auto iterator = address.begin();
    do {
        Disciplina& disciplina = _disciplinas[*iterator];        
        for (Alocacao percorre : disciplina.minhasAlocacoesOrdenadas()) {
            std::cout << disciplina.meuCodigo() << " " << disciplina.meuNome() << " " << percorre.meuDia() << " " << percorre.meuHorario() << " " << percorre.minhaSala() << std::endl;
        }
        ++iterator;
    } while (iterator != address.end());
}

void QuadroAlocacao::remover_alocacao_disciplina(std::string codigo, std::string horario) {
    Disciplina& disciplina = _disciplinas[codigo];
    disciplina.remover_alocacao(horario);

    std::vector<Alocacao>& alocacoes = _alocacoes[codigo];
    auto iterator = std::remove_if(alocacoes.begin(), alocacoes.end(),
                             [horario](const Alocacao& aloc) { return aloc.meuHorario() == horario; });
    alocacoes.erase(iterator, alocacoes.end());
}