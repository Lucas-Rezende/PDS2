#include <iostream>
#include <iterator>
#include <vector>

#include "ListaProcessos.hpp"
#include "Processo.hpp"

using namespace std;

unsigned int ListaProcessos::local_add(unsigned int prioridade) {
    unsigned int i;
    for (i = 0; i < processos.size(); i++)
    {
        if (prioridade > processos[i].MinhaPrioridade())
        {
            break;
        }
    }
    return i;
}
void ListaProcessos::adicionar_processo(Processo proc)
{
    //push_back(proc) não funciona pois adiciona ao final
    //portanto, cria-se um iterador, visto que o mesmo aponta para
    //um elemento dentro de um contêiner, permitindo acessar seus
    //valores

    //criando um iterador que percorre um vetor do tipo Processo
    std::vector<Processo>::iterator iterando;

    //agora, preciso saber em qual posição vou adicionar o novo
    //processo, fazendo assim uso do método MinhaPrioridade()
    unsigned int onde = local_add(proc.MinhaPrioridade());

    //essa linha dirá ao iterador onde, partindo do começo do vetor, onde
    //deve-se adicionar o processo
    iterando = processos.begin() + onde;

    processos.insert(iterando, proc);
}
Processo ListaProcessos::remover(int x) {
    Processo a = processos[x];
    processos.erase(processos.begin() + x);
    return a;
}
Processo ListaProcessos::remover_processo_maior_prioridade()
{
    return remover(0);
}
Processo ListaProcessos::remover_processo_menor_prioridade()
{
    int size = processos.size() - 1;
    return remover(size);
}
Processo ListaProcessos::remover_processo_por_id(unsigned int id)
{
    unsigned int i = 0;
    int x = 0;
    //esse while atravessa o vetor enquanto o id dado por i integrante do vetor
    //processo for diferente do id que foi inserido pelo usuário
    while (i < processos.size() && processos[i].MeuID() != id) {
        i++;
    }
    if (i < processos.size()) {
        x = i;
    }
    return remover(x);
}
void ListaProcessos::imprimir_lista()
{
    for (Processo proc : processos) {
        proc.imprimir_dados();
    }
}