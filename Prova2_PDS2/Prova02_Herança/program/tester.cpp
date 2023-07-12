#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "destinationpackages.h"
#include "overnightpackage.h"
#include "package.h"
#include "twodaypackage.h"

#include <string>

TEST_CASE("06 - Testando o construtor de OverNightPackage") {
    // Criando um pacote noturno com taxa adicional de 2, peso de 3 e custo por quilo de 5
    Package *p1 = new OverNightPackage(2, 3, 5, "Maria", "Rio");
    
    // Verificando se os parâmetros foram passados na ordem certa
    CHECK(p1->get_peso() == 2);
    CHECK(p1->get_custoporkilo() == 3);
    CHECK(p1->calculate_cost() == 16);
    
    delete p1;
}

TEST_CASE("07 - Testando o construtor de TwoDayPackage") {
    // Criando um pacote de dois dias com taxa fixa de 10, peso de 4 e custo por quilo de 6
    Package *p2 = new TwoDayPackage(10, 4, 6, "Paulo", "Juazeiro");
    
    CHECK(p2->get_peso() == 10);
    CHECK(p2->get_custoporkilo() == 4);
    CHECK(p2->calculate_cost() == 46);
    
    delete p2;
}

TEST_CASE("08 - Testando a inserção de pacotes duplicados") {
    Package* p1 = new Package(2, 5, "Josias", "Alfeneiros");
    Package* p2 = new Package(2, 5, "Josias", "Alfeneiros");

    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));

    CHECK(pacotes.custo_total("Josias") == 20);

    delete p1;
    delete p2;
}

TEST_CASE("09 - Testando a inserção de pacotes vazios") {
    Package* p1 = nullptr;

    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));

    CHECK(pacotes.custo_total() == 0);

    // Verifica se o custo total para um usuário é zero ao adicionar pacotes vazios
    CHECK(pacotes.custo_total("Josias") == 0);
}

TEST_CASE("10 - Testando a adição e cálculo de pacotes com custo zero") {
    Package *p1 = new Package(0, 5, "Josias", "Alfeneiros");
    Package *p2 = new Package(2, 0, "Carlos", "Alfeneiros");
    Package *p3 = new Package(0, 0, "Maria", "Alfeneiros");

    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));

    CHECK(pacotes.custo_total("Josias") == 0);
    CHECK(pacotes.custo_total("Carlos") == 0);
    CHECK(pacotes.custo_total("Maria") == 0);
    CHECK(pacotes.custo_total() == 0);

    delete p1;
    delete p2;
    delete p3;
}

TEST_CASE("11 - Testando cálculo de custo total para um usuário com pacotes de custo zero e outros pacotes") {
    Package *p1 = new Package(2, 5, "Josias", "Alfeneiros");
    Package *p2 = new Package(0, 0, "Josias", "Alfeneiros");
    Package *p3 = new Package(3, 4, "Josias", "Alfeneiros");

    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));

    CHECK(pacotes.custo_total("Josias") == 22);
    CHECK(pacotes.custo_total() == 22);

    delete p1;
    delete p2;
    delete p3;
}

TEST_CASE("12 - Testando o cálculo de custo total para um usuário não existente") {
    Package *p1 = new Package(2, 5, "Josias", "Alfeneiros");
    Package *p2 = new Package(5, 5, "Carlos", "Alfeneiros");
    Package *p3 = new Package(4, 5, "Maria", "Alfeneiros");

    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));

    // Verifica se o custo total para um usuário não existente é zero
    CHECK(pacotes.custo_total("Marcos") == 0);

    delete p1;
    delete p2;
    delete p3;
}

TEST_CASE("13 - Testando a inserção de pacotes com nomes e endereços especiais") {
    Package *p1 = new Package(2, 5, "Josias", "Rua 123, São Paulo");
    Package *p2 = new Package(3, 4, "Carlos", "Av. Principal, Rio de Janeiro");
    Package *p3 = new Package(4, 3, "Maria", "Praça Central, Brasília");

    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));

    // Verifica se os pacotes foram adicionados corretamente, mesmo com nomes e endereços especiais
    CHECK(pacotes.custo_total() == 34);

    delete p1;
    delete p2;
    delete p3;
}