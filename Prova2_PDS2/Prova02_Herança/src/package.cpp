#include "package.h"

Package::Package(
    unsigned int peso,
    unsigned int custoporkilo,
    std::string nome,
    std::string endereco) : _peso(peso), _custoporkilo(custoporkilo), _nome(nome), _endereco(endereco) {}

double Package::calculate_cost()
{
    // Package deve fornecer um método public calculate_cost que retorna um double indicando o custo associado com a entrega do pacote. A função calculate_cost de Package deve determinar o custo multiplicando o peso pelo custo(em quilos).
    return _peso * _custoporkilo;
}

std::string Package::get_nome() {
        return _nome;
}

unsigned int Package::get_peso() {
    return _peso;
}

unsigned int Package::get_custoporkilo() {
    return _custoporkilo;
}