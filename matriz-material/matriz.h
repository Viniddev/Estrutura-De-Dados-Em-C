#if !defined(MATRIZ_H)
#define MATRIZ_H

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int nLinhas, nColunas;
  LISTA *linha;
  LISTA *coluna;
} MATRIZ;


void leMatriz(MATRIZ*); 
int vaziaMatriz(MATRIZ*); 
void criaMatriz(MATRIZ*); 
void apagaMatriz(MATRIZ*); 
void imprimeMatriz(MATRIZ*); 
void somaMatriz(MATRIZ*,MATRIZ*,MATRIZ*);
void insereMatriz(MATRIZ*,int,int,double);
void multiplicaMatriz(MATRIZ*,MATRIZ*,MATRIZ*);


void criaMatriz(MATRIZ *mat){
  printf("criaMatriz \n");
  //criar uma lista para linha
  //criar uma lista para coluna
}

int vaziaMatriz(MATRIZ *mat){
  printf("vaziaMatriz ");
  //inicializamos matriz com valor nulo
  return 0;
}

void leMatriz(MATRIZ *mat){
  printf("leMatriz ");
  float valor = 0;
  int nlinhas = 0; int ncolunas = 0;
  int linha = 0; int coluna = 0; 

  scanf("%d %d", &nlinhas, &ncolunas);
  printf("linhas: %d | colunas: %d \n\n", nlinhas, ncolunas);

  //chamamos a cria matriz aqui

  while(linha >= 0){
    scanf("%d %d %f", &linha, &coluna, &valor);
    printf("%i | %i | %f \n", linha, coluna, valor);
  }
}

void apagaMatriz(MATRIZ *mat){
  printf("apagaMatriz ");
}

void imprimeMatriz(MATRIZ *mat){
  printf("imprimeMatriz ");
}

void somaMatriz(MATRIZ *mat1, MATRIZ *mat2, MATRIZ *matResult){
  printf("somaMatriz ");
}

void multiplicaMatriz(MATRIZ *mat1, MATRIZ *mat2, MATRIZ *matResult){
  printf("somaMatriz ");
}

void insereMatriz(MATRIZ* mat, int line, int col, double value){
  printf("insereMatriz ");
}

#endif
