#include <stdio.h>
#include <malloc.h>
#include "Fila.h"

void main(int argc, char *argv[]){
    FILA filaInicial;
    ITEM item; 

    item.chave = 15;
    cria(&filaInicial); 
    enfilera(item, &filaInicial);
    look(&filaInicial, &item);

    item.chave = 20;
    enfilera(item, &filaInicial);
    look(&filaInicial, &item);

    desenfilera(&filaInicial, &item);
    look(&filaInicial, &item);
    tamanho(filaInicial);

}