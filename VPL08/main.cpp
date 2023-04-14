#include <iostream>

int main(){
    // 1) Declare uma variável do tipo inteiro e atribua o valor '10'
    int var = 10;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int *dotvar = nullptr;

    // 3) Declare um vetor de inteiros e inicialize com valores de 9 a 0 (nessa ordem)
    int vet[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    std::cout << &var << std::endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    std::cout << var << std::endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    std::cout << &dotvar << std::endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    std::cout << dotvar << std::endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    std::cout << vet << std::endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    std::cout << &vet[0] << std::endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    std::cout << vet[0] << std::endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    dotvar = &var;

    // 12) Imprima o VALOR da variável declarada em (2)
    std::cout << dotvar << std::endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    std::cout << *dotvar << std::endl;

    // 14) Imprima o resultado da comparação do ENDEREÇO de (1) e do VALOR de (2)
    std::cout << (&var == dotvar) << std::endl;

    // 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *dotvar = 5;

    // 16) Imprima o VALOR da variável declarada em (1)
    std::cout << var << std::endl;

    // 17) Atribua o ENDEREÇO apontado pela variável (3) à variável declarada em (2)
    dotvar = vet;

    // 18) Imprima o VALOR da variável declarada em (2)
    std::cout << dotvar << std::endl;

    // 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    std::cout << *dotvar << std::endl;

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    dotvar = &vet[0];
    //ATRBUI AQUI A PRIMEIRA POSIÇÃO DE UM VETOR A UM PONTEIRO

    // 21) Imprima o VALOR da variável declarada em (2)
    std::cout << dotvar << std::endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    std::cout << *dotvar << std::endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for (int i = 0; i < 10; i++) {
        (*dotvar) = (*dotvar) * 10;
        dotvar++;
        //AQUI ESTOU PERCORRENDO O VETOR (3) ATRÁVES DO PONTEIRO, QUE
        //AUMENTA A CADA CHAMADA E PERCORRE O VETOR, MULTIPLICANDO CADA
        //POSIÇÃO APONTADA POR 10;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for (int i = 0; i < 10; i++) {
        std::cout << vet[i];
        if (i == 9) std::cout << std::endl;
        else std::cout << " ";
    }
    
    //std::cout << std::endl; 

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    for (int i : vet) {
        std::cout << i;
        if (i == vet[9]) std::cout << std::endl;
        if (i != vet[9]) std::cout << " ";
    }


    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    dotvar = &vet[0];
    for (int i = 0; i < 10; i++) {
        std::cout << *dotvar;
        if (i == 9) std::cout << std::endl;
        else std::cout << " ";
        dotvar++;
    }
    
    // 27) Atribua o ENDEREÇO da quinta posição de (3) à variável declarada em (2)
    dotvar = &vet[4];

    // 28) Imprima o VALOR da variável declarada em (2)
    std::cout << dotvar << std::endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    std::cout << *dotvar << std::endl;

    // 30) Imprima o VALOR guardado no: ENDEREÇO do ponteiro (2) decrementado de 4
    std::cout << *(dotvar - 4) << std::endl;

    // 31) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int ** PonteiroParaPonteiro = &dotvar;

    // 32) Imprima o VALOR da variável declarada em (31)
    std::cout << PonteiroParaPonteiro << std::endl;

    // 33) Imprima o ENDEREÇO da variável declarada em (31)
    std::cout << *PonteiroParaPonteiro << std::endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO apontado por (31)
    std::cout << &PonteiroParaPonteiro << std::endl;

    // 35) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (31)
    std::cout << **PonteiroParaPonteiro << std::endl;
    
    return 0;
}