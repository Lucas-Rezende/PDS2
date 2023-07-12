#include "destinationpackages.h"

DestinationPackages::DestinationPackages() {}

void DestinationPackages::add_package(Package* g) {
    if (g != nullptr) {
        std::string nome = g->get_nome();
        _destpackagemap[nome].push_back(g);
    }
}

double DestinationPackages::custo_total() {
    // computa o custo de todos os usuários
    double custototal = 0.0;
    for (const auto& pair : _destpackagemap) {
        const std::vector<Package*>& pacotes = pair.second;
        for (Package* pacote : pacotes) {
            custototal += pacote->calculate_cost();
        }
    }
    return custototal;
}

double DestinationPackages::custo_total(const std::string& nome) {
    // computa o custo de apenas um usuário
    double custototal = 0.0;
    if (_destpackagemap.count(nome) > 0) { 
        const std::vector<Package*>& pacotes = _destpackagemap[nome];
        for (Package* pacote : pacotes) {
            custototal += pacote->calculate_cost();
        }
    }
    return custototal;
}