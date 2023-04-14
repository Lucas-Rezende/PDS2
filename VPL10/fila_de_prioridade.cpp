#include "fila_de_prioridade.h"

#include <iostream>

// Define como cada nó da lista encadeada é implementado.
struct No
{
    int prioridade;
    string elemento;
    No *proximo;
};

FilaDePrioridade::FilaDePrioridade()
{
    //
    tamanho_ = 0;
    primeiro_ = nullptr;
}

string FilaDePrioridade::primeiro() const
{
    return primeiro_->elemento;
}

int FilaDePrioridade::tamanho() const
{
    return tamanho_;
}

bool FilaDePrioridade::vazia() const
{
    return tamanho_ == 0;
}

void FilaDePrioridade::RemoverPrimeiro()
{
    if (tamanho_ == 0)
    {
        throw "Erro: Fila vazia";
    }
    No *antigoPrimeiro = primeiro_;
    primeiro_ = primeiro_->proximo;
    delete antigoPrimeiro;
    tamanho_--;
}

void FilaDePrioridade::Inserir(int p, string s)
{
    //prioridade | idade
    //elemento | nome
    No *novoNo = new No;
    novoNo->prioridade = p;
    novoNo->elemento = s;
    if (vazia())
    {
        novoNo->proximo = nullptr;
        primeiro_ = novoNo;
    }
    else
    {
        std::cout << "não está mais vazio" << std::endl;
        No *anterior = nullptr;
        No *atual = primeiro_;
        while (atual != nullptr && p <= atual->prioridade)
        {
            anterior = atual;
            atual = atual->proximo;
        }
        if (anterior == nullptr)
        {
            novoNo->proximo = primeiro_;
            primeiro_ = novoNo;
        }
        else
        {
            anterior->proximo = novoNo;
            novoNo->proximo = atual;
        }
    }
    tamanho_++;
}

void FilaDePrioridade::Limpar()
{
    while (!vazia())
    {
        RemoverPrimeiro();
    }
}