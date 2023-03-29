#include <iostream>
#include <string>

class Conta
{
private:
    std::string _dono;
    unsigned int _saldo;

public:
    Conta(std::string dono)
    {
        _dono = dono;
        _saldo = 0;
        //unsigned int valor;
    }

    /* depositar/retirar dinheiro da conta */
    bool sacar(unsigned int valor)
    {
        if (valor > _saldo)
        {
            return false; // o saldo nunca deve ser negativo
        }
        else
        {
            _saldo -= valor;
            return true;
        }
    }

    void depositar(unsigned int valor)
    {
        _saldo += valor;
    }

    unsigned int get_saldo()
    {
        return _saldo;
    }
};

int main()
{
    unsigned int answer;
    unsigned int valor1;
    unsigned int deposito;
    std::string dono_check;

    std::cout << "Escolha um nome para a conta: ";
    std::cin >> dono_check;

    Conta conta1(dono_check);

    do
    {
        std::cout << "\nO que deseja fazer?" << std::endl;
        std::cout << "1. Sacar" << std::endl
                  << "2. Depositar" << std::endl
                  << "3. Ver saldo" << std:: endl
                  << "4. Sair" << std::endl;

        std::cin >> answer;

        switch (answer) {
            case 1:
                std::cout << "\nQuanto você quer sacar?" << std::endl;
                std::cin >> valor1;
                if (conta1.sacar(valor1) == false)
                {
                    std::cout << "\nVocê não tem saldo o suficiente, deposite mais" << std::endl;
                } else
                {
                    std::cout << "Saque concluído com sucesso" << std::endl;
                }
                break;

            case 2:
                std::cout << "\nQuanto você deseja depositar?  " << std::endl;
                std::cin >> deposito;
                conta1.depositar(deposito);
                std::cout << "Depósito concluído com sucesso" << std::endl;
                break;

            case 3:
                std::cout << "\nSeu saldo é: " << conta1.get_saldo() << std::endl << std::endl;
                break;
        }
    } while (answer != 4);
    
    return 0;
}