#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../funcoes_recursivas.cpp"

TEST_CASE("Testando a função para encontrar o maior valor em um array.") {
  int arr1[] = {1, 2, 3, 4, 5};
  CHECK(maior_valor_recursivo(arr1, 5) == 5);

  int arr2[] = {5, 4, 3, 2, 1};
  CHECK(maior_valor_recursivo(arr2, 5) == 5);

  int arr3[] = {3};
  CHECK(maior_valor_recursivo(arr3, 1) == 3);

  int arr4[] = {-1, -5, -3};
  CHECK(maior_valor_recursivo(arr4, 3) == -1);

  int arr5[] = {0, 20, 5, 15, -3, 0, 7, 8, 9, 4};
  CHECK(maior_valor_recursivo(arr5, 10) == 20);
};
