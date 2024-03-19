#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilhas.h"

int main(int argc, char *argv[]){
    PILHA operandos; PILHA operadores;
    cria(&operadores); cria(&operandos);
    ITEM itemempilha; ITEM itemdesempilha; ITEM itemlook;
    int numeroUm;
    int numeroDois;
    int resultado;

    itemempilha.chave = '#';
    empilha(itemempilha, &operadores);
    char *expression = argv[1]; // recebendo itens pelo terminal

    for(int i = 0; i<strlen(expression); i++){  
        look(&operadores, &itemlook);
        printf("topo Operadores: %d ", itemlook.chave);
        look(&operandos, &itemlook);
        printf("topo operandos: %d \n", itemlook.chave);

        if(expression[i] > 48 && expression[i] < 57){
            itemempilha.chave = expression[i];
            empilha(itemempilha, &operandos);
        }else if(expression[i] == '('){
            itemempilha.chave = expression[i];
            empilha(itemempilha, &operadores);
        }else{
            look(&operadores, &itemlook);
            if(itemlook.chave > expression[i] && expression[i] == '*' ||  (itemlook.chave < expression[i] && expression[i] == '/') || itemlook.chave == '(' ){
                itemempilha.chave = expression[i];
                empilha(itemempilha, &operadores);
            }else if(itemlook.chave == ')'){
                while(1){
                    look(&operadores, &itemlook);

                    if(itemlook.chave = '(')
                        break;

                    desempilha(&operandos, &itemdesempilha);
                    numeroUm = itemdesempilha.chave - '0';
                    desempilha(&operandos, &itemdesempilha);
                    numeroDois = itemdesempilha.chave - '0';
                    desempilha(&operadores, &itemdesempilha);

                    if(itemlook.chave == 43){
                        resultado = numeroUm + numeroDois;
                    }else if(itemlook.chave == 45){
                        resultado = numeroUm - numeroDois;
                    }else if(itemlook.chave == 42){
                        resultado = numeroDois * numeroUm;
                    }else if(itemlook.chave == 47){
                        resultado = numeroDois / numeroUm;
                    }
                    itemempilha.chave = resultado;
                    empilha(itemempilha, &operandos);
                }
            }else{
                desempilha(&operandos, &itemdesempilha);
                numeroUm = itemdesempilha.chave - '0';
                desempilha(&operandos, &itemdesempilha);
                numeroDois = itemdesempilha.chave - '0';
                desempilha(&operadores, &itemdesempilha);
                
                if(itemlook.chave == 43){
                    resultado = numeroUm + numeroDois;
                }else if(itemlook.chave == 45){
                    resultado = numeroUm - numeroDois;
                }else if(itemlook.chave == 42){
                    resultado = numeroDois * numeroUm;
                }else if(itemlook.chave == 47){
                    resultado = numeroDois / numeroUm;
                }

                itemempilha.chave = resultado;
                empilha(itemempilha, &operandos);
            }
        }
    }

    look(&operadores, &itemlook);
    printf("\n\n %d ", itemlook.chave);

    return 0;
}
