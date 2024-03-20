if(itemlook.chave > expression[i] && expression[i] == '\*' || (itemlook.chave < expression[i] && expression[i] == '/') || itemlook.chave == '(' ){
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
