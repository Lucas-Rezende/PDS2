#include "../include/frota.h"

/*
    Adição pessoal
    Motivo: procurar por um elemento em um container com base em uma condição especificada.
*/
#include <algorithm>

void Frota::cadastrar_carro(std::string cor, unsigned int id) {
    Carro c = Carro(cor, id); //temp car apenas para adicionar
    
    auto it = std::find_if(_carros.begin(), _carros.end(), [&](const Carro& carro) {
        //auto it se torna um iterador que aponta pra posição final, caso não aja repetição, ou aponta pra posição do id repetido, caso aja repetição
        return carro.get_id() == id;
    });
    
    if (it != _carros.end()) {
        throw id_ja_existe_e();
    } else
    {
        _carros.push_back(c); // adiciona ao vetor _carros do tipo Carro mais um carro
    } 
}

Carro Frota::alocar_carro() {
    if (_carros.empty()) {
        throw zero_carros_disponiveis_e();
    } else {
        Carro alocado = _carros.front(); // Faz uma cópia do primeiro carro
        _carros.erase(_carros.begin()); // Apaga o primeiro carro
        alocado.seta_ocupado(); // Define o status de ocupação como verdadeiro para o carro alocado
        return alocado;
    }
}