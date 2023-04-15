#ifndef PONTO_H
#define PONTO_H

#include <iostream>

class Ponto2D
{
private:
    double _x;
    double _y;
public:
    //• Essa classe deve possuir um construtor que recebe x e y, ambos do tipo double, e inicializa os membros correspondentes com os valores recebidos.
    Ponto2D(double x, double y);

    //Também deve possuir um construtor default, que inicializa x e y com zero.
    Ponto2D();

    double calcular_distancia (Ponto2D ponto);

    double MeuX();
    double MeuY();
    void movendo_x_e_y(double dx, double dy);
};

#endif