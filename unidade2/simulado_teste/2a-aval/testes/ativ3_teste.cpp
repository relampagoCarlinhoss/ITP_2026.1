#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../code.cpp"
using namespace std;

// --- Testes ---
// Você pode definir novos testes, mas os existentes não podem ser alterados!
TEST_CASE("Calcula os acordes de uma progressão") {
  SequenciaAcordes prog1 = gerarProgressao("1-5-6-4", RE); // Let It Be em Ré
  SequenciaAcordes prog2 = gerarProgressao("1-4-5-4", MI); // Progressão comum em Mi
  SequenciaAcordes prog3 = gerarProgressao("2-5-1-6", SOL); // Progressão começando no 2o grau em Sol

  CHECK(prog1.num_acordes == 4);
  CHECK(prog1.acordes[0].num_notas == 3);
  CHECK(prog1.acordes[0].notas[0] == RE);
  CHECK(prog1.acordes[0].notas[1] == FA_SUSTENIDO);
  CHECK(prog1.acordes[0].notas[2] == LA);
  CHECK(prog1.acordes[1].num_notas == 3);
  CHECK(prog1.acordes[1].notas[0] == LA);
  CHECK(prog1.acordes[1].notas[1] == DO_SUSTENIDO);
  CHECK(prog1.acordes[1].notas[2] == MI);
  CHECK(prog1.acordes[2].num_notas == 3);
  CHECK(prog1.acordes[2].notas[0] == SI);
  CHECK(prog1.acordes[2].notas[1] == RE);
  CHECK(prog1.acordes[2].notas[2] == FA_SUSTENIDO);
  CHECK(prog1.acordes[3].num_notas == 3);
  CHECK(prog1.acordes[3].notas[0] == SOL);
  CHECK(prog1.acordes[3].notas[1] == SI);
  CHECK(prog1.acordes[3].notas[2] == RE);

  CHECK(prog2.num_acordes == 4);
  CHECK(prog2.acordes[0].num_notas == 3);
  CHECK(prog2.acordes[0].notas[0] == MI);
  CHECK(prog2.acordes[0].notas[1] == SOL_SUSTENIDO);
  CHECK(prog2.acordes[0].notas[2] == SI);
  CHECK(prog2.acordes[1].num_notas == 3);
  CHECK(prog2.acordes[1].notas[0] == LA);
  CHECK(prog2.acordes[1].notas[1] == DO_SUSTENIDO);
  CHECK(prog2.acordes[1].notas[2] == MI);
  CHECK(prog2.acordes[2].num_notas == 3);
  CHECK(prog2.acordes[2].notas[0] == SI);
  CHECK(prog2.acordes[2].notas[1] == RE_SUSTENIDO);
  CHECK(prog2.acordes[2].notas[2] == FA_SUSTENIDO);
  CHECK(prog2.acordes[3].num_notas == 3);
  CHECK(prog2.acordes[3].notas[0] == LA);
  CHECK(prog2.acordes[3].notas[1] == DO_SUSTENIDO);
  CHECK(prog2.acordes[3].notas[2] == MI);

  CHECK(prog3.num_acordes == 4);
  CHECK(prog3.acordes[0].num_notas == 3);
  CHECK(prog3.acordes[0].notas[0] == LA);
  CHECK(prog3.acordes[0].notas[1] == DO);
  CHECK(prog3.acordes[0].notas[2] == MI);
  CHECK(prog3.acordes[1].num_notas == 3);
  CHECK(prog3.acordes[1].notas[0] == RE);
  CHECK(prog3.acordes[1].notas[1] == FA_SUSTENIDO);
  CHECK(prog3.acordes[1].notas[2] == LA);
  CHECK(prog3.acordes[2].num_notas == 3);
  CHECK(prog3.acordes[2].notas[0] == SOL);
  CHECK(prog3.acordes[2].notas[1] == SI);
  CHECK(prog3.acordes[2].notas[2] == RE);
  CHECK(prog3.acordes[3].num_notas == 3);
  CHECK(prog3.acordes[3].notas[0] == MI);
  CHECK(prog3.acordes[3].notas[1] == SOL);
  CHECK(prog3.acordes[3].notas[2] == SI);
}