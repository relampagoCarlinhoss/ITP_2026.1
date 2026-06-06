#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../pedidos.cpp"

TEST_CASE("Testar contar_estado") {
  Pedido pedidos[] = {
    {1, "Alice", 100.0, AGUARDANDO_PAGAMENTO},
    {2, "Bob", 150.0, PAGO},
    {3, "Charlie", 200.0, EM_TRANSPORTE},
    {4, "Diana", 250.0, ENTREGUE},
    {5, "Eve", 300.0, CANCELADO},
    {6, "Frank", 350.0, AGUARDANDO_PAGAMENTO}
  };
  int n = 6;

  CHECK(contar_estado(pedidos, n, AGUARDANDO_PAGAMENTO) == 2);
  CHECK(contar_estado(pedidos, n, PAGO) == 1);
  CHECK(contar_estado(pedidos, n, EM_TRANSPORTE) == 1);
  CHECK(contar_estado(pedidos, n, ENTREGUE) == 1);
  CHECK(contar_estado(pedidos, n, CANCELADO) == 1);
}

TEST_CASE("Testar contar_estado com array vazio") {
  Pedido pedidos[] = {};
  int n = 0;

  CHECK(contar_estado(pedidos, n, AGUARDANDO_PAGAMENTO) == 0);
  CHECK(contar_estado(pedidos, n, PAGO) == 0);
  CHECK(contar_estado(pedidos, n, EM_TRANSPORTE) == 0);
  CHECK(contar_estado(pedidos, n, ENTREGUE) == 0);
  CHECK(contar_estado(pedidos, n, CANCELADO) == 0);
}

TEST_CASE("Testar total_entregues") {
  Pedido pedidos[] = {
    {1, "Alice", 100.0, AGUARDANDO_PAGAMENTO},
    {2, "Bob", 150.0, PAGO},
    {3, "Charlie", 200.0, EM_TRANSPORTE},
    {4, "Diana", 250.0, ENTREGUE},
    {5, "Eve", 300.0, CANCELADO},
    {6, "Frank", 350.0, ENTREGUE}
  };
  int n = 6;

  CHECK(total_entregues(pedidos, n) == doctest::Approx(600.0));
}

TEST_CASE("Testar total_entregues com nenhum pedido entregue") {
  Pedido pedidos[] = {
    {1, "Alice", 100.0, AGUARDANDO_PAGAMENTO},
    {2, "Bob", 150.0, PAGO},
    {3, "Charlie", 200.0, EM_TRANSPORTE},
    {4, "Diana", 250.0, CANCELADO}
  };
  int n = 4;

  CHECK(total_entregues(pedidos, n) == doctest::Approx(0.0));
}


TEST_CASE("Testar cadastrar_pedido") {
  Pedido pedidos[10];
  int n = 0;

  CHECK(cadastrar_pedido(pedidos, n, 1, "Alice", 100.0) == true);
  CHECK(n == 1);
  CHECK(pedidos[0].codigo == 1);
  CHECK(pedidos[0].nome == "Alice");
  CHECK(pedidos[0].valorTotal == doctest::Approx(100.0));
  CHECK(pedidos[0].estado == AGUARDANDO_PAGAMENTO);

  CHECK(cadastrar_pedido(pedidos, n, 2, "Bob", 150.0) == true);
  CHECK(n == 2);
  CHECK(pedidos[1].codigo == 2);
  CHECK(pedidos[1].nome == "Bob");
  CHECK(pedidos[1].valorTotal == doctest::Approx(150.0));
  CHECK(pedidos[1].estado == AGUARDANDO_PAGAMENTO);
}

TEST_CASE("Testar cadastrar_pedido de um pedido existente") {
  Pedido pedidos[10];
  int n = 0;

  CHECK(cadastrar_pedido(pedidos, n, 1, "Alice", 100.0) == true);

  // Tentar cadastrar um pedido com código já existente
  CHECK(cadastrar_pedido(pedidos, n, 1, "Charlie", 200.0) == false);
  CHECK(n == 1); // O número de pedidos não deve ter aumentado
}

TEST_CASE("Testar cancelar_pedido") {
  Pedido pedidos[] = {
    {1, "Alice", 100.0, AGUARDANDO_PAGAMENTO},
    {2, "Bob", 150.0, PAGO},
    {3, "Charlie", 200.0, EM_TRANSPORTE}
  };
  int n = 3;

  CHECK(cancelar_pedido(pedidos, n, 2) == true);
  CHECK(pedidos[1].estado == CANCELADO);
}

TEST_CASE("Testar cancelar_pedido de um pedido inexistente") {
  Pedido pedidos[] = {
    {1, "Alice", 100.0, AGUARDANDO_PAGAMENTO},
    {2, "Bob", 150.0, PAGO},
    {3, "Charlie", 200.0, EM_TRANSPORTE}
  };
  int n = 3;

  // Tentar cancelar um pedido com código que não existe
  CHECK(cancelar_pedido(pedidos, n, 4) == false);
  CHECK(pedidos[0].estado == AGUARDANDO_PAGAMENTO);
  CHECK(pedidos[1].estado == PAGO);
  CHECK(pedidos[2].estado == EM_TRANSPORTE);
}

TEST_CASE("Testar atualizar_estado") {
  Pedido pedidos[] = {
    {1, "Alice", 100.0, AGUARDANDO_PAGAMENTO},
    {2, "Bob", 150.0, PAGO},
    {3, "Charlie", 200.0, EM_TRANSPORTE},
    {4, "Diana", 250.0, ENTREGUE},
    {5, "Eve", 300.0, CANCELADO}
  };
  int n = 5;

  CHECK(atualizar_estado(pedidos, n, 1) == true);
  CHECK(pedidos[0].estado == PAGO);

  CHECK(atualizar_estado(pedidos, n, 2) == true);
  CHECK(pedidos[1].estado == EM_TRANSPORTE);

  CHECK(atualizar_estado(pedidos, n, 3) == true);
  CHECK(pedidos[2].estado == ENTREGUE);

  // Tentar atualizar um pedido que já está entregue
  CHECK(atualizar_estado(pedidos, n, 4) == false);
  CHECK(pedidos[3].estado == ENTREGUE);

  // Tentar atualizar um pedido que já está cancelado
  CHECK(atualizar_estado(pedidos, n, 5) == false);
  CHECK(pedidos[4].estado == CANCELADO);
}