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
 * Elemento.hpp
 */

#ifndef _ListaEncadeada_hpp_
#define _ListaEncadeada_hpp_


template <typename T>
class Elemento {
public:
	Elemento();
	~Elemento();
	void adicionarProximoElemento(*Elemento<T>);
	Elemento<T> pegarProximoElemento();
	void adicionaInformacao(*T informacao);
	T pegarInformacao();
private:
	*Elemento<T> proximoElemento;
	T *informacao;

};

template <typename T>
Elemento<T>::Elemento() {
	proximoElemento = NULL;
	informacao = NULL;
}

template <typename T>
Elemento<T>::~Elemento() {

}

template <typename T>
void Elemento<T>::adicionarProximoElemento(*Elemento<T> elemento) {
	this->proximoElemento = elemento;
}

template <typename T>
*Elemento<T> Elemento<T>::pegarProximoElemento() {
	return this->proximoElemento;
}

template <typename T>
void Elemento<T>::adicionaInformacao(*T informacaoRecebida) {
	this->informacao = informacaoRecebida;
}

template <typename T>
*T Elemento<T>::pegarInformacao() {
	return this->informacao;
}
#endif