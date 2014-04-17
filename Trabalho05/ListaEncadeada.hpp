/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 05 - Trabalho de Sistema de Contabilidade Mafioso com Lista Encadeada Simples
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * ListaEncadeada.hpp
 */

 #ifndef _ListaEncadeada_hpp_
 #define _ListaEncadeada_hpp_

 #define ERRO_NAO_HA_ESPACO -1;
 #define ERRO_POSICAO_INVALIDA -2;

template <typename T>
class ListaEncadeada {
public:
	ListaEncadeada();
	~ListaEncadeada();
	void adiciona(*T elemento);
	void adicionaNoInicio(*T elemento);
	void adicionaNaPosicao(*T elemnto, int posicao);
	void adicionaEmOrdem(*T elemento);
	T retira();
	T retiraDoInicio();
	T retiraDaPosicao(int posicao);
	void retiraEspecifico(*T elemento);
	bool estaVazia();
	int posicao(*T elemento);
	bool contem(*T elemento);
private:
	*Elemento<T> dados;
	int tamanho;
};

 
template <typename T>
ListaEncadeada<T>::ListaEncadeada() {
	tamanho = 0;
	dados = NULL;
}

template <typename T>
ListaEncadeada<T>::~ListaEncadeada() {
 	
}

template <typename T>
void ListaEncadeada<T>::adicionaNoInicio(*T elemento) {
	Elemento<T> *novoElemento = new Elemento<T>();
	if (novoElemento != NULL) {
		novoElemento.adicionarProximoElemento(this->dados);
		dados = novoElemento;
		novoElemento.adicionaInformacao(elemento);
		this->tamanho++;

	}
	throw (ERRO_NAO_HA_ESPACO);
	
}

template <typename T>
void ListaEncadeada<T>::adicionaNaPosicao(*T elemento, int posicao) {
	if (posicao == 0){
		this.adicionaNoInicio(elemento);
		return 0;
	}
	if(posicao <= this->tamanho){
		Elemento<T> *novoElemento = new Elemento<T>();
		Elemento<T> *ultimoElemento = dados;
		if(novoElemento != NULL){
			for(int i = 0 ; i < this->posicao - 1 ; i++) {
			ultimoElemento = ultimoElemento.pegarProximoElemento();
			}
		ultimoElemento.adicionarProximoElemento(novoElemento);
		novoElemento.adicionaInformacao(elemento);
		this->tamanho++;	
		}
		throw (ERRO_NAO_HA_ESPACO);
	}
	throw (ERRO_POSICAO_INVALIDA);
	
}

#endif