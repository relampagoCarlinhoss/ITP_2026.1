#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "elevador.cpp"

TEST_CASE("Controle de Elevador") {
Elevador elevador(3, 4); // capacidade de 3 pessoas e 4 andares
CHECK(elevador.consultaAndarAtual() == 0);
CHECK(elevador.consultaNumPessoas() == 0);
CHECK(elevador.entra() == true); // uma pessoa entrou
CHECK(elevador.entra() == true);
CHECK(elevador.consultaNumPessoas() == 2);
CHECK(elevador.entra() == true);
CHECK(elevador.entra() == false); // a capacidade foi atingida
CHECK(elevador.consultaNumPessoas() == 3);
CHECK(elevador.sobe() == true);
CHECK(elevador.consultaAndarAtual() == 1);
CHECK(elevador.desce() == true);
CHECK(elevador.consultaAndarAtual() == 0);
CHECK(elevador.desce() == false); // já está no térreo
CHECK(elevador.sai() == true);
CHECK(elevador.consultaNumPessoas() == 2);
CHECK(elevador.sai() == true);
CHECK(elevador.sai() == true);
CHECK(elevador.sai() == false); 
}