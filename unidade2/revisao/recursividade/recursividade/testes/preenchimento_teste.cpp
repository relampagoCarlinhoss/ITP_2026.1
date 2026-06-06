#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../funcoes_recursivas.cpp"

TEST_CASE("Testando a imagem com uma única cor: deve virar nova_cor completamente.") {
  char imagem[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      imagem[i][j] = 'A';
    }
  }
  preenchimento_recursivo(imagem, 'B');
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      CHECK(imagem[i][j] == 'B');
    }
  }
}

TEST_CASE("Testando com uma região isolada, que não deve ser alterada.") {
  char imagem[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (i >= 4 && i <= 6 && j >= 4 && j <= 6) {
        imagem[i][j] = 'B';  // região com cor B no centro
      } else {
        imagem[i][j] = 'A';  // os demais pontos (ao redor de B) tem a cor A
      }
    }
  }
  preenchimento_recursivo(imagem, 'C');
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (i >= 4 && i <= 6 && j >= 4 && j <= 6) {
        CHECK(imagem[i][j] == 'B');  // verifica que essa região não mudou
      } else {
        CHECK(imagem[i][j] == 'C');  // mas essa mudou para C
      }
    }
  }
}

TEST_CASE("Testando com uma imagem específica.") {
  char imagem[10][10] = {
    { 'A', 'A', 'A', 'A', 'B', 'B', 'A', 'A', 'A', 'A' },
    { 'A', 'A', 'A', 'A', 'A', 'B', 'A', 'A', 'A', 'A' },
    { 'A', 'B', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A' },
    { 'A', 'B', 'A', 'B', 'B', 'B', 'A', 'A', 'B', 'B' },
    { 'A', 'A', 'A', 'B', 'C', 'C', 'C', 'C', 'C', 'C' },
    { 'A', 'A', 'A', 'B', 'C', '#', '#', '#', '#', '#' },
    { 'A', 'B', 'A', 'B', 'C', '#', 'D', 'D', 'D', 'D' },
    { 'A',' B',' A',' B',' C', '#', 'D', 'E', 'E', 'E' },
    { 'A',' A',' A',' B',' C', '#', 'D', 'E', 'E', 'E' },
    { 'A',' A',' A',' B',' C', '#', 'D', 'E', 'E', 'E' }
  };
  // depois do preenchimento, as linhas de 0 a 3 e as colunas de 0 a 3 devem estar
  // preenchidas com 'B', mas o restante da imagem deve permanecer inalterado

  // cria um clone da imagem original para comparar depois do preenchimento
  char clone[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      clone[i][j] = imagem[i][j];
    }
  }

  preenchimento_recursivo(imagem, 'B');
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (i <= 3 && j <= 3) {
        CHECK(imagem[i][j] == 'B');
      } else {
        CHECK(imagem[i][j] == clone[i][j]);
      }
    }
  }
};
