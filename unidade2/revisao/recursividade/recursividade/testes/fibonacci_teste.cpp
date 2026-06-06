#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../funcoes_recursivas.cpp"

TEST_CASE("Testando a função para calcular o n-ésimo número de Fibonacci.") {
  CHECK(fibonacci_recursivo(0) == 0);
  CHECK(fibonacci_recursivo(1) == 1);
  CHECK(fibonacci_recursivo(2) == 1);
  CHECK(fibonacci_recursivo(5) == 5);
  CHECK(fibonacci_recursivo(8) == 21);
  CHECK(fibonacci_recursivo(10) == 55);
};
