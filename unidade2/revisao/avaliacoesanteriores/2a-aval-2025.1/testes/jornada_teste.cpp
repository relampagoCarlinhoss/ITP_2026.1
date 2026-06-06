#define  DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../jornada.cpp"
using namespace std;

// defina os tipos e implemente sua função aqui

/*
// --- Testes ---
// Você pode definir novos testes para a sua função aqui
TEST_CASE("TESTANDO SOMA DOS TIPOSTERRENOS"){
Terreno t1 = {3, 3,
    { // altitudes
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
    },
    { // tipos de terreno
      {PANTANO, PANTANO,  PLANICIE},
      {PANTANO, PLANICIE, GELEIRA},
      {PANTANO, DESERTO,  GELEIRA}
    }
  };
  int arra[9];
  int alt[9];
  
Terreno t4 = {4, 5,
    { // altitudes
      {2, 0, 1, 2, 3},
      {2, 1, 0, 2, 5},
      {0, 1, 2, 3, 4},
      {1, 2, 0, 1, 2}
    },
    { // tipos de terreno
      {PANTANO, PANTANO,  PLANICIE, PLANICIE, GELEIRA},
      {PANTANO, PLANICIE, PANTANO,  PLANICIE, GELEIRA},
      {PANTANO, DESERTO,  DESERTO,  GELEIRA,  GELEIRA},
      {PANTANO, DESERTO,  PLANICIE, PLANICIE, DESERTO}
    }
  };

  esforcoTerreno(t4, 4, 5, arra);
   CHECK( arra[6] == 7);
   CHECK(arra[1] == 7);
   CHECK(arra[3] == 6); 
  
  esforcoAltitude(t4, 4, 5, alt);
  CHECK(alt[6] == 3);
  CHECK(alt[3] == 6);

}
  */
// Mas esta parte não pode ser alterada!
TEST_CASE("Testa o menor esforço da jornada em vários terrenos") {
  Terreno t1 = {3, 3,
    { // altitudes
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
    },
    { // tipos de terreno
      {PANTANO, PANTANO,  PLANICIE},
      {PANTANO, PLANICIE, GELEIRA},
      {PANTANO, DESERTO,  GELEIRA}
    }
  };

  Terreno t2 = {2, 2,
    { // altitudes
      {0, 2},
      {3, 1}
    },
    { // tipos de terreno
      {PANTANO, PLANICIE},
      {DESERTO, PANTANO}
    }
  };

  Terreno t3 = {1, 1,
    { // altitudes
      {5}
    },
    { // tipos de terreno
      {GELEIRA}
    }
  };

  Terreno t4 = {4, 5,
    { // altitudes
      {2, 0, 1, 2, 3},
      {2, 1, 0, 2, 5},
      {0, 1, 2, 3, 4},
      {1, 2, 0, 1, 2}
    },
    { // tipos de terreno
      {PANTANO, PANTANO,  PLANICIE, PLANICIE, GELEIRA},
      {PANTANO, PLANICIE, PANTANO,  PLANICIE, GELEIRA},
      {PANTANO, DESERTO,  DESERTO,  GELEIRA,  GELEIRA},
      {PANTANO, DESERTO,  PLANICIE, PLANICIE, DESERTO}
    }
  };

  CHECK(menor_jornada(t1) == 7);  // Jornada na linha 0
  CHECK(menor_jornada(t2) == 4);  // Jornada na coluna 1
  CHECK(menor_jornada(t3) == 4);  // Só conta o tipo de terreno (geleira)
  CHECK(menor_jornada(t4) == 10); // Jornada na coluna 3
}
