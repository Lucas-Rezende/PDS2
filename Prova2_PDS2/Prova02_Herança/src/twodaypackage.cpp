    #include "twodaypackage.h"

    TwoDayPackage::TwoDayPackage(unsigned int peso, unsigned int custoporkilo, float taxafixa, std::string nome, std::string endereco)
        : _taxafixa(taxafixa), Package(peso, custoporkilo, nome, endereco) {}


    double TwoDayPackage::calculate_cost() {
        // TwoDayPackage deve redefinir o método calculate_cost para que ele calcule o custo de entrega adicionando a taxa fixa ao custo baseado em peso calculado pela função calculate_cost da super classe Package.
        return (get_peso() * get_custoporkilo()) + _taxafixa;
    }
