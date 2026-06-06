/*
 * Este arquivo deve conter as implementações de funções RECURSIVAS.
 * O objetivo é fazer você pensar em "como resolver o problema usando a solução
 * para um subproblema menor".
 * É um exercício de como quebrar problemas em partes menores, e não de como
 * usar laços. Porém, você vai ver que alguns problemas são mais fáceis de
 * resolver usando recursão do que usando laços (como labirinto_recursivo()
 * e preenchimento_recursivo()).
 */

/**
 * Calcula o fatorial de um número usando recursão. A função deve receber um número
 * inteiro e retornar o fatorial desse número.
 * @param n O número inteiro do qual se deseja calcular o fatorial.
 * @return O fatorial do número fornecido.
 */
int fatorial_recursivo(int n) {
  // a completar
if(n == 0){
  return 1;
}
  return n*fatorial_recursivo(n - 1);
}


/**
 * Calcula o n-ésimo número da sequência de Fibonacci usando recursão. A função deve
 * receber um número inteiro n e retornar o n-ésimo número da sequência de Fibonacci.
 * @param n O número inteiro que representa a posição na sequência de Fibonacci.
 * @return O n-ésimo número da sequência de Fibonacci.
 */
int fibonacci_recursivo(int n) {
  //a completar
  if(n == 1){
    return 1;
  }
  if(n == 0){
    return 0;
  }
  
   return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n -2);
}


/**
  * Calcula a potência de um número usando recursão. A função deve receber uma base
  * (número real) e um expoente (número inteiro positivo) e retornar o resultado da base
  * elevada ao expoente.
  * @param base O número real que será a base da potência.
  * @param expoente O número inteiro com o expoente ao qual a base será elevada.
  * @return O resultado da base elevada ao expoente.
  */
double potencia_recurvisa(double base, unsigned int expoente) {
  // a completar
  if(expoente == 0){
    return 1;
  }

  return base * potencia_recurvisa(base,expoente - 1);
}


/**
 * Calcula o MDC de dois números inteiros usando recursão. A função deve receber dois
 * números inteiros e retornar o maior divisor comum entre eles.
 * @param a O primeiro número inteiro.
 * @param b O segundo número inteiro.
 * @return O maior divisor comum entre a e b.
 */
int mdc_recursivo(int a, int b) {
  // a completar
  if(b == 0 ){
    return a;
  }
  return mdc_recursivo(b, a % b);
}


/**
 * Encontra o maior valor de uma sequência de inteiros usando recursão. A função deve
 * receber um array de inteiros e seu tamanho, e retornar o maior valor presente
 * no array.
 * @param arr O array de inteiros do qual se deseja encontrar o maior valor.
 * @param tamanho O número de elementos presentes no array.
 * @return O maior valor presente no array.
 */
int maior_valor_recursivo(int arr[], int tamanho) {
    if(tamanho <= 0){
      return arr[0];
    }
    int maior = maior_valor_recursivo(arr, tamanho - 1);
    
    if(arr[tamanho - 1] > maior){
      return arr[tamanho - 1];
    }
    else{
      return maior;
    }

}


/**
 * Calcula o somatório de uma sequência de inteiros usando recursão. A função deve
 * receber um array de inteiros e seu tamanho, e retornar a soma de todos os elementos
 * presentes no array.
 * @param arr O array de inteiros do qual se deseja calcular o somatório.
 * @param tamanho O número de elementos presentes no array.
 * @return A soma de todos os elementos presentes no array.
 */;
// complete a partir daqui
int somatorio_recursivo(int arr[], int tamanho){
  if(tamanho == 1){
    return arr[0];
  }

  return arr[tamanho - 1] + somatorio_recursivo(arr, tamanho - 1);
}


/**
 * Verifica se um dado número inteiro encontra-se presente em um array de inteiros
 * usando recursão. A função deve receber um array de inteiros, seu tamanho e um número
 * inteiro a ser verificado, e retornar true se o número estiver presente no array ou
 * false caso contrário.
 * @param arr O array de inteiros no qual se deseja verificar a presença do número.
 * @param tamanho O número de elementos presentes no array.
 * @param numero O número inteiro a ser verificado no array.
 * @return true se o número estiver presente no array, ou false caso contrário.
*/
// complete a partir daqui
bool contem_recursivo(int arr[], int tamanho, int numero){
  if(tamanho < 0){
    return false;
  }

  if(arr[tamanho] == numero){
    return true;
  }

  else{
    return contem_recursivo(arr, tamanho - 1, numero);
  }
}

/**
 * Conta quantas vezes um determinado caractere aparece em uma string usando recursão.
 * @param str A string na qual se deseja contar os caracteres.
 * @param caractere O caractere a ser contado na string.
 * @return O número de vezes que o caractere aparece na string.
 */
// complete a partir daqui


/**
 * Verifica se um há saída para um labirinto representado por uma matriz 10x10 de
 * caracteres usando recursão. A função deve receber uma matriz 10x10 de caracteres,
 * as coordenadas de início e as coordenadas da saída, e retornar true se houver um
 * caminho do início até a saída ou false caso contrário. A matriz de caracteres
 * representa o labirinto, onde ' ' representa um caminho livre e '#' representa uma
 * parede.
 * @param labirinto A matriz de caracteres que representa o labirinto.
 * @param inicio_x A coordenada x do ponto de início.
 * @param inicio_y A coordenada y do ponto de início.
 * @param destino_x A coordenada x do ponto de destino.
 * @param destino_y A coordenada y do ponto de destino.
 * @return true se houver um caminho do início ao destino, ou false caso contrário.
 */
bool labirinto_recursivo(char labirinto[10][10], int inicio_x, int inicio_y, int destino_x, int destino_y) {
  // a completar
  return false;
}

/**
 * Realiza o preenchimento de uma área conectada em uma matriz 10x10 de caracteres
 * usando recursão. A função deve receber uma matriz 10x10 de caracteres, e um
 * caractere que representa a nova cor a ser preenchida. A função deve preencher a área
 * conectada (composta por caracteres iguais) com a nova cor, começando a partir do
 * ponto (0,0) e se estendendo para os pontos adjacentes (cima, baixo, esquerda,
 * direita) que sejam do mesmo caractere original. A função deve modificar a matriz de
 * caracteres passada.
 * Obs: Para ver uma aplicação prática dessa função, visite o jogo Flood it em:
 * https://unixpapa.com/floodit/
 * @param imagem A matriz de caracteres que representa a área a ser preenchida.
 * @param nova_cor O caractere que representa a nova cor a ser preenchida a partir do
 * ponto (0,0).
 */
void preenchimento_recursivo(char imagem[10][10], char nova_cor) {
  // a completar
}