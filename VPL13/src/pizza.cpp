#include "../include/pizza.hpp"

std::string Pizza::descricao() const
{
	// TODO: Implemente este metodo.
	/*
	 * Note que aqui voce deve retornar uma descricao detalhada da pizza.
	 *
	 * Exemplos:
	 * 2X Pizza Calabresa, 4 pedacos e borda recheada.
	 * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
	 */

	// std::to_string | Convert numerical value to string
	std::string descricao = std::to_string(_qtd) + "X Pizza " + _sabor + ", " + std::to_string(_pedacos) + " pedacos";

    if (_borda_recheada)
    {
        descricao += " e borda recheada";
    }
    else
    {
        descricao += " e sem borda recheada";
    }
    descricao += ".";

    return descricao;	
}

Pizza::Pizza(const std::string &sabor,
			 int pedacos,
			 bool borda_recheada,
			 int qtd,
			 float valor_unitario) : _sabor(sabor), _pedacos(pedacos), _borda_recheada(borda_recheada), _qtd(qtd), _valor_unitario(valor_unitario)
{
	// TODO: Implemente este metodo.
}

float Pizza::getValor() const {
    return _valor_unitario * _qtd;
}