#include <string>
using namespace std;

/*
O tabuleiro de xadrez é representado por 8 colunas, identificadas pelas letras de 'a' a 'g',
e 8 linhas, numeradas de 1 a 8, como na tabela abaixo. Assim, as seguintes textos são exemplos
de representações válidas para posições no tabuleiro: a8, b6, f8, e3.

a8 b8 c8 d8 e8 f8 g8 h8
a7 b7 c7 d7 e7 f7 g7 h7
a6 b6 c6 d6 e6 f6 g6 h6
a5 b5 c5 d5 e5 f5 g5 h5
a4 b4 c4 d4 e4 f4 g4 h4
a3 b3 c3 d3 e3 f3 g3 h3
a2 b2 c2 d2 e2 f2 g2 h2
a1 b1 c1 d1 e1 f1 g1 h1

Durante o jogo, a rainha pode se movimentar em qualquer direção (horizontal, vertical e diagonal)
em um número qualquer de casas no tabuleiro. Por exemplo, se a rainha se encontra na posição c2,
ela pode se mover para a posição g6 (é um movimento diagonal válido), mas não pode mover para g7
(não se encontra na diagonal, nem horizontal, nem vertical).
*/

/**
 * Verifica se, a partir de uma posição no tabuleiro, uma rainha consegue se movimentar para outra
 * posição.
 * @param origin string com a posição da rainha (ex: "c2")
 * @param target string com a posição a ser validada (ex: "g6")
 * @return retorna verdadeiro se uma rainha pode se movimentar de origin a target, ou falso caso contrário.
 */
bool is_valid_queen_move(string origin, string target) {
  char linha =  origin[1];
  char coluna = origin[0];
  //movimento vertical e horizontal
  if( coluna == target[0] || linha == target[1]){
    return true;
  }

  //movimento diagonal
  for(int i = 1; i < 8; i++){
    if((coluna + i == target[0] && linha + i == target[1]) || (coluna + i == target[0] && linha - i == target[1])){
      return true;
    }
  }
  
  for(int i = 8; i > 1; i--){
    if((coluna - i == target[0] && linha - i == target[1]) || (coluna - i == target[0] && linha + i == target[1])){
      return true;
    }
  }
  return false;
}