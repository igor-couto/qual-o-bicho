#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <Caracteres.h>

/**
    Função que converte uma string para o padrão adotado:
        - Primeira letra MAIÚSCULA, o restante minúscula;
        - Números viram letras;
        - letras acentuadas são aceitas;
        - Só é permito ainda hífens e espaços.
*/

char* padronizaString(char *str, int tam){
    int i;
    for(i = 0; i < tam - 1; i++){
        //se o caracter é diferente de 'espaço em branco', de 'hífen (-)' e de 'letras normais e acentuadas'
        if(str[i] == 13 || (str[i] > 32 && str[i] < 45) || (str[i] > 45 && str[i] < 65) ||
          (str[i] > 90 && str[i] < 97) || (str[i] > 122 && str[i] < 192))
        {
            if(str[i] >= 48 && str[i] <= 57){   //numeros (0-9)
                switch(str[i]){
                    case '1': str[i] = 'I'; break;
                    case '2': str[i] = 'Z'; break;
                    case '3': str[i] = 'E'; break;
                    case '4': str[i] = 'A'; break;
                    case '5': str[i] = 'S'; break;
                    case '6': str[i] = 'G'; break;
                    case '7': str[i] = 'T'; break;
                    case '8': str[i] = 'B'; break;
                    case '9': str[i] = 'P'; break;
                    case '0': str[i] = 'O'; break;
                    default:; //default
                }
            }
            else    return 0;
        }
        if(i > 0 && str[i] >= 65 && str[i] <= 90)   //se letra maiuscula no meio da palavra
            str[i] += 32;
        else if(i == 0 && str[i] >= 97 && str[i] <= 122)    //se letra miniscula no primeiro caracter
            str[i] -= 32;
    }
    str[i] = '\0';
    return str;
}

/**
    Procedimento para ler uma string e padronizá-la
*/

void leia(char *string, int STRMAX){
    fflush(stdin);
    fgets(string, STRMAX, stdin);
    if(padronizaString(string, strlen(string)) == 0){
        printf("\aFoi encontrado um caracter inv lido!\nPor favor utilize apenas Letras, Espa‡os e/ou H¡fens!\n\n");
        exit(0);
    }
}
