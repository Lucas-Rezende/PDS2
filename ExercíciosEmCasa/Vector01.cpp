// 1.Faça um TAD Banco que contém um vector de outro TAD Agencia
// 2. Faça um programa que lê um arquivo de texto e guarda as palavras em um vector e Imprima os elementos (um por linha)
// 3. Faça um programa que remove as palavras duplicadas do exercício anterior e mprima os elementos (um por linha)

#include <iostream>
#include <vector>
#include <fstream>

//questão 1
class Agencia
{

};

class Banco
{
private:
    std::vector<Agencia> agencias;
public:
};

int main() {
    //questão 2
    std::vector<std::string> words; 
    std::fstream arquivo;
    arquivo.open("file.dat");

    if (arquivo.is_open())
    {
        while (!arquivo.eof())
        {
            std::string palavra;
            while (arquivo >> palavra)
            {
                words.push_back(palavra);
            }
        }
    } else
    {
        std::cout << "Error opening file";
    }

    std::cout << "Com repetição: " << std::endl;
    for (int i = 0; i < words.size(); i++) {
        std::cout << words[i] << std::endl;
    }
    std::cout << std::endl;

    //questão 3
    std::cout << "Sem repetição: " << std::endl;
    for (int i = 0; i < words.size() - 1; i++) {
        if (words[i] == words[i+1])
        {
            words.erase(words.begin() + i);
        }
    }

    for (int i = 0; i < words.size(); i++) {
        std::cout << words[i] << std::endl;
    }
       
    arquivo.close();
    return 0;
}