#include <string>
using namespace std;

/*
 * Controle de Pedidos
 * ==================================
 *
 * Você foi contratato para implementar o controle de pedidos de uma loja online e precisa
 * gerenciar seus status de cada pedido, desde a espera da confirmação de pagamento até
 * a entrega.
 *
 * Cada pedido possui as seguintes informações:
 * - codigo do pedido (um valor inteiro)
 * - nome do cliente (texto)
 * - valor total (valor real)
 * - estado (indica a situação do pedido)
 *
 * O estado do pedido pode assumir um dos seguintes valores:
 * - AGUARDANDO_PAGAMENTO
 * - PAGO
 * - EM_TRANSPORTE
 * - ENTREGUE
 * - CANCELADO
 *
 * Você foi então solicitado para implementar as funções a seguir.
 *
 * O fluxo de alteração de um pedido segue o seguinte processo:
 * - AGUARDANDO_PAGAMENTO -> PAGO -> EM_TRANSPORTE -> ENTREGUE
 * 
 * Porém, se um pedido já tiver sido entregue ou tiver sido cancelado, ele permanecerá no
 * mesmo no estado.
 */
enum Status{
	AGUARDANDO_PAGAMENTO, PAGO, EM_TRANSPORTE, ENTREGUE, CANCELADO
};

struct Pedido{
	int codigo;
	string nome;
	double valorTotal;
	Status estado ;
};

/**
 * Contar quantos pedidos se encontram em um determinado estado.
 * @param pedidos O array de pedidos a ser analisado.
 * @param n O número de pedidos no array.
 * @param status O estado a ser contado.
 * @return O número de pedidos que se encontram no estado especificado.
 */
int contar_estado(const Pedido pedidos[], int n, Status status) {
	// a completar
	int pedidosI = 0;
	for(int i = 0; i < n; i++){
		if(pedidos[i].estado == status){
			pedidosI++;
		}
	}
	return pedidosI;
}

/**
 * Calcular o valor total dos pedidos que já foram entregues.
 * @param pedidos O array de pedidos a ser analisado.
 * @param n O número de pedidos no array.
 * @return O valor total dos pedidos que já foram entregues.
 */
double total_entregues(const Pedido pedidos[], int n) {
	double valorTotalA = 0;
	for(int i = 0; i < n; i++){
		if(pedidos[i].estado == ENTREGUE){
			valorTotalA += pedidos[i].valorTotal;
		}
	}
	return valorTotalA;
}


/**
 * Cadastrar um pedido e um array de pedidos, garantindo que o código do pedido seja único.
 * Quando um pedido é cadastrado, ele deve ser adicionado ao array de pedidos com o estado AGUARDANDO_PAGAMENTO.
 * @param pedidos O array de pedidos onde o novo pedido deve ser adicionado.
 * @param n O número de pedidos atualmente no array.
 * @param codigo O código do novo pedido a ser adicionado.
 * @param cliente O nome do cliente do novo pedido.
 * @param valor_total O valor total do novo pedido.
 * @return true se o pedido foi adicionado com sucesso, ou false se o código do pedido já existe.
 */
bool cadastrar_pedido(Pedido pedidos[], int& n, int codigo, string cliente, double valor_total) {
		for(int i = 0; i < n; i++){
			if(pedidos[i].codigo == codigo){
				return false;
		}}
			pedidos[n] ={codigo, cliente, valor_total, AGUARDANDO_PAGAMENTO};
			n++;
	return true;
}

/**
 * Cancelar um pedido dado seu código, alterando seu estado para CANCELADO.
 * @param pedidos O array de pedidos onde o pedido a ser cancelado se encontra.
 * @param n O número de pedidos no array.
 * @param codigo O código do pedido a ser cancelado.
 * @return true se o pedido foi cancelado com sucesso, ou false se o código do pedido não foi encontrado.
 */
bool cancelar_pedido(Pedido pedidos[], int n, int codigo) {
	for(int i = 0; i  < n; i++){
		if(pedidos[i].codigo ==  codigo){
			pedidos[i].estado = CANCELADO;
			return true;
		}
	}
	return false;
}

/**
 * Atualizar o estado de um pedido dado seu código, respeitando o fluxo de mudança de estado.
 * @param pedidos O array de pedidos a ser atualizado.
 * @param n O número de pedidos no array.
 * @param codigo O código do pedido a ser atualizado.
 * @return true se o estado foi alterado ou false se permanenceu no mesmo estado.
 */
bool atualizar_estado(Pedido pedidos[], int n, int codigo) {
	for(int i = 0; i < n; i++){
		if(pedidos[i].codigo == codigo){
			if(pedidos[i].estado < 3){
				pedidos[i].estado = (Status)(pedidos[i].estado + 1);
				return true;
			}
		}
	}
	return false;	
}
