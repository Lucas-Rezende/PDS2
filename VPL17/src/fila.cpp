#include "../include/fila.h"

struct No
{
    int chave;
    No *proximo;
};

Fila::Fila()
{
    // Construir fila vazia
    primeiro_ = nullptr;
    ultimo_ = nullptr;
}

void Fila::Inserir(int k)
{
    // Insere um elemento no fim da fila.
    // 1. Criar um novo ponteiro
    No* new_No = new No();

    // 2. Atribuir k em new_No
    new_No->chave = k;
    new_No->proximo = nullptr;

    if (primeiro_ == nullptr)
    {
        primeiro_ = new_No;
        ultimo_ = new_No;
    }
    else
    {
        ultimo_->proximo = new_No;
        ultimo_ = new_No;
    }
}

void Fila::RemoverPrimeiro()
{
    if (primeiro_ == nullptr)
    {
        throw ExcecaoFilaVazia();
    }
    else
    {
        No* temp = primeiro_;
        primeiro_ = primeiro_->proximo;
        delete temp;
        temp = nullptr;
    }
}

int Fila::primeiro() const
{
    if (primeiro_ == nullptr) {
        throw ExcecaoFilaVazia();
    } else {
        return primeiro_->chave;
    }
}

int Fila::ultimo() const
{
    if (ultimo_ == nullptr) {
        throw ExcecaoFilaVazia();
    } else {
        return ultimo_->chave;
    }
}

int Fila::tamanho() const
{
    int count = 0;
    No* atual = primeiro_;

    while (atual != nullptr) {
        count++;
        atual = atual->proximo;
    }

    return count;
}