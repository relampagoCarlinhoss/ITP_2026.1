/**
 * Verifica se há interseção entre duas sequências de dados. Ou seja, verifica se há algum
 * elemento comum nos dois conjuntos.
 * @param tam_a tamanho da primeira sequência de dados
 * @param a vetor com os elementos da primeira sequência
 * @param tam_b tamanho da segunda sequência de dados
 * @param b vetor com os elementos da segunda sequência
 * @return retorna verdadeiro se houver interseção entre as sequências, ou falso caso contrário.
 */
bool has_intersection(int tam_a, int a[], int tam_b, int b[]) {
  for(int i = 0; i < tam_a; i++){
    for(int j = 0; j < tam_b; j++){
      if(a[i] == b[j]){
        return true;
      }
    }
  }
  return false;
}