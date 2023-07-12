#ifndef PDS2_SISTEMA_H
#define PDS2_SISTEMA_H

#include <map>
#include <string>

#include "cliente.h"
#include "frota.h"

class cliente_ja_existe_e : public std::exception {
public:
    const char* what() const noexcept override {
        return "Cliente já existe.";
    }
};

class cliente_nao_existe_e : public std::exception {
public:
    const char* what() const noexcept override {
        return "Cliente não existe.";
    }
};

class sem_saldo_e : public std::exception {
public:
    const char* what() const noexcept override {
        return "Sem saldo!";
    }
};

class preco_indisponivel_e : public std::exception {
public:
    const char* what() const noexcept override {
        return "Preço menor ou igual a 0.";
    }
};

/*
 * A classe sistema está ok de métodos e tads utilizados. Porém, ainda tem
 * tarefas aqui.
 *
 * TODO: 1. Faça um novo construtor que recebe o preco da corrida. - FEITO
 *          - Crie uma nova exceção e lançe a mesma se o preço for <= 0. - FEITO
 *       2. Documentar essa classe. - FEITO
 *       3. Garantir que não tem bugs nem leaks - FEITO
 */
class Sistema {
    private:
        std::map<std::string, Cliente *> _clientes;
        std::map<unsigned int, std::string> _carros_alocados;
        Frota _frota;
        double _preco_corrida;
    public:
        /*
         * @brief Construtor que recebe o preço da corrida
         */
        Sistema(double _preco_corrida);

        /*
         * @brief Método sem retorno que adiciona um carro
         * com id único
         */
        void adicionar_carro(std::string cor, unsigned int id);
        
        /*
         * @brief Adiciona e retorna um cliente a partir
         * do nome e lança um erro se houver username repetido
         */
        Cliente *cadastra_cliente(std::string nome);
        
        /*
         * @brief Aloca um carro para um passageiro e verifica
         * se o mesmo possui saldo ou se existe
         */
        Carro *busca_uber(std::string nome);
};

#endif