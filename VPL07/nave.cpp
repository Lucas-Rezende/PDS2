#include "nave.h"
#include "ponto.h"

#include <iostream>

using namespace std;

Nave::Nave() {
    _energia = 100;
    _posicao = Ponto2D();
    _forca = 1;
}

Nave::Nave(Ponto2D posicao, double forca) {
    _energia = 100;
    _posicao = posicao;
    _forca = forca;
}

void Nave::mover(double dx, double dy) {
    _posicao.movendo_x_e_y(dx, dy);
}

double Nave::calcular_distancia(Nave nave) {
    return _posicao.calcular_distancia(nave._posicao);
}

int Nave::determinar_indice_nave_mais_proxima(Nave naves[], int n) {
    int indice = -1;
    double distancia_minima = -1;

    for(int i = 0; i < n; i++) {
        if (naves[i]._energia <= 0) { // ignora naves destruídas
            continue;
        }

    double distancia_atual = calcular_distancia(naves[i]);

    if (distancia_atual != 0 && (distancia_minima == -1 || distancia_atual < distancia_minima))
        {
            indice = i;
            distancia_minima = distancia_atual;
        }
    }
    
    return indice;
}

void Nave::atacar(Nave naves[], int n) {
    int indiceNaveMaisProxima = determinar_indice_nave_mais_proxima(naves, n);

    if (indiceNaveMaisProxima == -1) {
        std::cout << "Nenhum alvo válido encontrado" << std::endl;
        return;
    }

    Nave& naveMaisProxima = naves[indiceNaveMaisProxima];
    double distancia = calcular_distancia(naveMaisProxima);
    double dano = (_forca * 100) / distancia;
    if (dano > 30) {
        dano = 30;
    }
    naveMaisProxima._energia -= dano;
    
    if (naveMaisProxima._energia <= 0) {
        naveMaisProxima._energia = -1; // marca nave destruída
        std::cout << "Nave destruída!" << std::endl;
    }
    else if (naveMaisProxima._energia <= 50) {
        std::cout << "Energia baixa!" << std::endl;
    }
}

void Nave::imprimir_status() {
    std::cout << _posicao.MeuX() << " " << _posicao.MeuY() << " " << _energia << std::endl;
}