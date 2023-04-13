#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

#define TIPO_ANIMAL             0
#define TIPO_CARACTERISTICA     1
#define STRMAX                  20

typedef struct ArvoreT
{
    char info[STRMAX];
    int tipo;
    struct ArvoreT *dir;
    struct ArvoreT *esq;

}Arvore;


Arvore* init();

Arvore* CriaNo();

int SalvaBaseDeDados(Arvore *arv);

Arvore* InsereCaracteristica (Arvore *arv, char *info);

Arvore* InsereAnimal (Arvore *arv, char *info);

int ArvVazia (Arvore *arv);

int LimpaArvore(Arvore *raiz);

#endif
