#include "../include/venda.hpp"

#include <iomanip>

Venda::~Venda()
{
    // TODO: Implemente este metodo
    /**
     * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
     */
    for (Pedido* p : m_pedidos)
    {
        delete p;
    }
}

void Venda::adicionaPedido(Pedido *p)
{
    // TODO: Implemente este metodo
    m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const
{
    float totalVenda = 0.0;
    int quantidadePedidos = 0;

    for (Pedido* p : m_pedidos)
    {
        std::cout << "Pedido " << quantidadePedidos + 1 << "\n";
        std::cout << p->resumo() << "\n";

        totalVenda += p->calculaTotal(); // Somar ao totalVenda o valor do pedido atual
        quantidadePedidos++;
    }

    std::cout << "Relatorio de Vendas\n";
    std::cout << "Total de vendas: R$ " << std::fixed << std::setprecision(2) << totalVenda << "\n";
    std::cout << "Total de pedidos: " << quantidadePedidos << "\n";
}