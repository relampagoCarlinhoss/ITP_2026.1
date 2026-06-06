#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../funcoes_recursivas.cpp"

TEST_CASE("Testando a função para verificar se um número está em um array.") {
  int arr1[] = {1, 2, 3, 4, 5};
  CHECK(contem_recursivo(arr1, 5, 3) == true);
  CHECK(contem_recursivo(arr1, 5, 6) == false);

  int arr2[] = {10};
  CHECK(contem_recursivo(arr2, 1, 10) == true);
  CHECK(contem_recursivo(arr2, 1, 5) == false);

  int arr3[] = {-1, 0, 1};
  CHECK(contem_recursivo(arr3, 3, 0) == true);
  CHECK(contem_recursivo(arr3, 3, -5) == false);
};
