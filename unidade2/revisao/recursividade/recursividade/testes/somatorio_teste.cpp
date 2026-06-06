#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../funcoes_recursivas.cpp"

TEST_CASE("Testando a função para calcular o somatório de um array.") {
  int arr1[] = {1, 2, 3, 4, 5};
  CHECK(somatorio_recursivo(arr1, 5) == 15);

  int arr2[] = {10};
  CHECK(somatorio_recursivo(arr2, 1) == 10);

  int arr3[] = {0, 0, 0};
  CHECK(somatorio_recursivo(arr3, 3) == 0);

  int arr4[] = {-1, 1, -1, 1};
  CHECK(somatorio_recursivo(arr4, 4) == 0);

  int arr5[] = {100, 200, 300};
  CHECK(somatorio_recursivo(arr5, 3) == 600);
};
