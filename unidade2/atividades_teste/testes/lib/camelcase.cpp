#include <string>
using namespace std;

/**
 * Converte uma string para o formato camelCase. O formato camelCase é um estilo de escrita
 * onde a primeira letra de cada palavra, exceto a primeira, é maiúscula e as palavras são
 * concatenadas sem espaços. Por exemplo, "ola mundo" se torna "olaMundo".
 * @param texto A string a ser convertida.
 * @return A string convertida para camelCase.
 */
string to_camel(string texto) {
  // a completar
    string textoC;
    int i = texto.find_first_not_of(" ");

    //percorre a string
    while(i < texto.size()){
      //final da palavra
      int fimP = texto.find_first_of(" ",i);

      if(i == texto.find_first_not_of(" ")){
        texto[i] = tolower(texto[i]);
        textoC = texto.substr(i, fimP - i);
        i = texto.find_first_not_of(" ", fimP);
        continue;
      }
      if(fimP != string :: npos){
        texto[i] = toupper(texto[i]);
        textoC += texto.substr(i, fimP - i);
        i = texto.find_first_not_of(" ", fimP);
      }
      else if(fimP == string :: npos || fimP >= texto.size()){
        texto[i] = toupper(texto[i]);
        textoC += texto.substr(i, texto.size() - i);
        break;
      }
    }

  return textoC;
}