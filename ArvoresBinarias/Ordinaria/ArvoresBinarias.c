#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArvoresBinarias.h"

void main(int argc, char *argv[])
{

    
}

void cria(PONT *p){
    *p = NULL;
}

int insere(ITEM x, PONT *p){
    if(*p == NULL){
        *p = (PONT)malloc(sizeof(NO));
        (*p)->item = x;
        (*p)->esq = NULL;
        (*p)->dir = NULL;
        return 0;
    }

    int retornoStrComp = strncmp(x.nome, (*p)->item.nome, 20);
    if(retornoStrComp == -1)
        return insere(x, &(*p)->esq);
    if(retornoStrComp == 1)
        return insere(x, &(*p)->dir);

    return -1;
}

int pesquisa(ITEM *x, PONT *p){
    if(*p==NULL) return -1;

    int retornoStrComp = strncmp(x->nome, (*p)->item.nome, 20);

    if(retornoStrComp == -1)
        return pesquisa(x, &(*p)->esq);
    if(retornoStrComp == 1)
        return pesquisa(x, &(*p)->dir);

    *x = (*p)->item;
    return 0;
}

int update(ITEM x, PONT *P){
    //bloco não achou
    if(*P == NULL) return -1;

    //bloco de comparação na arvore binaria
    int retornoStrnComp = srtncomp(x.nome, (*P)->item.nome, 20);
    if(retornoStrnComp == -1)
        return update(x, &(*P)->esq);
    if(retornoStrnComp == 1)
        return update(x, &(*P)->dir);

    //se for o item
    (*P)->item.preço = x.preço;
    return 0;
}

int retira(ITEM x, PONT *p){
    PONT aux;

    if(*p == NULL)
        return -1;


    int retornoStrComp = strncmp(x.nome, (*p)->item.nome, 20);

    if(retornoStrComp == -1)
        return retira(x, &(*p)->esq);
    if(retornoStrComp == 1)
        return retira(x, &(*p)->dir);
   
    if((*p)->dir == NULL){
        aux = *p;
        *p = (*p)->esq;
        free(aux);
        return 0;

        /*
            se o ponteiro que aponta para a direita é nulo
            criamos um ponteiro auxiliar que aponta para o elemento na esquerda
            atribuimos o elemento da esquerda ao ponteiro inicial
            e limpamos o auxiliar;

            trocamos de lugar o elemento filho com o pai.
        */
    }

    if((*p)->esq == NULL){
        aux = *p;
        *p = (*p)->dir;
        free(aux);
        return 0;
    }

    antecessor(*p, &(*p)->esq);
    /*
        *p           ::   é o nó que ele tenta remover
        &(*p)->esq   ::   é endereço de memoria do ponteiro que aponta para a esquerda
    */

    return 0;
}


void antecessor(PONT q, PONT *r){
    if((*r)->dir != NULL){
        return antecessor(q, &(*r)->dir);
    }


    q->item = (*r)->item;
    q = *r;
    *r = (*r)->esq;
    free(q);
}


void percorreIn(PONT p){
    if(p != NULL)
    {
        percorreIn(p->esq);
        printf("%d \n", p->item.nome);
        percorreIn(p->dir);
    }
}

void percorrePre(PONT p){
    if(p != NULL)
    {
        printf("%d \n", p->item.nome);
        percorreIn(p->esq);
        percorreIn(p->dir);
    }
}

void percorrePos(PONT p){
    if(p != NULL)
    {
        percorreIn(p->esq);
        percorreIn(p->dir);
        printf("%d \n", p->item.nome);
    }
}


/*
    para descobrirmos o tamanho da arvore utilizaremos chamadas
    recursivas para a subarvore esquerda e direita. a altura da
    arvore é calculada a partir da maior distancia entre a raiz 
    e alguma folha acrescido de 1 (pois consideramos a raiz)

    Passo 1: Percorrer somando a altura e retornando um valor util;
    Passo 2: Comparar altura maxima da subarvore esquerda e direita;
    Passo 3: Retornar esse valor toral;
*/

int calculaAltura(PONT p){
    if(p != NULL){
        int altEsq, altDir, maiorAlt;

        altEsq = calculaAltura(p->esq);
        altDir = calculaAltura(p->dir);

        if(altDir >= altEsq){
            maiorAlt = altDir;
        }else{
            maiorAlt = altEsq;
        }

        return maiorAlt + 1;
    }
    return 0;
}


