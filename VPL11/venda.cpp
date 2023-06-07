#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <cctype>

std::string capitalizeFirstLetter(const std::string& str) {
    std::string result = str;
    if (!result.empty()) {
        result[0] = std::toupper(result[0]);
    }
    return result;
}

void Venda::adicionaCelular(const Celular& celular) {
    m_celulares.push_back(celular);
}

void Venda::ordena() {
    // TODO: Implemente este metodo
    // ordena a lista de celulares (utilizando a composição fabricante + modelo)
    m_celulares.sort([](const Celular& a, const Celular& b) {
        return a < b;
    });
}

void Venda::recarregaEstoque(int cod, int qtd) {
    for (auto& celular : m_celulares) {
        if (celular.getCodigo() == cod) {
            celular.setQtd(celular.getQtd() + qtd);
            return;  // Sai do método após encontrar o celular correspondente
        }
    }
    // Se nenhum celular com o código correspondente for encontrado
    std::cout << "Celular com código " << cod << " não encontrado no estoque." << std::endl;
}

void Venda::efetuaVenda(int cod, int qtd) {
    for (auto& celular : m_celulares) {
        if (celular.getCodigo() == cod) {
            if (qtd <= celular.getQtd()) {
                celular.setQtd(celular.getQtd() - qtd);
                std::cout << "Venda efetuada: " << qtd << " unidade(s) do celular código " << cod << std::endl;
            } else {
                std::cout << "Quantidade insuficiente em estoque para venda do celular código " << cod << std::endl;
            }
            return;
        }
    }
    std::cout << "Celular com código " << cod << " não encontrado no estoque." << std::endl;
}

void Venda::aplicaDesconto(const std::string& fabricante, float desconto) {
    for (Celular& celular : m_celulares) {
        if (celular.getFabricante() == fabricante) {
            float valorDesconto = celular.getValor() * desconto / 100.0;
            celular.setValor(celular.getValor() - valorDesconto);
        }
    }
}

void Venda::removeModelo(int cod) {
    m_celulares.remove_if([cod](const Celular& celular) {
        return celular.getCodigo() == cod;
    });
}

void Venda::imprimeEstoque() const {
    for (const Celular& celular : m_celulares) {
        if (celular.getQtd() > 0) {
            std::cout << celular.getFabricante();
            std::cout << " " << celular.getModelo();
            std::cout << ", " << celular.getArmazenamento() << "GB";
            std::cout << ", " << celular.getMemoria() << "GB RAM";
            std::cout << ", " << static_cast<int>(std::floor(celular.getPeso())) << " gramas";
            std::cout << ", " << capitalizeFirstLetter(celular.getCor());
            std::cout << ", " << celular.getQtd() << (celular.getQtd() > 1 ? " restantes" : " restante");
            std::cout << ", R$" << std::fixed << std::setprecision(2) << celular.getValor();
            std::cout << std::endl;
        }
    }
}