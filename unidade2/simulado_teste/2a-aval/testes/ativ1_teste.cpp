#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../code.cpp"
using namespace std;

// --- Testes ---
// Você pode definir novos testes, mas os existentes não podem ser alterados!
TEST_CASE("Testa se um acorde é maior") {
  Acorde acorde1 = {3, {DO, MI, SOL}}; // Dó maior (tem 3 notas: Dó, Mi e Sol)
  Acorde acorde2 = {3, {RE, FA_SUSTENIDO, LA}}; // Ré maior (tem 3 notas: Ré, Fá# e Lá)
  Acorde acorde3 = {3, {MI, SOL, SI}}; // Mi menor (tem 3 notas: Mi, Sol e Si)
  Acorde acorde4 = {3, {FA, LA, DO_SUSTENIDO}}; // Fá aumentado (tem 3 notas: Fá, Lá e Dó#)
  Acorde acorde5 = {3, {SOL, SI, RE}}; // Sol maior (tem 3 notas: Sol, Si e Ré)
  Acorde acorde6 = {4, {SOL, SI, RE, FA}}; // Sol maior com 7a (tem 4 notas: Sol, Si, Ré e Fá)
  Acorde acorde7 = {5, {SOL, SI, RE, FA, LA}}; // Sol maior com 7a e 9a (tem 5 notas: Sol, Si, Ré, Fá e Lá)
  Acorde acorde8 = {3, {LA, DO, MI}}; // Lá menor (tem 3 notas: Lá, Dó e Mi)
  Acorde acorde9 = {3, {DO, FA, SOL}}; // Dó suspenso (tem 3 notas: Dó, Fá e Sol)

  CHECK(isMaior(acorde1) == true);
  CHECK(isMaior(acorde2) == true);
  CHECK(isMaior(acorde3) == false);
  CHECK(isMaior(acorde4) == false);
  CHECK(isMaior(acorde5) == true);
  CHECK(isMaior(acorde6) == false);
  CHECK(isMaior(acorde7) == false);
  CHECK(isMaior(acorde8) == false);
  CHECK(isMaior(acorde9) == false);
}