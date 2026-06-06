#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "biblioteca.cpp"

TEST_CASE("Gerenciamento de Biblioteca") {
Biblioteca biblioteca;
// Dados do livro: título, autor, ISBN
Livro l1 = {"O Senfhor dos Anéis", "J.R.R. Tolkien", 9788845292613};
Livro l2 = {"1984", "George Orwell", 9788547007063};
Livro l3 = {"A Revolução dos Bichos", "George Orwell", 9788547007064};
// Dados do usuário: ID e nome
Usuario fulano = {1, "Fulano"};
Usuario beltrano = {2, "Beltrano"};
CHECK(biblioteca.cadastrarLivro(l1) == true);
CHECK(biblioteca.cadastrarLivro(l2) == true);
CHECK(biblioteca.cadastrarLivro(l3) == true);
CHECK(biblioteca.cadastrarUsuario(fulano) == true);
CHECK(biblioteca.cadastrarUsuario(beltrano) == true);
// Parâmetros do empréstimo: ISBN do livro e ID do usuário, indicando
// que o usuário do ID solicitou o empréstimo do livro com o ISBN
CHECK(biblioteca.emprestarLivro(9788845292613, 1) == true);
CHECK(biblioteca.emprestarLivro(9788547007063, 1) == true);
CHECK(biblioteca.emprestarLivro(9788547007064, 2) == true);
// Tentativa de empréstimo de um livro já emprestado
CHECK(biblioteca.emprestarLivro(9788845292613, 2) == false);
// Verifica quantos livros um usuário de dado ID pegou emprestado
CHECK(biblioteca.quantidadeLivros(1) == 2);
CHECK(biblioteca.quantidadeLivros(2) == 1);
CHECK(biblioteca.devolverLivro(9788845292613, 1) == true);
CHECK(biblioteca.devolverLivro(9788547007063, 1) == true);
// Agora o livro pode ser emprestado para outro usuário
CHECK(biblioteca.emprestarLivro(9788845292613, 2) == true);
CHECK(biblioteca.quantidadeLivros(1) == 0);
CHECK(biblioteca.quantidadeLivros(2) == 2);
}