#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <Bicho.h>
#include <Caracteres.h>

/** -=-=-=-=Funções encapsuladas=-=-=-=- */

void novoAnimal(Arvore *animal);

/** =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */


/**
    loop principal da aplicação que caminha na árvore à procura do animal. Ao encontrá-lo é feito a interação com o usuário
    a fim de saber se o programa acertou ou não.
*/

void playGame(Arvore* no){
    int possuiCaracteristica, ehAnimal;

    while(no->tipo != TIPO_ANIMAL){

        // Então é um nó do tipo Caracteristica
        printf("O animal que vocˆ est  pensando possui esta caracter¡stica: %s\n \t(1 para SIM, 0 para NAO)\t\t[ ]\b\b", no->info);
        scanf("%d", &possuiCaracteristica);
        if (possuiCaracteristica && no->esq != NULL)
            no = no->esq;
        if (!possuiCaracteristica && no->dir != NULL)
            no = no->dir;
        printf("\n");
    }
    //neste momento o nó é de tipo animal
    printf("\nAprop¢sito, o animal que vocˆ est  pensando ‚ o: %s?\n \t(1 para SIM, 0 para NAO)\t\t[ ]\b\b", no->info);
    scanf("%d", &ehAnimal);

    if(ehAnimal){
        printf("\nAdivinhei mais uma! Sou supremo!\n");
        return;
    }
    else
        novoAnimal(no);
}

/**
    Modifica a árvore inserindo o novo animal e a nova caracteristica propostos pelo usuário
*/

void novoAnimal(Arvore* animal) {
    int seria;
    char animalPensado[STRMAX], carac[STRMAX];

    printf("\nEntÆo me diga. Qual o animal que estava pensando?\n-> ");
    leia(animalPensado, STRMAX);

    printf("\nMe diga uma caracter¡stica que diferencie %s de %s:\n-> ", animal->info, animalPensado);
    leia(carac, STRMAX);

    printf("\nSe o animal fosse %s ele seria/teria %s ?\n \t(1 para SIM, 0 para NAO)\t\t[ ]\b\b", animal->info, carac);
    scanf("%d", &seria);

    /*
        Cria dois novos nós que serão inseridos na árvore. Um guarda o backup do animal que foi sugerido pelo sistema,
        o outro recebe o animal pensado pelo usuário. O nó atual (de tipo de animal) é convertido para tipo caracteristica
        e receberá a caracteristica sugerida pelo usuário. Depois é feito a inserção dos nós na árvore (O animal que possui
        a caracteristica é inserido à esquerda e o que não a possui à direita).
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
    Salva as alterações da árvore no banco de dados e desaloca a memória utilizada
*/

void endGame(Arvore *raiz){
    system("cls");

    printf("Salvando informa‡äes...\n");
    if(!SalvaBaseDeDados(raiz)){
        printf("\aErro ao salvar dados!");
        exit(0);
    }
    printf("\tSucesso!");

    printf("\n\nLimpando cache...\n");
    if(!LimpaArvore(raiz)){
        printf("\aErro ao acessar  rvore!");
        exit(0);
    }
    printf("\tSucesso!");

    printf("\n\n\t\t\t\tFim de Aplica‡Æo\n");
}
