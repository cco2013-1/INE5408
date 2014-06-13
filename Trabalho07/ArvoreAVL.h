/*
 * File:   ArvoreAVL.h
 * Author: matheus
 *
 * Created on 13 de Junho de 2014, 08:15
 */

#ifndef ARVOREAVL_H
#define	ARVOREAVL_H

#include<string>
using std::string;

template <typename T>
class ArvoreAVL{
    struct Nodo{
        Nodo *esquerda, *direita;
        T informacao;


        Nodo(const T& t):  //lista de inicialização
            esquerda(0),
            direita(0),
            informacao(t),
            altura(0){

        }
        void atualizarAltura(){
            altura = maximo(esquerda->pegarAltura(),direita->pegarAltura())+1;
        }
        Nodo* maior(){  //retorna o maior Nodo da estrutura
            if(rigth == 0)return this;
            return direita->maior();
        }
        int pegarAltura() const{ //o const assegura que nada será mudado na estrutura ao executar este método
            if(this == 0) return -1;
            return altura;
        }
        Nodo *rotacaoEsquerda(){
            Nodo *raiz = direita;
            direita = direita->esquerda;
            raiz->esquerda = this;
            atualizarAltura();
            raiz->atualizarAltura();
            return raiz;
        }
        Nodo *rotacaoDireita(){
            Nodo*raiz = esquerda;
            esquerda = esquerda->direita;
            raiz->direita = this;
            atualizarAltura();
            raiz->atualizarAltura();
            return raiz;
        }
        Nodo *rotacaoDuplaEsquerda(){
            direita = direita->rotacaoDireita();
            return rotacaoEsquerda();
        }
        Nodo *rotacaoDuplaDireita(){
            esquerda = esquerda->rotacaoEsquerda();
            return rotacaoDireita();
        }
        string toString(){
            if(this == 0) {
                return"@";
            }
            return "("+esquerda->toString()+")"+informacao+"("+direita->toString()+")";
        }
    private:
        int altura;
        int maximo(int a, int b){
            if(a>b) return a;
            return b;
        }
    };
public:
    ArvoreAVL():raiz(0){
    }
    void inserir(const T& t){
        raiz = inserir(t, raiz);
    }
    void deletar(const T& t){
        raiz = deletar(t, raiz);
    }
    string toString(){
        return raiz->toString();
    }
private:
    Nodo *raiz;
    Nodo *inserir(const T& t, Nodo *raiz){
        if(raiz == 0){
            return new Nodo(t);
        }
        if(t < raiz->informacao){ //esquerda
            raiz-> esquerda = inserir(t, raiz->esquerda);
            if(raiz->esquerda->pegarAltura() - raiz->direita->pegarAltura() > 1){ //testando se houve desbalanceamento
                if(t < raiz->esquerda->informacao){ // testando se o desbalanceamento foi do tipo linear a esquerda "/"
                    raiz = raiz->rotacaoDireita();
                }else{ //testando se o desbalanceamento foi do tipo zigue-zague a esquerda "<"
                    raiz = raiz->rotacaoDuplaDireita();
                }
            }
        }
        else if(t > raiz->informacao){ //direta
            raiz -> direita = inserir(t, raiz->direita);
            if(raiz->direita->pegarAltura() - raiz->esquerda->pegarAltura() > 1){ //testando se houve desbalanceamento
                if(t > raiz->direita->informacao){ //testando se o desbalancemanto foi do tipo linear a direita "\"
                    raiz = raiz->rotacaoEsquerda();
                }else{ //testando se o desbalancemento foi do tipo zigue-zague a direita ">"
                    raiz = raiz->rotacaoDuplaEsquerda();
                }
            }
        }
        raiz->atualizarAltura();
        return raiz;
    }
    Nodo *deletar(const T& t, Nodo *raiz){
        if(raiz == 0){ //informacão não existe na árvore
            return raiz;
        }
        if(t < raiz->informacao){  //esquerda
            raiz->esquerda = deletar(t, raiz->esquerda);
        }
        else if(t > raiz->informacao){ 
            raiz->direita = deletar(t, raiz->direita);
        }
        else{ //é esse que eu quero deletar!!! 
            if(raiz->esquerda == 0 && raiz->direita == 0){ //se for uma folha  
                delete raiz;
                return 0;
            }
            else if(raiz->esquerda == 0 || raiz->direita == 0){ //tem somente um filho
                Nodo *auxiliar = (raiz->esquerda ? raiz->esquerda : raiz->direita);
                delete raiz;
                raiz = auxiliar;
                
            }
            else{ //tem mais filhos
                Nodo *auxiliar = raiz->esquerda->maior();
                raiz->informacao = auxiliar->informacao;
                raiz->esquerda = deletar(auxiliar->informacao, raiz->esquerda);
            }
        }
        raiz->atualizarAltura();
        return raiz;
    }
};

#endif	/* ARVOREAVL_H */
