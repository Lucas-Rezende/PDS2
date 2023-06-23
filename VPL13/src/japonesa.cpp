#include "../include/japonesa.hpp"

std::string Japonesa::descricao() const
{
    // TODO: Implemente este metodo.
    /*
     * Note que aqui voce deve retornar uma descricao detalhada da comida
     * japonesa.
     *
     * Exemplos:
     * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
     * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
     */

    std::string descricao = std::to_string(_qtd) + "X Comida japonesa - " + (_combinado) + ", " + std::to_string(_sushi) + " sushis, " + std::to_string(_temaki) + " temakis e " + std::to_string(_hots) + " hots.";
    descricao += ".";

    return descricao;
}

Japonesa::Japonesa(const std::string &combinado,
                   int sushi,
                   int temaki,
                   int hots,
                   int qtd,
                   float valor_unitario) : _combinado(combinado), _sushi(sushi), _temaki(temaki), _hots(hots), _qtd(qtd), _valor_unitario(valor_unitario)   
{
    // TODO: Implemente este metodo.
}

float Japonesa::getValor() const {
    return _valor_unitario * _qtd;
}