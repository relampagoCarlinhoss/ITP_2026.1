#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../code.cpp"
using namespace std;

// --- Testes ---
// Você pode definir novos testes, mas os existentes não podem ser alterados!
TEST_CASE("Testa a mudança de tonalidade de uma sequência de acordes") {
  SequenciaAcordes p1 = {4, {
    {3, {DO, MI, SOL}}, // Dó maior
    {3, {SOL, SI, RE}}, // Sol maior
    {3, {LA, DO, MI}},  // Lá menor
    {3, {FA, LA, DO}}   // Fá maior
  }};
  SequenciaAcordes p2 = {3, {
    {3, {RE, FA, LA}}, // Ré menor
    {3, {LA, DO, MI}}, // Lá menor
    {3, {SI, RE, FA}}  // Si diminuto
  }};

  mudarTonalidade(p1, RE); // Muda para Ré maior
  CHECK(p1.num_acordes == 4);
  CHECK(p1.acordes[0].num_notas == 3);
  CHECK(p1.acordes[0].notas[0] == RE);
  CHECK(p1.acordes[0].notas[1] == FA_SUSTENIDO);
  CHECK(p1.acordes[0].notas[2] == LA);
  CHECK(p1.acordes[1].num_notas == 3);
  CHECK(p1.acordes[1].notas[0] == LA);
  CHECK(p1.acordes[1].notas[1] == DO_SUSTENIDO);
  CHECK(p1.acordes[1].notas[2] == MI);
  CHECK(p1.acordes[2].num_notas == 3);
  CHECK(p1.acordes[2].notas[0] == SI);
  CHECK(p1.acordes[2].notas[1] == RE);
  CHECK(p1.acordes[2].notas[2] == FA_SUSTENIDO);
  CHECK(p1.acordes[3].num_notas == 3);
  CHECK(p1.acordes[3].notas[0] == SOL);
  CHECK(p1.acordes[3].notas[1] == SI);
  CHECK(p1.acordes[3].notas[2] == RE);
  
  mudarTonalidade(p2, MI); // Muda para Mi maior
  CHECK(p2.num_acordes == 3);
  CHECK(p2.acordes[0].num_notas == 3);
  CHECK(p2.acordes[0].notas[0] == FA_SUSTENIDO);
  CHECK(p2.acordes[0].notas[1] == LA);
  CHECK(p2.acordes[0].notas[2] == DO_SUSTENIDO);
  CHECK(p2.acordes[1].num_notas == 3);
  CHECK(p2.acordes[1].notas[0] == DO_SUSTENIDO);
  CHECK(p2.acordes[1].notas[1] == MI);
  CHECK(p2.acordes[1].notas[2] == SOL_SUSTENIDO);
  CHECK(p2.acordes[2].num_notas == 3);
  CHECK(p2.acordes[2].notas[0] == RE_SUSTENIDO);
  CHECK(p2.acordes[2].notas[1] == FA_SUSTENIDO);
  CHECK(p2.acordes[2].notas[2] == LA);
}