#if !defined(PILHA_H)
#define PILHA_H

#define TIPO_VARIAVEL(variavel) _Generic((variavel), \
    int: "int", \
    float: "float", \
    double: "double", \
    char: "char", \
    default: "unknown" \
)

#include <stdio.h>
#include <stdlib.h>
typedef struct CELULA_TAG *PONT;

typedef struct{
    char chave;
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
void empilha(ITEM, PILHA*);
int desempilha(PILHA*, ITEM*);
int look(PILHA*, ITEM*);

void cria(PILHA *pilha){
    pilha->topo = (PONT) malloc(sizeof(CELULA));
    pilha->fundo = pilha->topo;
    pilha->topo->prox = NULL;
    pilha->tamanho = 0;
}

int vazia(PILHA pilha){
    return (pilha.topo == pilha.fundo);
}

void empilha(ITEM item, PILHA *pilha){
    PONT auxiliar;
    auxiliar = (PONT) malloc(sizeof(CELULA));

    pilha->topo->item = item;
    auxiliar->prox = pilha->topo;
    pilha->topo = auxiliar;
    pilha->tamanho++;

}

int desempilha(PILHA *pilha, ITEM *item){
    PONT itemExcluido;

    if(vazia(*pilha))
        return -1;

    itemExcluido = pilha->topo;
    *item = pilha->topo->item;
    pilha->topo = pilha->topo->prox;
    pilha->tamanho--;
    free(itemExcluido);
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