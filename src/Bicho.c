#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <Bicho.h>
#include <Caracteres.h>

/** -=-=-=-=Fun��es encapsuladas=-=-=-=- */

void novoAnimal(Arvore *animal);

/** =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */


/**
    loop principal da aplica��o que caminha na �rvore � procura do animal. Ao encontr�-lo � feito a intera��o com o usu�rio
    a fim de saber se o programa acertou ou n�o.
*/

void playGame(Arvore* no){
    int possuiCaracteristica, ehAnimal;

    while(no->tipo != TIPO_ANIMAL){

        // Ent�o � um n� do tipo Caracteristica
        printf("O animal que voc� est� pensando possui esta caracter�stica: %s\n \t(1 para SIM, 0 para NAO)\t\t[ ]\b\b", no->info);
        scanf("%d", &possuiCaracteristica);
        if (possuiCaracteristica && no->esq != NULL)
            no = no->esq;
        if (!possuiCaracteristica && no->dir != NULL)
            no = no->dir;
        printf("\n");
    }
    //neste momento o n� � de tipo animal
    printf("\nAprop�sito, o animal que voc� est� pensando � o: %s?\n \t(1 para SIM, 0 para NAO)\t\t[ ]\b\b", no->info);
    scanf("%d", &ehAnimal);

    if(ehAnimal){
        printf("\nAdivinhei mais uma! Sou supremo!\n");
        return;
    }
    else
        novoAnimal(no);
}

/**
    Modifica a �rvore inserindo o novo animal e a nova caracteristica propostos pelo usu�rio
*/

void novoAnimal(Arvore* animal) {
    int seria;
    char animalPensado[STRMAX], carac[STRMAX];

    printf("\nEnt�o me diga. Qual o animal que estava pensando?\n-> ");
    leia(animalPensado, STRMAX);

    printf("\nMe diga uma caracter�stica que diferencie %s de %s:\n-> ", animal->info, animalPensado);
    leia(carac, STRMAX);

    printf("\nSe o animal fosse %s ele seria/teria %s ?\n \t(1 para SIM, 0 para NAO)\t\t[ ]\b\b", animal->info, carac);
    scanf("%d", &seria);

    /*
        Cria dois novos n�s que ser�o inseridos na �rvore. Um guarda o backup do animal que foi sugerido pelo sistema,
        o outro recebe o animal pensado pelo usu�rio. O n� atual (de tipo de animal) � convertido para tipo caracteristica
        e receber� a caracteristica sugerida pelo usu�rio. Depois � feito a inser��o dos n�s na �rvore (O animal que possui
        a caracteristica � inserido � esquerda e o que n�o a possui � direita).
    */

    Arvore *backupAnimal = CriaNo();
    Arvore *novoAnimal = CriaNo();
    backupAnimal = InsereAnimal(backupAnimal, animal->info);
    novoAnimal = InsereAnimal(novoAnimal, animalPensado);

    animal = InsereCaracteristica (animal, carac);

    if (!seria){
        animal->dir = backupAnimal;
        animal->esq = novoAnimal;
    }
    else{
        animal->dir = novoAnimal;
        animal->esq = backupAnimal;
    }
}

/**
    Salva as altera��es da �rvore no banco de dados e desaloca a mem�ria utilizada
*/

void endGame(Arvore *raiz){
    system("cls");

    printf("Salvando informa��es...\n");
    if(!SalvaBaseDeDados(raiz)){
        printf("\aErro ao salvar dados!");
        exit(0);
    }
    printf("\tSucesso!");

    printf("\n\nLimpando cache...\n");
    if(!LimpaArvore(raiz)){
        printf("\aErro ao acessar �rvore!");
        exit(0);
    }
    printf("\tSucesso!");

    printf("\n\n\t\t\t\tFim de Aplica��o\n");
}
