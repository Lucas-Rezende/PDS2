#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "forma.h"
#include "forma2d.h"
#include "quadrado.h"
#include "triangulo.h"
#include "forma3d.h"
#include "cubo.h"
#include "esfera.h"
#include "circulo.h"

#include <string>
#include <math.h>

// ADIÇÕES DE TESTE
TEST_CASE("05 - Testando arestas do Triangulo")
{
    // testa alocação de arestas
    Triangulo triangulo("azul", 7, 5, 4);
    CHECK(triangulo.get_cor() == "azul");
    CHECK(triangulo.get_a1() == 7);
    CHECK(triangulo.get_a2() == 5);
    CHECK(triangulo.get_a3() == 4);
}

TEST_CASE("06 - Testando valores negativos no triângulo")
{
    // testando triangulo com valor negativo
    Triangulo triangulo1("azul", -7, 5, 4);
    CHECK_THROWS_AS(triangulo1.get_area(), TrianguloInvalidoException);
    CHECK_THROWS_AS(triangulo1.get_perimetro(), TrianguloInvalidoException);
}

TEST_CASE("07 - Testando triângulos inexistentes") 
{
    // testando triangulo inexistente
    Triangulo triangulo2("azul", 1, 5, 4);
    CHECK_THROWS_AS(triangulo2.get_area(), TrianguloInvalidoException);
    CHECK_THROWS_AS(triangulo2.get_perimetro(), TrianguloInvalidoException);
}

TEST_CASE("08 - Teste de cor do triângulo")
{
    Triangulo triangulo("vermelho", 6, 8, 10);
    CHECK(triangulo.get_cor() == "vermelho");
}

TEST_CASE("09 - Teste de nome do triângulo")
{
    Triangulo triangulo("azul", 6, 8, 10);
    CHECK(triangulo.get_nome() == "triangulo");
}

TEST_CASE("10 - Teste de área de triângulo válido")
{
    Triangulo triangulo("azul", 6, 8, 10);
    CHECK(triangulo.get_area() == 24);
}

TEST_CASE("11 - Teste de perímetro de triângulo válido")
{
    Triangulo triangulo("azul", 3, 4, 5);
    CHECK(triangulo.get_perimetro() == 12);
}

TEST_CASE("12 - Teste de área de quadrado válido") {
    Quadrado quadrado("vermelho", 5.0);
    CHECK(quadrado.get_area() == 25.0);
}

TEST_CASE("13 - Teste de perímetro de quadrado válido") {
    Quadrado quadrado("azul", 3.0);
    CHECK(quadrado.get_perimetro() == 12.0);
}

TEST_CASE("14 - Teste de cor do quadrado") {
    Quadrado quadrado("verde", 7.0);
    CHECK(quadrado.get_cor() == "verde");
}

TEST_CASE("15 - Teste de nome do quadrado") {
    Quadrado quadrado("amarelo", 4.0);
    CHECK(quadrado.get_nome() == "quadrado");
}

TEST_CASE("16 - Teste de destrutor do quadrado") {
    Quadrado* quadrado = new Quadrado("preto", 6.0);
    delete quadrado;
    CHECK(true);
}

TEST_CASE("17 - Teste de volume da esfera válido") {
    Esfera esfera("vermelho", 2.0);
    CHECK(esfera.get_volume() == doctest::Approx(33.5103).epsilon(0.001));
}

TEST_CASE("18 - Teste de cor da esfera") {
    Esfera esfera("azul", 3.0);
    CHECK(esfera.get_cor() == "azul");
}

TEST_CASE("19 - Teste de nome da esfera") {
    Esfera esfera("verde", 4.0);
    CHECK(esfera.get_nome() == "esfera");
}

TEST_CASE("20 - Teste de destrutor da esfera") {
    Esfera* esfera = new Esfera("preto", 5.0);
    delete esfera;
    CHECK(true);
}

