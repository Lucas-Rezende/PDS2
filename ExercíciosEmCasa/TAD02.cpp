#include <iostream>

class Fracao {
private:
    int _num;
    int _den;
public:
    Fracao(int numerador, int denominador) {
        _num = numerador;
        _den = denominador;
    }
    int soma(int esc) {
        return (_num/_den)+esc;
    }
    int soma(int n, int d) {
        return (_num/_den)+(n/d);
    }

    int sub(int esc) {
        return (_num/_den)-esc;
    }
    int sub(int n, int d) {
        return (_num/_den)-(n/d);
    }

    int mult(int esc) {
        return (_num/_den)*esc;
    }
    int mult(int n, int d) {
        return (_num/_den)*(n/d);
    }

    int div(int esc) {
        return (_num/_den)/esc;
    }
    int div(int n, int d) {
        return (_num/_den)/(n/d);
    }
};

int main() {
    int wtd, escalar, n, d, n1, d1;
    std::cout << "Insira o numerador: ";
    std::cin >> n;
    std::cout << "Insira o denominador: ";
    std::cin >> d;
    Fracao p(n, d);
    std::cout << "1. Somar fração com escalar" << std::endl <<
    "2. Somar fração com fração" << std::endl <<
    "3. Subtrair fração com escalar" << std::endl <<
    "4. Subtrair fração com fração" << std::endl <<
    "5. Multiplicar fração com escalar" << std::endl <<
    "6. Multiplicar fração com fração" << std::endl <<
    "7. Dividir fração com escalar" << std::endl <<
    "8. Dividir fração com fração" << std::endl << "9. Sair" << std::endl;
    
    std::cout << "O que você deseja fazer? ";
    std::cin >> wtd;
    switch (wtd)
    {
    case 1:
        std::cout << "Insira o escalar: ";
        std::cin >> escalar;
        std::cout << "Resposta: " << p.soma(escalar) << std::endl;
        break;

    case 2:
        std::cout << "Insira o numerador da nova fração: " << std::endl;
        std::cin >> n1;
        std::cout << "Insira o denominador da nova fração: " << std::endl;
        std::cin >> d1;
        std::cout << "Resposta: " << p.soma(n1, d1) << std::endl;
        break;

    case 3:
        std::cout << "Insira o escalar: ";
        std::cin >> escalar;
        std::cout << "Resposta: " << p.sub(escalar) << std::endl;
        break;

    case 4:
        std::cout << "Insira o numerador da nova fração: " << std::endl;
        std::cin >> n1;
        std::cout << "Insira o denominador da nova fração: " << std::endl;
        std::cin >> d1;
        std::cout << "Resposta: " << p.sub(n1, d1) << std::endl;
        break;

    case 5:
        std::cout << "Insira o escalar: ";
        std::cin >> escalar;
        std::cout << "Resposta: " << p.mult(escalar) << std::endl;
        break;

    case 6:
        std::cout << "Insira o numerador da nova fração: " << std::endl;
        std::cin >> n1;
        std::cout << "Insira o denominador da nova fração: " << std::endl;
        std::cin >> d1;
        std::cout << "Resposta: " << p.mult(n1, d1) << std::endl;
        break;

    case 7:
        std::cout << "Insira o escalar: ";
        std::cin >> escalar;
        std::cout << "Resposta: " << p.div(escalar) << std::endl;
        break;

    case 8:
        std::cout << "Insira o numerador da nova fração: " << std::endl;
        std::cin >> n1;
        std::cout << "Insira o denominador da nova fração: " << std::endl;
        std::cin >> d1;
        std::cout << "Resposta: " << p.div(n1, d1) << std::endl;
        break;
    
    case 9:
        break;
    }
}