    #include "triangulo.h"

    #include <cmath>

    Triangulo::Triangulo(std::string cor, double aresta1, double aresta2, double aresta3) : _nome("triangulo"), _cor(cor), _aresta1(aresta1), _aresta2(aresta2), _aresta3(aresta3) {}

    double Triangulo::get_area()
    {
        /*A fórmula de Heron é dada por:

        A = √(s * (s - a) * (s - b) * (s - c))

        onde:
        A é a área do triângulo,
        a, b e c são os comprimentos dos lados do triângulo, e
        s é o semiperímetro do triângulo, calculado da seguinte forma:

        s = (a + b + c) / 2*/

        if (_aresta1 <= 0 || _aresta2 <= 0 || _aresta3 <= 0 || (_aresta1 + _aresta2 <= _aresta3) ||
            (_aresta1 + _aresta3 <= _aresta2) || (_aresta2 + _aresta3 <= _aresta1))
        {
            throw TrianguloInvalidoException();
        }

        double semiperimetro = (_aresta1 + _aresta2 + _aresta3) / 2;
        return (sqrt(semiperimetro * (semiperimetro - _aresta1) * (semiperimetro - _aresta2) * (semiperimetro - _aresta3)));
    }

    double Triangulo::get_perimetro()
    {
        if (_aresta1 <= 0 || _aresta2 <= 0 || _aresta3 <= 0 || (_aresta1 + _aresta2 <= _aresta3) ||
            (_aresta1 + _aresta3 <= _aresta2) || (_aresta2 + _aresta3 <= _aresta1))
        {
            throw TrianguloInvalidoException();
        }

        return _aresta1 + _aresta2 + _aresta3;
    }

    std::string Triangulo::get_cor()
    {
        return _cor;
    }

    std::string Triangulo::get_nome()
    {
        return _nome;
    }

    double Triangulo::get_a1()
    {
        return _aresta1;
    }

    double Triangulo::get_a2()
    {
        return _aresta2;
    }

    double Triangulo::get_a3()
    {
        return _aresta3;
    }

    Triangulo::~Triangulo() {}