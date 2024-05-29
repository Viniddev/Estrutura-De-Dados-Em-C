
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Left_Leaving_Red_Black_Tree.h"

void main(int argc, char *argv[]){

}

int isRed(PONT *x){
    if(*x == NULL) return -1;
    return ((*x)->Color == 1);
}

int pesquisa(ITEM *item, PONT *x){
    if(*x==NULL) return -1;

    int retornoStrComp = strncmp(item->nome, (*x)->item.nome, 20);

    if(retornoStrComp == -1)
        return pesquisa(item, &(*x)->left);
    if(retornoStrComp == 1)
        return pesquisa(item, &(*x)->right);

    if(retornoStrComp == 0 && (*x)->item.status == 1)
        *item = (*x)->item;    
    
    return 0;
}

int deletion(ITEM *item, PONT *x){
     if(*x==NULL) return -1;

    int retornoStrComp = strncmp(item->nome, (*x)->item.nome, 20);
    if(retornoStrComp == -1)
        return pesquisa(item, &(*x)->left);
    if(retornoStrComp == 1)
        return pesquisa(item, &(*x)->right);

    if(retornoStrComp == 0 && (*x)->item.status == 1)
        (*x)->item.status = 0;    
    
    return 0;
}

int minimo(PONT *x){
    if(*x == NULL) return -1;

    PONT aux = (PONT)malloc(sizeof(PONT));
    aux = x;
    while(aux != NULL){
        aux = aux->left;
    }

     if(aux == NULL) 
        return -1;
    else 
        return aux->item.preço;
}

PONT insertNode(PONT *h, ITEM item){
    if(*h == NULL) {
        *h = (PONT)malloc(sizeof(PONT));
        (*h)->right = NULL;
        (*h)->left = NULL;
        (*h)->Color = 1;
        (*h)->item = item;
        return 0;
    }

    if((*h)->left->Color == 1 && (*h)->right->Color == 1){
        colorFlip(h);
    }

    int comp = strncmp(item.nome, (*h)->item.nome, 21);
    if(comp == 0 && (*h)->item.status == 1){
        (*h)->item.preço = item.preço;
    }else if(comp == 0 && (*h)->item.status == 0){
        (*h)->item.preço = item.preço;
        (*h)->item.status = 1;
    }
    if(comp < 0 && (*h)->item.status == 1){
        (*h)->right = insertNode(&(*h)->right, item);
    }else if(comp > 0 && (*h)->item.status == 1){
        (*h)->left = insertNode(&(*h)->left, item);
    }

    if((*h)->right->Color == 1){
        h = rotateLeft(h);
    }
    if((*h)->left->Color == 1 && (*h)->left->left->Color == 1){
        h = rotateRight(h);
    }

    return h;
}

PONT colorFlip(PONT h){
    if(h == NULL) return -1;

    if((*h).Color == 1){
        (*h).Color == 0;
    } else {
        (*h).Color = 1;
    }
    if((*h).left->Color == 1){
        (*h).left->Color == 0;
    } else {
        (*h).left->Color = 1;
    }
    if((*h).right->Color == 1){
        (*h).right->Color == 0;
    } else {
        (*h).right->Color = 1;
    }
}

PONT rotateLeft(PONT h){
    PONT x  = h->right;
    x->right = x->left;
    x->left = h;
    x->Color = x->left->Color;
    x->left->Color = 1;
    return x;
}

PONT rotateRight(PONT h){
    PONT x = h->left;
    h->left = x->right;
    x->right = h;
    x->Color = x->right->Color;
    x->right->Color = 1;
    return x;
}