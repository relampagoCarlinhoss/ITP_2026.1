#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../funcoes_recursivas.cpp"

TEST_CASE("Testando a função para contar ocorrências de um caractere em uma string.") {
  CHECK(conta_caractere_recursivo("hello", 'l') == 2);
  CHECK(conta_caractere_recursivo("hello", 'z') == 0);
  CHECK(conta_caractere_recursivo("", 'a') == 0);
  CHECK(conta_caractere_recursivo("aaa", 'a') == 3);
  CHECK(conta_caractere_recursivo("banana", 'a') == 3);
};
