/*
Gomoku é um jogo japonês milenar, jogado em um tabuleiro de 15x15 células e pedras pretas e brancas.
Um jogador joga com as pedras brancas, o outro joga com as pedras pretas. O objetivo do jogo, como o
nome sugere (go-moku em japonês quer dizer cinco pedras) é colocar cinco pedras da mesma cor
consecutivamente ou numa mesma linha, ou numa mesma coluna, ou numa diagonal do tabuleiro.
*/

/**
 * Identifica se o estado do tabuleiro de uma partida no Gomoku tem um vencedor.
 * Assume-se que cada célula da matriz possui apenas 3 possíveis valores: 0, 1 e 2.
 * O número 1 indica uma pedra preta, o número 2 indica uma pedra branca e o número 0
 * indica que não há pedra na célula.
 * 
 * @param tabuleiro matriz 15x15 com o estado do tabuleiro
 * @return 0 se a partida estiver empatada, 1 se as pretas ganharam ou 2 se as brancas ganharam.
 */

int gomoku_winner(int tabuleiro[15][15]) {
  int preta = 0;
  int branca = 0;
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){

      //vitoria linha ou coluna das pretas.
      if(tabuleiro[i][j] == 1){
        if(j + 4 < 14 && tabuleiro [i][j+1] == 1 && tabuleiro[i][j+2] == 1 && tabuleiro [i][j+3] == 1 && tabuleiro[i][j+4] == 1){
          preta++;
        }
        else if(i + 4 < 14 && tabuleiro [i + 1][j] == 1 && tabuleiro[i + 2][j] == 1 && tabuleiro [i + 3][j] == 1 && tabuleiro[i + 4][j] == 1){
          preta++;
        }
        else if(i + 4 < 14 && j + 4 < 14 && tabuleiro [i+1][j+1] == 1 && tabuleiro[i+2][j+2] == 1 && tabuleiro [i+3][j+3] == 1 && tabuleiro[i+4][j+4] == 1 ){
          preta++;
        }
      }

      //vitoria linha/coluna das brancas.
      else if(tabuleiro[i][j] == 2){
        if(j + 4 < 14 && tabuleiro [i][j+1] == 2 && tabuleiro[i][j+2] == 2 && tabuleiro [i][j+3] == 2 && tabuleiro[i][j+4] == 2){
          branca++;
        }
        else if(i + 4 < 14 && tabuleiro [i + 1][j] == 2 && tabuleiro[i + 2][j] == 2 && tabuleiro [i + 3][j] == 2 && tabuleiro[i + 4][j] == 2){
          branca++;
        }
        else if(i + 4 < 14 && j + 4 < 14 && tabuleiro [i+1][j+1] == 2 && tabuleiro[i+2][j+2] == 2 && tabuleiro [i+3][j+3] == 2 && tabuleiro[i+4][j+4] == 2){
          branca++;
        }
      }
      }
    }
    if(preta > branca){
      return 1;
    }
    if( branca > preta){
      return 2;
    }
    return 0;
  }
  