TEST_CASE("21 - Teste de volume do cubo válido") {
    Cubo cubo("vermelho", 2.0);
    CHECK(cubo.get_volume() == doctest::Approx(8.0).epsilon(0.001));
}

TEST_CASE("22 - Teste de cor do cubo") {
    Cubo cubo("azul", 3.0);
    CHECK(cubo.get_cor() == "azul");
}

TEST_CASE("23 - Teste de nome do cubo") {
    Cubo cubo("verde", 4.0);
    CHECK(cubo.get_nome() == "cubo");
}

TEST_CASE("24 - Teste de destrutor do cubo") {
    Cubo* cubo = new Cubo("preto", 5.0);
    delete cubo;
    // Não há verificação específica a ser feita aqui, apenas garantimos que o destrutor não cause erros
    CHECK(true);
}

TEST_CASE("25 - Teste de área do círculo válido") {
    Circulo circulo("vermelho", 3.0);
    CHECK(circulo.get_area() == doctest::Approx(28.274).epsilon(0.001));
}

TEST_CASE("26 - Teste de perímetro do círculo") {
    Circulo circulo("azul", 4.0);
    CHECK(circulo.get_perimetro() == doctest::Approx(25.132).epsilon(0.001));
}

TEST_CASE("27 - Teste de cor do círculo") {
    Circulo circulo("verde", 5.0);
    CHECK(circulo.get_cor() == "verde");
}

TEST_CASE("28 - Teste de nome do círculo") {
    Circulo circulo("amarelo", 6.0);
    CHECK(circulo.get_nome() == "circulo");
}

TEST_CASE("29 - Teste de destrutor do círculo") {
    Circulo* circulo = new Circulo("preto", 7.0);
    delete circulo;
    CHECK(true);
}

TEST_CASE("30 - Teste Construtor - Quadrado Válido") {
    // Teste de criação de um quadrado válido
    CHECK_NOTHROW(Quadrado("vermelho", 5.0));
    CHECK_NOTHROW(Quadrado("azul", 7.5));
}

TEST_CASE("31 - Teste Construtor - Quadrado Inválido") {
    // Teste de criação de um quadrado inválido (tamanho do lado <= 0)
    CHECK_THROWS_AS(Quadrado("verde", 0.0), QuadradoInvalidoException);
    CHECK_THROWS_AS(Quadrado("amarelo", -2.5), QuadradoInvalidoException);
}

TEST_CASE("32 - Teste construtor Esfera - raio válido") {
    Esfera esfera("vermelho", 3.5);
    CHECK(esfera.get_volume() == doctest::Approx(179.5944));
}

TEST_CASE("33 - Teste construtor Esfera - raio inválido") {
    CHECK_THROWS_AS(Esfera("azul", -2.0), EsferaInvalidaException);
}

TEST_CASE("34 - Teste Construtor Cubo - Tamanho da aresta válido") {
    CHECK_NOTHROW(Cubo("vermelho", 5.0));
}

TEST_CASE("35 - Teste Construtor Cubo - Tamanho da aresta inválido") {
    CHECK_THROWS_AS(Cubo("vermelho", -2.0), CuboInvalidoException);
    CHECK_THROWS_AS(Cubo("azul", 0.0), CuboInvalidoException);
}

TEST_CASE("36 - Teste construtor circulo - raio válido") {
    Circulo c("vermelho", 5.0);
    
    CHECK(c.get_cor() == "vermelho");
    CHECK(c.get_nome() == "circulo");
    CHECK(c.get_area() == doctest::Approx(78.5398).epsilon(0.001));
    CHECK(c.get_perimetro() == doctest::Approx(31.4159).epsilon(0.001));
}

TEST_CASE("37 - Teste construtor circulo - raio inválido") {
    CHECK_THROWS_AS(Circulo("azul", -3.0), CirculoInvalidoException);
    CHECK_THROWS_AS(Circulo("verde", 0.0), CirculoInvalidoException);
}