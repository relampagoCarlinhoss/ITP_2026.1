#define  DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../cume.cpp"
using namespace std;
#include <string>
// defina os tipos e implemente sua função aqui


// --- Testes ---
// Você pode definir novos testes para a sua função aqui

// Mas esta parte não pode ser alterada!
TEST_CASE("Testa o caminho do Rei Gelado em vários terrenos") {
  Terreno t1 = {3, 3, {
    {5, 4, 3},
    {2, 1, 0},
    {3, 2, 1}
  }};

  CHECK(rumoAoTopo(t1, Posicao{1, 1}) == "CIMA-ESQUERDA-FIM");
  CHECK(rumoAoTopo(t1, Posicao{0, 0}) == "FIM");
  CHECK(rumoAoTopo(t1, Posicao{2, 2}) == "ESQUERDA-ESQUERDA-FIM");
  CHECK(rumoAoTopo(t1, Posicao{2, 0}) == "FIM");
  CHECK(rumoAoTopo(t1, Posicao{1, 2}) == "CIMA-ESQUERDA-ESQUERDA-FIM");

  Terreno t2 = {2, 2, {
    {0, 2},
    {3, 1}
  }};
  CHECK(rumoAoTopo(t2, Posicao{0, 0}) == "BAIXO-FIM");
  CHECK(rumoAoTopo(t2, Posicao{0, 1}) == "FIM");
  CHECK(rumoAoTopo(t2, Posicao{1, 0}) == "FIM");
  CHECK(rumoAoTopo(t2, Posicao{1, 1}) == "ESQUERDA-FIM");
}