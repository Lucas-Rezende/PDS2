#ifndef ALOCACAO_HPP
#define ALOCACAO_HPP

#include <vector>
#include <string>

class Alocacao
{
private:
    std::string _dia;
    std::string _horario;
    std::string _sala;
public:
    Alocacao(std::string dia, std::string horario, std::string sala);
    void imprimir_dados();
    std::string MeuHorario();
    std::string MeuDia();
};

#endif