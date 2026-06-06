#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../lib/camelcase.cpp"

TEST_CASE("Verificando a formatação de textos simples para CamelCase.") {
  CHECK(to_camel("De tudo ao meu amor serei atento") == "deTudoAoMeuAmorSereiAtento");
  CHECK(to_camel("Antes e com tal zelo e sempre e tanto") == "antesEComTalZeloESempreETanto");
  CHECK(to_camel("Que mesmo em face do maior encanto") == "queMesmoEmFaceDoMaiorEncanto");
  CHECK(to_camel("Dele se encante mais meu pensamento") == "deleSeEncanteMaisMeuPensamento");
};

TEST_CASE("Verificando a formatação de textos com espaços no início.") {
  CHECK(to_camel("   De tudo ao meu amor serei atento") == "deTudoAoMeuAmorSereiAtento");
  CHECK(to_camel("           Antes e com tal zelo e sempre e tanto") == "antesEComTalZeloESempreETanto");
};

TEST_CASE("Verificando a formatação de textos com espaços no fim.") {
  CHECK(to_camel("Que mesmo em face do maior encanto     ") == "queMesmoEmFaceDoMaiorEncanto");
  CHECK(to_camel("Dele se encante mais meu pensamento  ") == "deleSeEncanteMaisMeuPensamento");
};

TEST_CASE("Verificando a formatação de textos com um ou mais espaços entre as palavras.") {
  CHECK(to_camel("Que    mesmo em    face do maior encanto") == "queMesmoEmFaceDoMaiorEncanto");
  CHECK(to_camel("Dele  se    encante mais   meu   pensamento") == "deleSeEncanteMaisMeuPensamento");
};