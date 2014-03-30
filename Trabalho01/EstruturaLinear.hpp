/**
 * Universidade Federal de Santa Catarina
 * Centro Tecnológico
 * Departamento de Informática e Estatística
 * Ciências da Computação
 * INE5408 - Estruturas de Dados
 *
 * Trabalho 01 - Implementação de pilhas com Vetor em C++
 * Alunos: Antonio Vinicius Gomes Teixeira  Matrícula: 13100731
 *         Matheus Ben-Hur de Melo Leite    Matrícula: 13100765
 *
 * EstruturaLinear.hpp
 */
#define TAMANHO_MAX 100
#define ERRO_ESTRUTURA_CHEIA -1
#define ERRO_ESTRUTURA_VAZIA -2

template<typename T>
class EstruturaLinear {

public:
    EstruturaLinear();
    ~EstruturaLinear();
    void inserir(T elemento);
    virtual T extrair() = 0;
    bool estaVazia();
    bool estaCheia();
protected:
    T dados[TAMANHO_MAX];
    int posicaoAtual;

};

template<typename T>
EstruturaLinear<T>::EstruturaLinear() {
	posicaoAtual = -1;
}

template<typename T>
EstruturaLinear<T>::~EstruturaLinear() {

}

template<typename T>
bool EstruturaLinear<T>::estaVazia() {
    return posicaoAtual == -1;
}

template<typename T>
bool EstruturaLinear<T>::estaCheia(){
    return posicaoAtual == TAMANHO_MAX - 1;
}

template<typename T>
void EstruturaLinear<T>::inserir(T elemento) {
    if(!estaCheia()) {
    	dados[++posicaoAtual] = elemento;
    	return;
    }
    throw(ERRO_ESTRUTURA_CHEIA);
}
