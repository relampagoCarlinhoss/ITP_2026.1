#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../lib/intersecao.cpp"

TEST_CASE("Verificando quando há interseção entre as duas sequências.") {
  int a1[] = {1, 2, 3, 4, 5};
  int b1[] = {5, 6, 7, 8, 9};
  CHECK(has_intersection(5, a1, 5, b1) == true);

  int a3[] = {4, -10, 1, 2, 3};
  int b3[] = {0, -2, 3, 4, 15, 23, -9};
  CHECK(has_intersection(5, a3, 7, b3) == true);
};

TEST_CASE("Verificando quando não há interseção entre as duas sequências.") {
  int a1[] = {10, 20, 30};
  int b1[] = {40, 5, 9, -2, 0};
  CHECK(has_intersection(3, a1, 5, b1) == false);

  int a2[] = {11, 3};
  int b2[] = {42, 51, 6, 9, 18, 23, -9};
  CHECK(has_intersection(3, a2, 7, b2) == false);
};