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
    // TODO: Implemente este metodo
    /**
     * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
     * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
     * de pedidos processados.
     */
    float totalVenda = 0.0;
    int quantidadePedidos = 0;
    for (Pedido* p : m_pedidos)
    {
        std::cout << p->resumo() << "\n";
        totalVenda += p->calculaTotal();
        quantidadePedidos++;
    }

    std::cout << "Total de venda: " << totalVenda << "\n";
    std::cout << "Quantidade de pedidos processados: " << quantidadePedidos << "\n";
}