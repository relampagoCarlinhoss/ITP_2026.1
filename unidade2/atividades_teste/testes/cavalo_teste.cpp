#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../lib/cavalo.cpp"

TEST_CASE("Verificando possíveis movimentos válidos.") {
  CHECK(is_valid_knight_move("c2", "d4") == true);
  CHECK(is_valid_knight_move("d2", "b3") == true);
  CHECK(is_valid_knight_move("h8", "g6") == true);
  CHECK(is_valid_knight_move("e4", "f6") == true);
};

TEST_CASE("Verificando movimentos inválidos.") {
  CHECK(is_valid_knight_move("c2", "c4") == false);
  CHECK(is_valid_knight_move("a3", "b2") == false);
  CHECK(is_valid_knight_move("h8", "h6") == false);
  CHECK(is_valid_knight_move("e4", "g1") == false);
};
