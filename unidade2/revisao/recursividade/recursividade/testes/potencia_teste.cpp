#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../funcoes_recursivas.cpp"

TEST_CASE("Testando a função para calcular a potência.") {
  CHECK(potencia_recurvisa(2.0, 3) == doctest::Approx(8.0).epsilon(0.1));
  CHECK(potencia_recurvisa(5.0, 0) == doctest::Approx(1.0).epsilon(0.1));
  CHECK(potencia_recurvisa(3.0, 4) == doctest::Approx(81.0).epsilon(0.1));
  CHECK(potencia_recurvisa(2.5, 2) == doctest::Approx(6.25).epsilon(0.001));
  CHECK(potencia_recurvisa(10.7, 3) == doctest::Approx(1225.043).epsilon(0.001));
};
