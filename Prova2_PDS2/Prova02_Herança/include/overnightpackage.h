#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "package.h"

class OverNightPackage : public Package
{
private:
    float _taxaadicional;
public:
    OverNightPackage(
        unsigned int peso,
        unsigned int custoporkilo,
        float taxaadicional,
        std::string nome,
        std::string endereco
    );

    double calculate_cost() override;
};

#endif