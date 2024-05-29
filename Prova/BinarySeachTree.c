#include<stdio.h>
#include<stdlib.h>

typedef struct NO_TAG *PONT;

typedef struct {
    int chave; 
    int valor;
}ITEM;

typedef struct NO_TAG{
    ITEM item;
    PONT esc, dir;
}NO;

typedef PONT ARVORE;

void cria (ARVORE*);
int pesquisa(ITEM*, PONT*);
int insere(ITEM, PONT*);
int retira(ITEM, PONT*);
void percorreIn(PONT P);
void percorrePre(PONT p);
void percorrePos(PONT p);

void cria(ARVORE *arv){
    *arv = NULL;
}
int pesquisa(ITEM *item, PONT *pont){
    if(*pont == NULL) return -1;

    if(item->chave < (*pont)->item.chave)          //se a chave que busco for menor que a chave raiz
        return pesquisa(item, &(*pont)->esc);      //pesquisa na subarvore esquerda
    else if(item->chave > (*pont)->item.chave)     //senao se a chave buscada for maior que a raiz
        return pesquisa(item, &(*pont)->dir);      //pesquiso na subarvore direita

    *item = (*pont)->item;                         //se não entrei em nenhum caso acima, encontrei o elemento
    return 0;
}

int insere(ITEM item, PONT *pont){
    if(*pont == NULL){
        *pont = (PONT)malloc(sizeof(NO));
        (*pont)->item = item;
        (*pont)->esc = NULL;
        (*pont)->dir = NULL;
        return 0;
    }

    if(item.chave < (*pont)->item.chave)
        return insere(item, &(*pont)->esc);
    if(item.chave > (*pont)->item.chave)
        return insere(item, &(*pont)->dir);
        
    return -1;
}