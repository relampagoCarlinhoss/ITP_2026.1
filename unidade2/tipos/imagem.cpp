#include <algorithm>

/*
 * Imagem vetorial
 * ==================================
 *
 * Você foi selecionado para atuar num projeto cujo objetivo é desenvolver um software de edição
 * de imagens vetoriais. O software deve ser capaz de representar figuras geométricas, calcular
 * suas caixas envoltórias (o retângulo que envolve todos os pontos da figura), verificar interseção
 * entre figuras e realizar transformações como deslocamento.
 * 
 * Você precisa, então, definir os tipos de dados necessários para representar uma imagem vetorial,
 * incluindo figuras, pontos e retângulos (para a caixa envoltória).
 *
 * Neste projeto, uma imagem é definida por um conjunto (array) de figuras, onde cada figura é um
 * polígono definido por uma sequência de pontos... e cada ponto possui suas coordenadas x e y.
 * 
 * Como se trata de um software simples, existem algumas limitações:
 * - as coordenadas dos pontos são valores inteiros;
 * - cada figura pode conter no máximo 100 pontos;
 * - a imagem pode conter no máximo 50 figuras.
 * 
 * Além desses tipos, é necessário também definir um tipo para representar um retângulo, já que
 * será necessário calcular a caixa envoltória de uma figura. O retângulo é definido por dois pontos
 * contendo as coordenadas superior esquerda e coordenada inferior direita.
 *
 * Obs: nos testes, a convenção adotada é a mesma do plano cartesiano. Ou seja, a coordenada
 * superior esquerda é a de menor x e maior y, enquanto a coordenada inferior direita é a de maior
 * x e menor y.
 *
 * Implemente então as funções a seguir.
 */

const int MAX_PONTOS = 100;
const int MAX_FIGURAS = 50;

struct Ponto {
	int x;
	int y;
};

struct Figura {
	Ponto pontos[MAX_PONTOS];
	int n_pontos;
};

struct Imagem {
	Figura figuras[MAX_FIGURAS];
	int n_figuras;
};

struct Retangulo {
	Ponto superior_esquerda;
	Ponto inferior_direita;
};


/**
 * Mover todos os pontos de uma figura de um deslocamento tanto em X (horizontal) quanto
 * em Y (vertical).
 * @param figura A figura a ser deslocada (será alterada).
 * @param delta_x O deslocamento horizontal.
 * @param delta_y O deslocamento vertical.
 */
void deslocar_figura(Figura& figura, int delta_x, int delta_y) {
	// a completar
	for(int i = 0; i < figura.n_pontos; i++){
		figura.pontos[i].x += delta_x;
		figura.pontos[i].y+= delta_y;
	}
}

/**
 * Calcular a caixa envoltória (bounding box) de uma figura.
 * A caixa envoltória é o retângulo de menor área que envolve todos os pontos da figura.
 * @param figura A figura (poligono) para a qual sera calculada a caixa envoltoria.
 * @return O retangulo que envolve todos os pontos da figura.
 */
Retangulo caixa_envoltoria(const Figura& figura) {
	// a completar
	Retangulo limite{figura.pontos[0].x,figura.pontos[0].y, figura.pontos[0].x, figura.pontos[0].y};

	for(int i = 1; i < figura.n_pontos; i++){
		if(limite.inferior_direita.x < figura.pontos[i].x){
			limite.inferior_direita.x = figura.pontos[i].x;
		}
		if(limite.inferior_direita.y > figura.pontos[i].y){
			limite.inferior_direita.y = figura.pontos[i].y;
		}
		if(limite.superior_esquerda.x > figura.pontos[i].x){
			limite.superior_esquerda.x = figura.pontos[i].x;
		}
		if(limite.superior_esquerda.y < figura.pontos[i].y){
			limite.superior_esquerda.y = figura.pontos[i].y;
		}
	}
	return limite;
}

/**
 * Verificar se há interseção entre as áreas envoltórias de duas figuras.
 * @param figura1 A primeira figura.
 * @param figura2 A segunda figura.
 * @return true se houver interseção de área entre as caixas envoltórias,
 * ou false caso contrário.
 */
bool ha_intersecao(const Figura& figura1, const Figura& figura2) {
	Retangulo ret1 = caixa_envoltoria(figura1);
	Retangulo ret2 = caixa_envoltoria(figura2);
	
	bool limiteXd = ret2.inferior_direita.x >= ret1.superior_esquerda.x  && ret2.inferior_direita.x <= ret1.inferior_direita.x;
	bool limiteXe = ret2.superior_esquerda.x >= ret1.superior_esquerda.x  && ret2.superior_esquerda.x <= ret1.inferior_direita.x;
	bool limiteYe = ret2.superior_esquerda.y >= ret1.inferior_direita.y && ret2.superior_esquerda.y <= ret1.superior_esquerda.y;
	bool limiteYd = ret2.inferior_direita.y >= ret1.inferior_direita.y && ret2.inferior_direita.y <= ret1.superior_esquerda.y;

	if((limiteXd || limiteXe) && (limiteYe || limiteYd)){
		return true;
	}
	return false;
}

/**
 * Contar o número de interseções entre as áreas envoltórias das figuras de uma imagem.
 * @param imagem A imagem contendo as figuras.
 * @return O número de interseções entre as caixas envoltórias.
 */
int conta_intersecoes(const Imagem& imagem) {
	int haInter = 0;
	for(int i = 0; i < imagem.n_figuras; i++){
		for(int j = i + 1; j < imagem.n_figuras; j++){
			if(ha_intersecao(imagem.figuras[i], imagem.figuras[j])){
				haInter++;
			}
		}
	}
  return haInter;
}

