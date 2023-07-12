#ifndef PDS2_FROTA_H
#define PDS2_FROTA_H

#include <vector>
#include <string>

#include "../include/carro.h"

class zero_carros_disponiveis_e : public std::exception {
public:
    const char* what() const noexcept override {
        return "Nenhum carro disponível na frota.";
    }
};

class id_ja_existe_e : public std::exception {
public:
    const char* what() const noexcept override {
        return "Id do carro já existe!";
    }
};

/*
 * A frota simplesmente cuida do nosso comboio. Isto é, podemos adicionar
 * carros para a frota e remover os mesmos alocando para uma corrida.
 * TODO: ALGUMAS (ou TODAS) de suas tarefas aqui:
 *   1. Garantir que exceções são lançadas. - FEITO
 *   2. Garantir que sempre o primeiro carro cadastrado é o alocado para corrida
 *      caso não esta disponível, passe para o próximo. - FEITO
 *   3. Ajustar bugs e memory leaks caso existam - FEITO
 *
 *  Altere o container (ou adicione outros) se necessário
 */
class Frota {
    private:
        std::vector<Carro> _carros;
    public:
        /*
         * @brief Cadastra um carro novo no sistema.
         *        o id dos carros tem que ser únicos
         *        se não, uma exceção deve ser lançada.
         */
        void cadastrar_carro(std::string cor, unsigned int id);

        /*
         * @brief Aloca um carro. O carro alocado deve ser aquele que foi
         *        cadastrado mais no passado.
         */
        Carro alocar_carro();
};

#endif