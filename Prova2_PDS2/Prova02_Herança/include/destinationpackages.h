#ifndef DESTINATION_PACKAGES_H
#define DESTINATION_PACKAGES_H

#include "package.h"

#include <map>
#include <vector>

class DestinationPackages
{
private:
    // indexa pelo nome do usuário
    std::map<std::string, std::vector<Package*>> _destpackagemap;
public:
    DestinationPackages();

    void add_package(Package* g);

    // computa o custo de todos os usuários
    double custo_total();

    // computa os custos de um único usuário.
    double custo_total(const std::string& nome);
};

#endif