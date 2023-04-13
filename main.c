#include <stdio.h>
#include <stdlib.h>

#include <Bicho.h>

int main()
{
    /*================== Inicia o Jogo =====================*/
    Arvore* raiz = init();
    do{
        printf("Est  pensando em algum bicho?\n \t(1 para SIM, 0 para NAO)\t\t[ ]\b\b");
        scanf("%d", &JOGAR);
        system("cls");

        if(JOGAR)
           playGame(raiz);

    }while(JOGAR);

    /*================= Encerra Aplicação ==================*/
    endGame(raiz);

    return 0;
}
