#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <Arvore.h>

/** -=-=-=-=Funções encapsuladas=-=-=-=- */

Arvore* CarregaBaseDeDados(Arvore *arv);
Arvore* LeDado(Arvore *arv, FILE *arq);
void EscreveDado(Arvore *arv, FILE *arq);
void Libera(Arvore *raiz);

/** =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */


/**
    Função para alocar memória para um novo nó
*/

Arvore* CriaNo()
{
    Arvore *arv = (Arvore*) malloc(sizeof(Arvore));
    arv->dir = NULL;
    arv->esq = NULL;
    strcpy(arv->info, "");
    arv->tipo = 1;          //tipo padrão definido como caracteristica

    return arv;
}

/**
    Criação e inicialização da arvore e leitura do banco de dados
*/

Arvore* init()
{
    Arvore *arv = CriaNo();
    printf("Lendo informa‡äes...");
    arv = CarregaBaseDeDados(arv);
    system("cls");
    return arv;
}

/**
    Cria o ponteiro de leitura para o arquivo de texto (banco de dados) e chama a função "LeDado".
*/

Arvore* CarregaBaseDeDados(Arvore *arv)
{
    FILE *arq;
    arq = fopen("media/dados.txt", "r");
    if(arq == NULL)
    {
        printf("Erro ao carregar base de dados!\n");
        exit(0);
    }
    arv = LeDado(arv, arq);
    return arv;
}

/**
    Função para preencher a árvore passada como parâmetro com o conteudo do banco de dados (arquivo txt)
*/

Arvore* LeDado(Arvore *arv, FILE *arq)
{
    if(!feof(arq))
    {
        char info[STRMAX];
        fgets(info, STRMAX, arq);

        if(strcmp(info, "NULL\n"))
        {
            char tipoch;
            int tipo;

            tipoch = info[strlen(info)-2];
            tipo = (tipoch == '1') ? TIPO_CARACTERISTICA : TIPO_ANIMAL; // 1 : 0
            info[strlen(info)-3] = '\0';

            if(tipo == TIPO_CARACTERISTICA)
                arv = InsereCaracteristica(arv, info);
            else
                arv = InsereAnimal(arv, info);

            arv->esq = CriaNo();
            arv->dir = CriaNo();
            arv->esq = LeDado(arv->esq, arq);
            arv->dir = LeDado(arv->dir, arq);

            return arv;
        }
    }
}

/**
    Gerencia o banco de dados (arquivo texto) para se iniciar a alteração no mesmo
*/

int SalvaBaseDeDados(Arvore *arv)
{
    FILE *arq;
    arq = fopen("media/dados.txt", "w");
    if(arq == NULL)
    {
        printf("Erro ao salvar base de dados!\n");
        exit(0);
    }

    EscreveDado(arv, arq);
    if(arv == NULL)
        return 0;
    return 1;
}

/**
    Escreve os dados da árvore alterada no banco de dados (arquivo texto)
*/

void EscreveDado(Arvore *arv, FILE *arq)
{
    if(arv != NULL)
    {
        fprintf(arq, "%s %d\n", arv->info, arv->tipo);
        EscreveDado(arv->esq, arq);
        EscreveDado(arv->dir, arq);
    }
    else
        fprintf(arq, "NULL\n");
}

/**
    Define o nó passado por parâmetro como de tipo caracteristica e insere a mesma na info do nó
*/

Arvore* InsereCaracteristica (Arvore *no, char* info)
{
    strcpy(no->info,info);
    no->tipo = TIPO_CARACTERISTICA;
    return no;
}

/**
    Define o nó passado por parâmetro como de tipo animal e insere o mesmo na info do nó
*/

Arvore* InsereAnimal (Arvore *no, char* info)
{
    strcpy(no->info,info);
    no->tipo = TIPO_ANIMAL;
    return no;
}

/**
    Verifica se o nó passado está vazio
*/

int ArvVazia (Arvore *arv)
{
    return (arv == NULL) ? 1 : 0;
}

/**
    Gerencia a desalocagem de memória da árvore
*/

int LimpaArvore(Arvore *raiz){
    if(ArvVazia(raiz))
        return 0;
    Libera(raiz);
    return 1;
}

/**
    Desaloca a memória utilizada pela árvore da aplicação
*/

void Libera(Arvore *raiz){
    if (raiz != NULL){
        if(raiz->esq == NULL && raiz->dir == NULL)
            free(raiz);

        Libera(raiz->esq);
        Libera(raiz->dir);
        free(raiz);
    }
}

/**
    Procedimento auxiliar para imprimir as informações da árvore na tela
*/

void printArv(Arvore *arv) {
    if (arv!=NULL) {
        printf("(");
        printf("%s", arv->info);
        printArv(arv->esq);
        printArv(arv->dir);
        printf(")");
    }
}
