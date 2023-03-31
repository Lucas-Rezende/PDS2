#include <iostream>
#include <string>
#include <vector>

class Aluno {
  private:
    std::string _nome;
    int _matricula;
    std::vector<int> _materias;
  public:
    Aluno(std::string nome, int matricula) {
        _nome = nome;
        _matricula = matricula;
    }

    void realizar_matricula(int cod_disciplina) {
        _materias.push_back(cod_disciplina);
    }

    void print() {
        std::cout << "Nome: " << _nome << std::endl;
        std::cout << "Matrícula: " << _matricula <<std::endl;
        std::cout << "Matérias: ";
        for (int i : _materias) std::cout << i << " ";
    }
};

int main() {
    std::string name;
    int matr, mate, check;
    std::cout << "### Insira seus dados ###" << std::endl;
    std::cout << "Nome: ";
    std::getline(std::cin, name);
    std::cout << "Matricula: ";
    std::cin >> matr;
    std::vector<Aluno> a;
    a.push_back(Aluno(name, matr));

    while (check != 3)
    {
        std::cout << "\nO que deseja fazer agora?" << std::endl <<
        "1. Adicionar Materias" << std::endl <<
        "2. Ver seus dados e materias matriculadas" << std::endl <<
        "3. Sair" << std::endl;
        std::cin >> check;
        switch (check)
        {
        case 1:
            std::cout << "Digite o código da matéria: ";
            std::cin >> mate;
            a[0].realizar_matricula(mate);
            break;
        
        case 2:
            a[0].print();
        default:
            break;
        }
    }
    return 0;
}