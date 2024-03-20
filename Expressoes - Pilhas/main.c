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
    int expressaoInvalida = 0;
    itemempilha.chave = '#';
    empilha(itemempilha, &operadores);
    char *expression = argv[1];

    for(int i = 0; i<strlen(expression); i++){  
        look(&operadores, &itemlook);

        if(expression[i] >= '0' && expression[i] <= '9') {
            itemempilha.chave = (expression[i] - '0');
            push(itemempilha, &operandos);
        } else if(expression[i] == '(') {
            itemempilha.chave = expression[i];
            push(itemempilha, &operandos);
        } else if(((itemlook.chave == '+' || itemlook.chave == '-' || itemlook.chave == '#') && expression[i] == '*') ||
        ((itemlook.chave == '+' || itemlook.chave == '-' || itemlook.chave == '#') && expression[i] == '/')) {
            itemempilha.chave = expression[i];
            push(itemempilha, &operadores);
        } else if(expression[i] == '+' || expression[i] == '-') {
            itemempilha.chave = expression[i];
            push(itemempilha, &operadores);
        } else if(expression[i] == ')') {
            while(1) {
                look(&operadores, &itemlook);

                if(itemlook.chave == '(') {
                    break;
                }

                if(itemlook.chave == '#') {
                    printf("expression invalida!");
                    expressaoInvalida = 1;
                    break;
                }

                pop(&operandos, &itemdesempilha);
                numeroUm = itemdesempilha.chave;
                pop(&operandos, &itemdesempilha);
                numeroDois = itemdesempilha.chave;
                pop(&operadores, &itemdesempilha);

                if(itemdesempilha.chave == '*') {
                    resultado = numeroUm * numeroDois;
                } else if(itemdesempilha.chave == '/') {
                    resultado = numeroDois / numeroUm;
                } else if(itemdesempilha.chave == '+') {
                    resultado = numeroUm + numeroDois;
                } else if(itemdesempilha.chave == '-') {
                    resultado = numeroDois - numeroUm;
                }

                itemempilha.chave = resultado;
                push(itemempilha, &operandos)               ;
            }
        }

        if(expressaoInvalida == 1) {
            break;
        }

         while(itemlook.chave != '#') {
            pop(&operandos, &itemdesempilha);
            numeroUm = itemdesempilha.chave;
            pop(&operandos, &itemdesempilha);
            numeroDois = itemdesempilha.chave;
            pop(&operadores, &itemdesempilha);

            if(itemdesempilha.chave == '+') {
                resultado = numeroUm + numeroDois;
                itemempilha.chave = resultado;
            } else if(itemdesempilha.chave == '-') {
                resultado = numeroDois - numeroUm;
            } else if(itemdesempilha.chave == '*') {
                resultado = numeroUm * numeroDois;
            } else if(itemdesempilha.chave == '/') {
                resultado = numeroDois / numeroUm;
            }

            look(&operadores, &itemlook);
            itemempilha.chave = resultado;
            push(itemempilha, &operandos);   
        }
    pop(&operandos, &itemdesempilha);
    printf("O resultado da operacao e: %d", itemdesempilha.chave);
    return 0;
}
