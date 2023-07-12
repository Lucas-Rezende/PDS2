#include <exception>
#include <iostream>

#include "include/sistema.h"
#include "include/carro.h"
#include "include/cliente.h"
#include "include/frota.h"

int main() {
    Sistema sistema_uber = Sistema(10.0); // Supondo que o preço da corrida seja 10.0

    sistema_uber.adicionar_carro("branco", 0);
    sistema_uber.adicionar_carro("verde", 2);
    sistema_uber.adicionar_carro("verde", 1);
    sistema_uber.adicionar_carro("vermelho", 10);

    try {
    sistema_uber.adicionar_carro("verde", 1);
    } catch (id_ja_existe_e& e) {
        std::cout << e.what() << std::endl;  // Imprime a mensagem de erro, caso seja necessário
    }


    Cliente *flavio = sistema_uber.cadastra_cliente("flavio@dcc");
    Cliente *ana = sistema_uber.cadastra_cliente("ana@dcc");
    Cliente *pedro = sistema_uber.cadastra_cliente("pedro");

    try {
        sistema_uber.cadastra_cliente("flavio@dcc");
    } catch (cliente_ja_existe_e &e) {
        std::cout << "O cliente já existe!" << std::endl;   // Imprime a mensagem de erro, caso seja necessário
    }

    try {
        flavio->adicionar_saldo(-2);
    } catch (impossivel_adicionar_saldo_negativo_e &e) {
        std::cout << "Não podemos adicionar saldo negativo" << std::endl;   // Imprime a mensagem de erro, caso seja necessário
    }

    flavio->adicionar_saldo(50);
    ana->adicionar_saldo(20);

    try {
        ana->remover_saldo(50);
    } catch (saldo_insuficiente_para_remocao_e &e) {
        std::cout << "Não posso remover saldo de valor 50 de ana" << std::endl; // Imprime a mensagem de erro, caso seja necessário
    }

    Carro *cf = sistema_uber.busca_uber("flavio@dcc");
    std::cout << "Carro de placa " << cf->get_id();
    std::cout << " está ocupado? " << cf->ocupado() << std::endl;
    
    Carro *add = sistema_uber.busca_uber("ana@dcc");
    std::cout << "Carro de placa " << add->get_id();
    std::cout << " está ocupado? " << add->ocupado() << std::endl;
    
    try {
    sistema_uber.busca_uber("pedro");
    } catch (sem_saldo_e &e) {
        std::cout << "Não posso alocar um carro para " << pedro->get_login() << "!" << std::endl; // Imprime a mensagem de erro, caso seja necessário
    }

}  