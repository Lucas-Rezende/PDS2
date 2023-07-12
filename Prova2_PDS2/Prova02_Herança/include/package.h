#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package
{
private:
    unsigned int _peso;
    unsigned int _custoporkilo;
    std::string _nome;
    std::string _endereco;

public:
    Package(
        unsigned int peso,
        unsigned int custoporkilo,
        std::string nome,
        std::string endereco
    );
    virtual ~Package() {}

    /*TODO Possivelmente fazer gets e sets*/
    std::string get_nome();
    unsigned int get_peso();
    unsigned int get_custoporkilo();

    virtual double calculate_cost();
};

#endif