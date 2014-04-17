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
	Elemento<T> *proximoElemento;
	T *informacao;

};
#endif