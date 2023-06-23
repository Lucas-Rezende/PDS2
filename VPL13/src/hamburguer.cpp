#include "../include/hamburguer.hpp"

std::string Hamburguer::descricao() const
{
	// TODO: Implemente este metodo.
	/*
	 * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
	 *
	 * Exemplos:
	 * 1X Hamburguer X-tudo artesanal.
	 * 1X Hamburguer X-tudo simples.
	 */

	std::string descricao = std::to_string(_qtd) + "X Hamburguer " + _tipo;

	if (_artesanal)
	{
		descricao += " artesanal";
	}
	else
	{
		descricao += " simples";
	}
	
	descricao += ".";

	return descricao;
}

Hamburguer::Hamburguer(const std::string &tipo,
					   bool artesanal,
					   int qtd,
					   float valor_unitario) : _tipo(tipo), _artesanal(artesanal), _qtd(qtd), _valor_unitario(valor_unitario)
{
	// TODO: Implemente este metodo.
}

float Hamburguer::getValor() const {
    return _valor_unitario * _qtd;
}