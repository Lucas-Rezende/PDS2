#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "package.h"

class TwoDayPackage : public Package
{
private:
    float _taxafixa;
public:
    TwoDayPackage(
        unsigned int peso,
        unsigned int custoporkilo,
        float taxafixa,
        std::string nome,
        std::string endereco
    );

    double calculate_cost() override;
};

#endif