#ifndef ALOCACAO_HPP
#define ALOCACAO_HPP

#include <string>

class Alocacao
{
    private:
        // Atributos: dia, horario, sala (todos do tipo string).
        std::string _dia;
        std::string _horario;
        std::string _sala;

    public:
        Alocacao();

        // Alocacao(string dia, string horario, string sala): Método construtor para a inicialização dos atributos.
        Alocacao(std::string dia, std::string horario, std::string sala);

        // void imprimir_dados(): faz a impressão dos atributos no seguinte formato: "dia horario sala", com uma quebra de linha ao final.
        void imprimir_dados();

        // outros
        std::string meuHorario() const;
        std::string meuDia() const;
        std::string minhaSala() const;
};

#endif