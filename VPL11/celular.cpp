#include "celular.hpp"

// TODO: Inicialize aqui sua variavel estatica. Caso tenha optado por essa
// solucao.
int Celular::_proximocodigo = 1;

// inicializando construtor
Celular::Celular(std::string modelo,
                 std::string fabricante,
                 int armazenamento,
                 int memoria,
                 double peso,
                 std::string cor,
                 int qtd,
                 float valor) : _modelo(modelo), _fabricante(fabricante), _armazenamento(armazenamento),
                                _memoria(memoria), _peso(peso), _cor(cor), _qtd(qtd), _valor(valor)
{
    _codigo = _proximocodigo; // Atribui o código atual ao celular
    _proximocodigo++;
}

bool Celular::operator<(const Celular &other) const
{
    if (this->_fabricante < other._fabricante)
    {
        return true;
    }
    else if (this->_fabricante > other._fabricante)
    {
        return false;
    }

    return this->_modelo < other._modelo;
}

std::string Celular::getModelo() const
{
    return _modelo;
}

std::string Celular::getFabricante() const
{
    return _fabricante;
}

int Celular::getArmazenamento() const
{
    return _armazenamento;
}

int Celular::getMemoria() const
{
    return _memoria;
}

double Celular::getPeso() const
{
    return _peso * 1000;
}

std::string Celular::getCor() const
{
    return _cor;
}

int Celular::getQtd() const
{
    return _qtd;
}

float Celular::getValor() const
{
    return _valor;
}

int Celular::getCodigo() const
{
    return _codigo;
}

void Celular::setQtd(int qtd)
{
    _qtd = qtd;
}

void Celular::setValor(float valor) {
    _valor = valor;
}