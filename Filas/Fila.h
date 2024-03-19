#if !defined(FILA_H)
#define FILA_H

#include <stdio.h>
#include <malloc.h>

// Ponteiro para celula
typedef struct CELULA_TAG *PONT;

// Item que armazena os dados relevantes
typedef struct {
    int chave;
} ITEM;

typedef struct CELULA_TAG {
    ITEM item;
    PONT proximo;
} CELULA;

typedef struct FILA {
    PONT primeiro, ultimo;
    int tamanho;
} FILA;

void cria(FILA*);
int vazia(FILA*);
int enfilera(ITEM, FILA*);
int desenfilera(FILA*, ITEM*);
int tamanho(FILA);
int look(FILA*, ITEM*);

void cria(FILA* fila){
    //criar a fila vazia
    fila->primeiro = (PONT)malloc(sizeof(CELULA));
    fila->primeiro->item.chave = 0;
    fila->ultimo = fila->primeiro;
    fila->primeiro->proximo = NULL;
    fila->tamanho = 0;
}
int vazia(FILA *fila){
    //verificar tamanho
    return fila->primeiro == fila->ultimo;
}
int enfilera(ITEM item, FILA* fila){
    //adiciona um elemento no final da fila
    PONT auxiliar = (PONT)malloc(sizeof(CELULA));

    fila->ultimo->proximo = auxiliar;
    fila->ultimo = auxiliar;
    fila->ultimo->item = item;
    fila->ultimo = fila->ultimo;
    fila->tamanho++;

    return 1;
}
int desenfilera(FILA* fila, ITEM* item){
    //removemos um item da primeira casa
    PONT excluido;

    if(vazia(fila))
        return -1;
    
    *item = fila->primeiro->proximo->item;
    excluido = fila->primeiro;
    fila->primeiro = fila->primeiro->proximo;
    fila->tamanho--;

    free(excluido);

    return 1;
}
int tamanho(FILA fila){
    printf("\n Tamanho Fila > %d: ", fila.tamanho);
    return fila.tamanho;
}
int look(FILA *fila, ITEM *item){
    printf("\n Ultimo item > %d ", fila->primeiro->item.chave);
    return fila->primeiro->item.chave;
}

#endif