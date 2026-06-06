#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../funcoes_recursivas.cpp"

TEST_CASE("Testando a função para calcular o MDC.") {
  CHECK(mdc_recursivo(12, 8) == 4);
  CHECK(mdc_recursivo(15, 5) == 5);
  CHECK(mdc_recursivo(7, 13) == 1);
  CHECK(mdc_recursivo(100, 75) == 25);
  CHECK(mdc_recursivo(36, 48) == 12);
};
