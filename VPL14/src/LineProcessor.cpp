#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

#include "LineProcessor.hpp"

enum Meses {
    JAN,
    FEV,
    MAR,
    ABR,
    MAI,
    JUN,
    JUL,
    AGO,
    SET,
    OUT,
    NOV,
    DEZ
};

void LinePrinter::processaLinha(const std::string &str)
{
    std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const
{
    // Neste exemplo usaremos expressoes regulares para verificar se uma linha
    // eh valida ou nao.
    //
    // Esta expressao regular eh formada por cinco partes. Cada uma dessas
    // partes eh um dos tres tipos de padrao regular abaixo:
    //
    // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
    // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
    // \\d+ eh qualquer sequencia de um ou mais digitos
    std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

    // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
    // a expressao regular que acabamos de criar:
    return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str)
{
    //
    // Em geral eh mais facil ler dados de uma string se a string eh transformada
    // em um objeto do tipo stringstream:
    std::stringstream ss(str);
    //
    // Iremos ler os dados da string nestas tres variaveis abaixo:
    std::string nomePais;
    unsigned populacao, percUrbana;
    //
    // Como sabemos que a linha contem string int int, podemos fazer a leitura
    // facilmente usando o operador de streaming:
    ss >> nomePais >> populacao >> percUrbana;
    //
    // Note que precisamos arredondar o valor que serah impresso. O arredondamento
    // serah feito via a funcao floor. Ou seja, decimais serao sempre
    // arredondados para baixo:
    unsigned popRural = floor(populacao - (populacao * (percUrbana / 100.0)));
    //
    // Uma vez encontrados os valores que precisam ser impressos, seguimos o
    // modelo do enunciado do exercicio:
    std::cout << popRural << " pessoas vivem no campo no " << nomePais << std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const
{
    // TODO: Implemente este metodo

    // verifico com regex se há apenas números naturais e espaços
    std::regex padrao("^[0-9 ]*$");
    return std::regex_match(str, padrao);
}

void ContadorNumNaturais::processaLinha(const std::string &str)
{
    if (!linhaValida(str))
    {
        std::cout << "Linha inválida: " << str << std::endl;
        return;
    }

    // TODO: Implemente este metodo:
    std::istringstream iss(str);
    unsigned int num;
    unsigned int somalinha = 0;

    while (iss >> num)
    {
        somalinha += num;
    }

    std::cout << somalinha << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const
{
    // TODO: Implemente este metodo
    std::regex padrao("^\\s*[a-zA-Z]+\\s+[0-9]+\\s+[a-zA-Z]+\\s+[0-9]+\\s*$");
    return std::regex_match(str, padrao);
}

void LeitorDeFutebol::processaLinha(const std::string &str)
{
    // TODO: Implemente este metodo:
    std::string time1;
    unsigned int gols1;
    std::string time2;
    unsigned int gols2;

    if (linhaValida(str) == true)
    {
        std::istringstream info(str);
        info >> time1 >> gols1 >> time2 >> gols2;
    }

    if (gols1 == gols2)
    {
        std::cout << "Empate" << std::endl;
    }
    if (gols1 > gols2)
    {
        std::cout << "Vencedor: " << time1 << std::endl;
    }
    if (gols1 < gols2)
    {
        std::cout << "Vencedor: " << time2 << std::endl;
    }
}

void ContadorDePalavras::processaLinha(const std::string &str)
{
    // TODO: Implemente este metodo:)
    std::string check;
    unsigned int count = 0;
    std::istringstream info(str);
    while (info >> check)
    {
        count++;
    }

    std::cout << count << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const
{
    std::regex padrao("^[a-zA-Z ]*$");
    return std::regex_match(str, padrao);
}

void InversorDeFrases::processaLinha(const std::string &str)
{
    // TODO: Implemente este metodo:
    if (!linhaValida(str))
    {
        std::cout << "Linha inválida: " << str << std::endl;
        return;
    }

    std::vector<std::string> palavras;
    std::istringstream info(str);
    std::string palavra;
    std::string reverse_str;

    while (info >> palavra)
    {
        palavras.push_back(palavra);
    }

    for (auto it = palavras.rbegin(); it != palavras.rend(); it++)
    {
        reverse_str += *it;
        reverse_str += " ";
    }

    std::cout << reverse_str << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const
{
    std::regex padrao("\\s*\\d{1,2}/\\d{1,2}/\\d{4}\\s*");
    // TODO: Implemente este metodo
    // Note que você pode usar uma expressao regular como:
    // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
    return std::regex_match(str, padrao);
}

void EscritorDeDatas::processaLinha(const std::string &str)
{
    if (!linhaValida(str))
    {
        std::cout << "Linha inválida: " << str << std::endl;
        return;
    }

    std::istringstream info(str);
    std::string data;
    std::string dia;
    std::string mes;
    std::string ano;

    std::getline(info, data);

    std::istringstream dataStream(data);

    std::getline(dataStream, dia, '/');
    std::getline(dataStream, mes, '/');
    std::getline(dataStream, ano);

    std::string iniciaisMes;

    if (mes == "1" || mes == "01")
        iniciaisMes = "Jan";
    else if (mes == "2" || mes == "02")
        iniciaisMes = "Fev";
    else if (mes == "3" || mes == "03")
        iniciaisMes = "Mar";
    else if (mes == "4" || mes == "04")
        iniciaisMes = "Abr";
    else if (mes == "5" || mes == "05")
        iniciaisMes = "Mai";
    else if (mes == "6" || mes == "06")
        iniciaisMes = "Jun";
    else if (mes == "7" || mes == "07")
        iniciaisMes = "Jul";
    else if (mes == "8" || mes == "08")
        iniciaisMes = "Ago";
    else if (mes == "9" || mes == "09")
        iniciaisMes = "Set";
    else if (mes == "10")
        iniciaisMes = "Out";
    else if (mes == "11")
        iniciaisMes = "Nov";
    else if (mes == "12")
        iniciaisMes = "Dez";
    else
    {
        std::cout << "Mês inválido: " << mes << std::endl;
        return;
    }

    std::cout << iniciaisMes << std::endl;
}