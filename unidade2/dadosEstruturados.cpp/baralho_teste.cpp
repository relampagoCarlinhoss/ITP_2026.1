#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "baralho.cpp"

TEST_CASE("VERIFICANDO SE HÁ UM JOGO NUM CONJUNTO PEQUENO DE CARTAS"){
    Cartas c = {3, { 
        {DOIS,COPAS},
        {TRES, COPAS},
        {QUATRO, COPAS}
    }};
    CHECK(verificaCarta(c) == true);
}

TEST_CASE("VERIFICANDO SE HÁ UM JOGO NUM CONJUNTO PEQUENO DE CARTAS"){
    Cartas c = {3, {
        {DOIS, PAUS},
        {TRES, OUROS},
        {QUATRO, ESPADAS}
    }};
    CHECK(verificaCarta(c) == false);
}

TEST_CASE("VERIFICANDO SE HÁ UM JOGO NUM CONJUNTO MAIOR DE CARTAS"){
    Cartas c={11, {
        {DOIS, PAUS},
        {QUATRO, OUROS},
        {CINCO,ESPADAS},
        {OITO, COPAS},
        {DAMA, COPAS},
        {DAMA, ESPADAS},
        {DAMA, OUROS},
        {REI, ESPADAS},
        {AS, OUROS},
        {DOIS, OUROS},
        {TRES, OUROS}
    }};
    CHECK(verificaCarta(c) == false);
    }

TEST_CASE("Verificando se há um jogo num conjunto maior de cartas.") {
  Cartas c = {
    9,
    {
      { VALETE, OUROS },
      { REI, OUROS },
      { SEIS, ESPADAS },
      { DAMA, ESPADAS },
      { DOIS, COPAS },
      { TRES, COPAS },
      { QUATRO, COPAS },
      { CINCO, PAUS },
      { SEIS, PAUS }
    }
  };
  CHECK(verificaCarta(c) == true);
};

TEST_CASE("Verificando se há um jogo num conjunto maior de cartas.") {
  Cartas c = {
    9,
    {
      { VALETE, OUROS },
      { REI, OUROS },
      { SEIS, ESPADAS },
      { DAMA, ESPADAS },
      { DOIS, COPAS },
      { TRES, COPAS },
      { CINCO, COPAS },
      { CINCO, PAUS },
      { SEIS, PAUS }
    }
  };
  CHECK(verificaCarta(c) == false);
};

