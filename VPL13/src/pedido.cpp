#include "../include/pedido.hpp"

Pedido::~Pedido()
{
    // TODO: Implemente este metodo.
    /**
     * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
     * Explicação de como:
     * 1) Sendo uma lista, precisamos percorrer a mesma
     * 2) Deleta cada ponteiro da lista
     */
    for (Produto* p : m_produtos)
    {
        delete p;
    }
}

void Pedido::setEndereco(const std::string &endereco)
{
    // TODO: Implemente este metodo.
    m_endereco = endereco;
}

float Pedido::calculaTotal() const
{
    float total = 0.0f;
    for (Produto* p : m_produtos)
    {
        total += p->getValor();
    }
    return total;
}

void Pedido::adicionaProduto(Produto *p)
{
    // TODO: Implemente este metodo.
    m_produtos.push_back(p);
}

std::string Pedido::resumo() const
{
    // TODO: Implemente este metodo.
    /**
     * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
     * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
     * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
     *
     */
    std::string resumo;
    for (Produto* p : m_produtos)
    {
        resumo += p->descricao() + "\n";
    }
    resumo += "Endereco: " + m_endereco;
    return resumo;
}