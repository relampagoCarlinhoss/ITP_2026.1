#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../lib/rainha.cpp"

TEST_CASE("Verificando possíveis movimentos na diagonal.") {
  CHECK(is_valid_queen_move("c2", "g6") == true);
  CHECK(is_valid_queen_move("a8", "h1") == true);
  CHECK(is_valid_queen_move("f4", "c7") == true);
};

TEST_CASE("Verificando possíveis movimentos na horinzontal.") {
  CHECK(is_valid_queen_move("a5", "f5") == true);
  CHECK(is_valid_queen_move("e3", "b3") == true);
  CHECK(is_valid_queen_move("h2", "c2") == true);
};

TEST_CASE("Verificando possíveis movimentos na vertical.") {
  CHECK(is_valid_queen_move("e7", "e4") == true);
  CHECK(is_valid_queen_move("b4", "b8") == true);
  CHECK(is_valid_queen_move("f4", "f3") == true);
};

TEST_CASE("Verificando movimentos inválidos.") {
  CHECK(is_valid_queen_move("b7", "c5") == false);
  CHECK(is_valid_queen_move("h2", "b3") == false);
  CHECK(is_valid_queen_move("h6", "d3") == false);
};
