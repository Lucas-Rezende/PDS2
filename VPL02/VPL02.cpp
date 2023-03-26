#include <iostream>
#include <string>

class CountVowels
{
private:
    std::string _w;
    unsigned int _a, _e, _i, _o, _u;

public:
    CountVowels(std::string word)
    {
        _w = word;
        _a = 0;
        _e = 0;
        _i = 0;
        _o = 0;
        _u = 0;
    }

    unsigned int CountA () {
        unsigned int qntA = 0;
        for (int i = 0; i < _w.length(); i++)
        {
            if (_w[i] == 'a')
            {
                qntA++;
            }          
        }
        return qntA;
    }

    unsigned int CountE () {
        unsigned int qntE = 0;
        for (int i = 0; i < _w.length(); i++)
        {
            if (_w[i] == 'e')
            {
                qntE++;
            }          
        }
        return qntE;
    }

    unsigned int CountI () {
        unsigned int qntI = 0;
        for (int i = 0; i < _w.length(); i++)
        {
            if (_w[i] == 'i')
            {
                qntI++;
            }          
        }
        return qntI;
    }

    unsigned int CountO () {
        unsigned int qntO = 0;
        for (int i = 0; i < _w.length(); i++)
        {
            if (_w[i] == 'o')
            {
                qntO++;
            }          
        }
        return qntO;
    }

    unsigned int CountU () {
        unsigned int qntU = 0;
        for (int i = 0; i < _w.length(); i++)
        {
            if (_w[i] == 'u')
            {
                qntU++;
            }          
        }
        return qntU;
    }
};

int main()
{
    std::string w;
    std::cout << "Insert a word: ";
    std::cin >> w;

    CountVowels count1(w);

    if (count1.CountA() > 0)
    {
        std::cout << "a " << count1.CountA() << std::endl;
    } else {
        ;
    }

    if (count1.CountE() > 0)
    {
        std::cout << "e " << count1.CountE() << std::endl;
    } else {
        ;
    }

    if (count1.CountI() > 0)
    {
        std::cout << "i " << count1.CountI() << std::endl;
    } else {
        ;
    }

    if (count1.CountO() > 0)
    {
        std::cout << "o " << count1.CountO() << std::endl;
    } else {
        ;
    }

    if (count1.CountU() > 0)
    {
        std::cout << "u " << count1.CountU() << std::endl;
    } else {
        ;
    }
    return 0;
}