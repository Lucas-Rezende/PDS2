#ifndef CELULAR_H
#define CELULAR_H

#include <string>
#include <iostream>

class Celular
{
private:
    std::string _modelo;
    std::string _fabricante;
    int _armazenamento;
    int _memoria;
    double _peso;
    std::string _cor;
    int _qtd;
    float _valor;
    int _codigo;
    static int _proximocodigo;

public:
    // construtor
    Celular(std::string modelo,
            std::string fabricante,
            int armazenamento,
            int memoria,
            double peso,
            std::string cor,
            int qtd,
            float valor);

    /**
     * @brief Implementa a sobrecarga do operador logico menor que ('<').
     * Utilizado na ordenacao dos objetos da classe.
     * Muda a configuração do sinal "<" durante o uso de Celular
     *
     * @param other Instancia de outro objeto da classe.
     * @return true Retorna true quando o objeto atual for 'menor' que o other
     * @return false Retorna false quando o objeto atual for 'maior' que o other
     */
    bool operator<(const Celular &other) const;

    std::string getModelo() const;
    std::string getFabricante() const;
    int getArmazenamento() const;
    int getMemoria() const;
    double getPeso() const;
    std::string getCor() const;
    int getQtd() const;
    float getValor() const;
    int getCodigo() const;

    void setQtd(int qtd);
    void setValor(float valor);
};

#endif