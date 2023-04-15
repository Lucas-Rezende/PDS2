#include "ponto.h"

#include <iostream>
#include <math.h>

using namespace std;

Ponto2D::Ponto2D() {
    _x = 0;
    _y= 0;
}

Ponto2D::Ponto2D(double x, double y) {
    _x = x;
    _y = y;
}

double Ponto2D::calcular_distancia(Ponto2D ponto) {
    //return (sqrt(pow(x2 - x1, 2)) + pow(y2 - y1, 2));
    return sqrt((pow(_x - ponto._x, 2)) + pow(_y - ponto._y, 2));
}

double Ponto2D::MeuX() {
    return _x;
}

double Ponto2D::MeuY() {
    return _y;
}

//Como não consigo acessar x e y no nave.cpp, criarei aqui um método que
//automaticamente mova x e y para mim;
void Ponto2D::movendo_x_e_y(double dx, double dy) {
    _x = _x + dx;
    _y = _y + dy;
}