#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include "ListaDeVetores.h"

void except(int);
void imprimeMenu();
void imprimirLista(ListaDeVetores*);
char* lerString();
int lerInt();

int main(int argc, char** argv) {
    
    ListaDeVetores lP;
    int op = 10;

    while (op!=0) {
        imprimeMenu();
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                try
                {
                    lP.adiciona(lerString());
                }catch(int exc)
                {
                    except(exc);
                }
                break;
            case 2:
                try
                {
                    lP.adicionaNoInicio(lerString());
                }catch(int exc)
                {
                    except(exc);
                }
                break;
            case 3:
                try
                {
                    lP.adicionaNaPosicao(lerString(),lerInt());
                }catch(int exc)
                {
                    except(exc);
                }
                break;
            
            case 4:
                try
                {
                    lP.adicionaEmOrdem(lerString());
                }catch(int exc)
                {
                    except(exc);
                }
                break;
            case 5:
                try
                {
                    char *aux = lP.retira();
                    printf("%s foi retirado da lista.\n\n",aux);
                    delete(aux);
                }catch(int exc)
                {
                    except(exc);
                }
                break;
            case 6:
                try
                {
                    char *aux = lP.retiraDoInicio();
                    printf("%s foi retirado da lista.\n\n",aux);
                    delete(aux);
                }catch(int exc)
                {
                    except(exc);
                }
                break;
            case 7:
                try
                {
                    char *aux = lP.retiraDaPosicao(lerInt());
                    printf("%s foi retirado da lista.\n\n",aux);
                    delete(aux);
                }catch(int exc)
                {
                    except(exc);
                }
                break;
             case 8:
                try
                {
                    char *aux = lP.retiraEspecifico(lerString());
                    printf("%s foi retirado da lista.\n\n",aux);
                    delete(aux);
                }catch(int exc)
                {
                    except(exc);
                }
                break;
             case 9:
                try
                {
                    imprimirLista(&lP);
                }catch(int exc)
                {
                    except(exc);
                }
                break;
            case 0:
               printf("Hasta La Vista Baby!\n");
            	break;
            default:
                printf("Sinto muito, opção inválida.\n");
                break;
        }
    }
    return 0;
}

void imprimeMenu()
{
    printf("Menu:\n\n");
    
    printf("1: Adicionar\n");
    printf("2: Adicionar no início\n");
    printf("3: Adicionar na posição\n");
    printf("4: Adicionar em ordem\n");
    printf("5: Retirar\n");
    printf("6: Retirar do início\n");
    printf("7: Retirar da posição\n");
    printf("8: Retirar específico\n");
    printf("9: Imprimir Lista\n");
    printf("0: Sair\n");
    printf("\n");
}

void except(int exc)
{
    switch(exc)
    {
        case -1:
                printf("Lista vazia!\n");
                break;
        case -2:
                printf("A lista está cheia!\n");
                break;
        case -3:
                printf("Posição invalida!\n");   
                break;
        case -4:
                printf("Elemento inexistente!\n");
                break;
        default:
                break;
                
    }
    printf("\n");
}

char* lerString()
{
    char buffer[10000];
    char *point;
    setbuf(stdin, NULL);
    printf("Digite a String a ser armazenada\n");
    scanf("%[^\n]s",buffer); //Ler strings com espaços
    setbuf(stdin, NULL);
    point = new char[strlen(buffer)+1];
    strcpy(point, buffer);
    printf("\n");
    return point;
}

int lerInt()
{
    int aux;
    printf("Digite a posição:\n");
    scanf("%i", &aux);
    printf("\n");
    return aux;
}

void imprimirLista(ListaDeVetores *p)
{
    printf("Imprimindo lista:\n\n");
       
    if(p->tamanho() < 0)
        printf("Lista vazia!\n");
    
    for(int i = 0; i < p->tamanho(); i++)
    {
        printf("%d",i);
        printf("> %s",p->elementoNaPosicao(i));
        printf("\n");
    }
    printf("\n");
}