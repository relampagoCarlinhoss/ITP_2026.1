#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../funcoes_recursivas.cpp"

TEST_CASE("Testando a função para calcular o fatorial.") {
  CHECK(fatorial_recursivo(0) == 1);
  CHECK(fatorial_recursivo(1) == 1);
  CHECK(fatorial_recursivo(5) == 120);
  CHECK(fatorial_recursivo(7) == 5040);
  CHECK(fatorial_recursivo(10) == 3628800);
};
