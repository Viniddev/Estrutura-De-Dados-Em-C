#if !defined(ARVORE_H)
#define ARVORE_H

typedef char CHAVE [21];

typedef struct NO_TAG *PONT;

typedef struct {
   CHAVE nome;
   double preço;
} ITEM;

typedef struct NO_TAG{
   ITEM item;
   PONT esq, dir;
}NO;

typedef PONT ARVORE;

void cria(ARVORE*);  //
int pesquisa(ITEM*, PONT*);//
int insere(ITEM, PONT*);//
int retira(ITEM, PONT*);//

void update(PONT *p);

void percorreIN(PONT p);//
void percorrePre(PONT p);//
void percorrePos(PONT p);//
void calculaAltura(PONT p); //
//pesquisa

#endif