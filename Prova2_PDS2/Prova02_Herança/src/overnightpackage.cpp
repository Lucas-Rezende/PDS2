#include "overnightpackage.h"

OverNightPackage::OverNightPackage(unsigned int peso, unsigned int custoporkilo, float taxaadicional, std::string nome, std::string endereco)
    : Package(peso, custoporkilo, nome, endereco), _taxaadicional(taxaadicional) {}

double OverNightPackage::calculate_cost() {
    // O certo é somar a taxa adicional ao custo por quilo, e multiplicar pelo peso
    double custo = Package::get_peso() * (Package::get_custoporkilo() + _taxaadicional);
    return custo;
}