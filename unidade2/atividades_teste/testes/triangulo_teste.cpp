#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../lib/triangulo.cpp"

TEST_CASE("Verificando quando as dimensões não formam triângulo.") {
  CHECK(triangle_type(-1.0, 3.2, 2.4) == 0); // não pode ter dimensão negativa
  CHECK(triangle_type(5.0, 3.1, 0.0) == 0); // ... nem nula
  CHECK(triangle_type(8.1, 3.1, 3.1) == 0);
  CHECK(triangle_type(1.1, 4.5, 2.7) == 0);
};

TEST_CASE("Verificando quando o triângulo é escaleno.") {
  CHECK(triangle_type(3.2, 4.9, 4.1) == 1);
  CHECK(triangle_type(5.0, 3.1, 2.0) == 1);
  CHECK(triangle_type(5.0, 3.1, 3.2) == 1);
};

TEST_CASE("Verificando quando o triângulo é isósceles.") {
  CHECK(triangle_type(3.2, 3.2, 4.1) == 2);
  CHECK(triangle_type(5.0, 3.2, 3.2) == 2);
  CHECK(triangle_type(3.2, 3.1, 3.2) == 2);
};


TEST_CASE("Verificando quando o triângulo é equilátero.") {
  CHECK(triangle_type(10.5, 10.5, 10.5) == 3);
  CHECK(triangle_type(6, 6, 6) == 3);
};