#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../funcoes_recursivas.cpp"

TEST_CASE("Testando um labirinto completamente aberto.") {
  char labirinto[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      labirinto[i][j] = ' ';
    }
  }
  // No labirinto completamente aberto, deve haver um caminho para qualquer ponto
  // de início e saída.
  CHECK(labirinto_recursivo(labirinto, 0, 0, 9, 9) == true);
  CHECK(labirinto_recursivo(labirinto, 4, 5, 2, 3) == true);
  CHECK(labirinto_recursivo(labirinto, 8, 9, 1, 4) == true);
}

TEST_CASE("Testando um labirinto com parede vertical e horizontal.") {
  char labirinto[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (i == 4 || j == 4) {
        labirinto[i][j] = '#';  // parede na linha 4 ou na coluna 4
      } else {
        labirinto[i][j] = ' ';
      }
    }
  }
  // se o início e o destino estiverem em lados opostos da parede, não deve haver caminho
  CHECK(labirinto_recursivo(labirinto, 0, 0, 9, 9) == false);
  CHECK(labirinto_recursivo(labirinto, 0, 5, 9, 5) == false);

  // mas se estiverem do mesmo lado da parede, deve haver caminho
  CHECK(labirinto_recursivo(labirinto, 0, 0, 3, 3) == true);
  CHECK(labirinto_recursivo(labirinto, 5, 5, 9, 9) == true);
}

TEST_CASE("Testando quando o início e a saída se encontram no mesmo ponto.") {
  // Início e destino são o mesmo ponto
  char labirinto[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      labirinto[i][j] = ' ';
    }
  }
  CHECK(labirinto_recursivo(labirinto, 3, 3, 3, 3) == true);
  CHECK(labirinto_recursivo(labirinto, 2, 7, 2, 7) == true);
};

TEST_CASE("Testando um labirinto que precisa contornar as paredes.") {
  char labirinto[10][10] = {
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', '#', '#', '#', '#', '#', '#', '#', '#', ' ' },
    { ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ' },
    { ' ', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ' },
    { ' ', '#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ' },
    { ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#', ' ' },
    { ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ' },
    { ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ' },
    { ' ', '#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ' },
    { ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', ' ' }
  };
  CHECK(labirinto_recursivo(labirinto, 6, 6, 9, 9) == true);
  CHECK(labirinto_recursivo(labirinto, 8, 7, 9, 9) == false);
}

