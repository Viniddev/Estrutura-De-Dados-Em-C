#if !defined(ARVORE_H)
#define ARVORE_H

typedef char CHAVE [21];
typedef struct NO_TAG *PONT;

typedef struct {
   CHAVE nome;
   double preço;
   int status;
} ITEM;

typedef struct NO_TAG{
   ITEM item;
   int Color;
   PONT left, right;
}NO;

typedef PONT ARVORE;

#endif


//status = 0 inativo
//status = 1 ativo