#include<stdio.h>
#include<stdlib.h>

typedef struct CELULA_TAG *PONT;
typedef struct {
    int codigo; 
    int valor;
}ITEM;

typedef struct CELULA_TAG{
    ITEM item;
    PONT prox;
}CELULA;

typedef struct{
    PONT primeiro;
    PONT ultimo;
    int tamanho;
}LISTA;

int aloca_insere(ITEM item, LISTA *lista){
    if(lista == NULL) return 0;
    PONT novoItem = (PONT)malloc(sizeof(PONT));
    novoItem->item = item;

    PONT auxContagem = (PONT)malloc(sizeof(PONT));
    auxContagem = lista->primeiro->prox;
    while(auxContagem != NULL){
        if(novoItem->item.codigo == auxContagem->item.codigo){
            auxContagem->item.valor += novoItem->item.valor;
        }else if(novoItem->item.codigo < auxContagem->item.codigo){
            novoItem->prox = auxContagem->prox;
            auxContagem->prox = novoItem;
        }else{
            auxContagem = auxContagem->prox;
        }  
    }
    return 1;
}

int pesquisa(int valor, PONT p){
    if(p == NULL) return -1;
    while(p->prox != NULL){
        if(p->item.valor == valor){
            return p->item.codigo;
        }
        p = p->prox;
    }
    return -1;
}

