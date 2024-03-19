#if !defined(PILHA_H)
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct CELULA_TAG *PONT;

typedef struct{
    int chave;
    //more attributes
} ITEM;

typedef struct CELULA_TAG{
    ITEM item;
    PONT prox;
    //more attributes
} CELULA;

typedef struct{
    PONT fundo, topo;
    int tamanho;
    //more attributes
} PILHA;

int vazia(PILHA);
void cria(PILHA*);
int tamanho(PILHA);
int push(ITEM, PILHA*);
int pop(PILHA*, ITEM*);
int look(PILHA*, ITEM*);

void cria(PILHA *pilha){
    pilha->topo = (PONT)malloc(sizeof(CELULA));
    pilha->fundo = pilha->topo;
    pilha->topo->prox = NULL;
    pilha->tamanho = 0;
}

int vazia(PILHA pilha){
    return (pilha.topo == pilha.fundo);
}
int push(ITEM x, PILHA *pilha){
    PONT aux;
    
    aux = (PONT)malloc(sizeof(CELULA));
    pilha->topo->item = x;
    aux->prox = pilha->topo;
    pilha->topo = aux;
    pilha->tamanho++;
    return 0;
}
int pop(PILHA *pilha, ITEM *item){
    PONT q;

    if(vazia(*pilha))
        return -1;
    
    q = pilha->topo;
    pilha->topo = q->prox;
    *item = q->prox->item;

    free(q);
    pilha->tamanho--;
    return 0;
}

int look(PILHA *pilha, ITEM *item){
    if(vazia(*pilha))
        return -1;

    *item = pilha->topo->prox->item;
    return 0;
}

int tamanho(PILHA pilha){
    return pilha.tamanho;
}


#endif