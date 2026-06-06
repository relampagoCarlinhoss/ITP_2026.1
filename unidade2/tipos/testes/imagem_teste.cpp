#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../imagem.cpp"


TEST_CASE("Testar deslocar_figura com deslocamento positivo") {
  Figura figura = {
    {{1, 1}, {3, 2}, {2, 4}},
    3
  };
  deslocar_figura(figura, 2, 3);

  CHECK(figura.pontos[0].x == 3);
  CHECK(figura.pontos[0].y == 4);
  CHECK(figura.pontos[1].x == 5);
  CHECK(figura.pontos[1].y == 5);
  CHECK(figura.pontos[2].x == 4);
  CHECK(figura.pontos[2].y == 7);
}

TEST_CASE("Testar deslocar_figura com deslocamento negativo") {
  Figura figura = {
    {{2, 3}, {0, -1}, {-4, 5}},
    3
  };
  deslocar_figura(figura, -3, -2);

  CHECK(figura.pontos[0].x == -1);
  CHECK(figura.pontos[0].y == 1);
  CHECK(figura.pontos[1].x == -3);
  CHECK(figura.pontos[1].y == -3);
  CHECK(figura.pontos[2].x == -7);
  CHECK(figura.pontos[2].y == 3);
}

TEST_CASE("Testar caixa_envoltoria com coordenadas positivas") {
  Figura figura = {
    {{1, 1}, {4, 2}, {3, 6}, {2, 5}},
    4
  };

  Retangulo caixa = caixa_envoltoria(figura);
  CHECK(caixa.superior_esquerda.x == 1);
  CHECK(caixa.superior_esquerda.y == 6);
  CHECK(caixa.inferior_direita.x == 4);
  CHECK(caixa.inferior_direita.y == 1);
}

TEST_CASE("Testar caixa_envoltoria com coordenadas negativas") {
  Figura figura = {
    {{-2, -1}, {-5, 3}, {0, 2}, {-1, -4}},
    4
  };

  Retangulo caixa = caixa_envoltoria(figura);
  CHECK(caixa.superior_esquerda.x == -5);
  CHECK(caixa.superior_esquerda.y == 3);
  CHECK(caixa.inferior_direita.x == 0);
  CHECK(caixa.inferior_direita.y == -4);
}


TEST_CASE("Testar caixa_envoltoria em uma figura sem pontos") {
  Figura figura = {{}, 0 };

  Retangulo caixa = caixa_envoltoria(figura);
  CHECK(caixa.superior_esquerda.x == 0);
  CHECK(caixa.superior_esquerda.y == 0);
  CHECK(caixa.inferior_direita.x == 0);
  CHECK(caixa.inferior_direita.y == 0);
}


TEST_CASE("Testar ha_intersecao_envoltoria quando há sobreposição de área") {
  Figura figura1 = {
    {{0, 0}, {4, 0}, {4, 4}, {0, 4}},
    4
  };
  Figura figura2 = {
    {{2, -1}, {6, -1}, {6, 3}, {2, 3}},
    4
  };

  CHECK(ha_intersecao(figura1, figura2) == true);
}

TEST_CASE("Testar ha_intersecao_envoltoria quando não há sobreposição de área") {
  Figura figura1 = {
    {{0, 0}, {1, 0}, {1, 1}, {0, 1}},
    4
  };
  Figura figura2 = {
    {{5, 5}, {7, 5}, {7, 7}, {5, 7}},
    4
  };

  CHECK(ha_intersecao(figura1, figura2) == false);
}

TEST_CASE("Testar ha_intersecao_envoltoria com toque de borda") {
  Figura figura1 = {
    {{0, 0}, {2, 0}, {2, 2}, {0, 2}},
    4
  };
  Figura figura2 = {
    {{2, 0}, {4, 0}, {4, 2}, {2, 2}},
    4
  };
  CHECK(ha_intersecao(figura1, figura2) == true);
}


TEST_CASE("Testar ha_intersecao_envoltoria quando uma figura está completamente dentro da outra") {
  Figura figura1 = {
    {{0, 0}, {5, 0}, {5, 5}, {0, 5}},
    4
  };
  Figura figura2 = {
    {{1, 1}, {2, 1}, {2, 2}, {1, 2}},
    4
  };
  CHECK(ha_intersecao(figura1, figura2) == true);
}


TEST_CASE("Testar conta_intersecoes de figuras de uma imagem") {
  Imagem imagem = {
    {
      {{{0, 0}, {2, 0}, {2, 2}, {0, 2}}, 4},
      {{{1, 1}, {3, 1}, {3, 3}, {1, 3}}, 4},
      {{{4, 4}, {6, 4}, {6, 6}, {4, 6}}, 4}
    },
    3
  };
  CHECK(conta_intersecoes(imagem) == 1);
}