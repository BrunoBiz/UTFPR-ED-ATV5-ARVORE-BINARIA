#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insere(struct arvore **inicio, Aluno alunoInserir, int info){
    struct arvore *aux;

    if (!*inicio)    {
        if((aux = (struct arvore*) malloc(sizeof(struct arvore))) != NULL)        {
            aux -> info = info;
            aux -> dir = NULL;
            aux -> esq = NULL;
            aux->aluno = alunoInserir;
            *inicio = aux;
        }
        else        {
            printf("Nao foi possivel alocar memoria");
        }
    }
    else    {
        if ((*inicio)->info > info){
            insere(&((*inicio)->esq), alunoInserir, info);
        }
        else if((*inicio)->info < info) {
            insere(&((*inicio)->dir), alunoInserir, info);
        }
        else{
            printf("A Chave %d ja pertence a arvore\n", info);
        }
    }
}

void preOrdem(struct arvore *inicio)
{
    if (inicio)
    {
        /* printf("matricula: %d\n", inicio->info); */
        ImprimirAluno(inicio->aluno);
        preOrdem(inicio->esq);
        preOrdem(inicio->dir);
    }
}

void ImprimirAluno(Aluno aluno){
    printf("X-------------------X\n");
    printf("| Informacoes Aluno |\n");
    printf("X-------------------X\n");

    printf("Matricula.....: %d\n", aluno.matricula);
    printf("Nome..........: %s", aluno.nome);
    printf("Sobrenome.....: %s", aluno.sobrenome);
    printf("E-mail........: %s", aluno.email);
    printf("Telefone......: %s", aluno.telefone);
    printf("Dt. Nascimento: %d/%d/%d\n", aluno.diaNascimento, aluno.mesNascimento, aluno.anoNascimento);
}

struct arvore* menorValor(struct arvore* arvore)
{
    struct arvore* atual = arvore;

    /* Acha a folha de menor valor */
    while (atual && atual->esq != NULL)
        atual = atual->esq;

    return atual;
}
struct arvore* removeAluno(struct arvore* arvoreAux, int matriculaRemover)
{
    if (arvoreAux == NULL)
        return arvoreAux;

    /* Se for menor, está do lado esquerdo */
    if (matriculaRemover < arvoreAux->info){
        arvoreAux->esq = removeAluno(arvoreAux->esq, matriculaRemover);
    }/* Maior, do lado direito */
    else if (matriculaRemover > arvoreAux->info){
        arvoreAux->dir = removeAluno(arvoreAux->dir, matriculaRemover);
    }
    /* Se for igual, é o que vai ser eliminado */
    else {
        /* Apenas um ou nenhum filho */
        if (arvoreAux->esq == NULL) {
            struct arvore* temp = arvoreAux->dir;
            free(arvoreAux);
            return temp;
        }
        else if (arvoreAux->dir == NULL) {
            struct arvore* temp = arvoreAux->esq;
            free(arvoreAux);
            return temp;
        }

        /* Dois filhos */
        /* Acha o menor na sub arvore da direita */
        struct arvore* temp = menorValor(arvoreAux->dir);

        /* Copia o menor da sub arvore da direita para o atual  */
        arvoreAux->info = temp->info;

        /* Deleta o que foi copiado */
        arvoreAux->dir = removeAluno(arvoreAux->dir, temp->info);
    }
    return arvoreAux;
}

void consultaMatricula(struct arvore* arvoreAux, int matriculaConsulta){
    /* Se for menor, está do lado esquerdo */
    if (matriculaConsulta < arvoreAux->info){
        arvoreAux->esq = removeAluno(arvoreAux->esq, matriculaConsulta);
    }/* Maior, do lado direito */
    else if (matriculaConsulta > arvoreAux->info){
        arvoreAux->dir = removeAluno(arvoreAux->dir, matriculaConsulta);
    }
    /* Se for igual, é o que vai ser eliminado */
    else {
        ImprimirAluno(arvoreAux->aluno);
    }
}

void destruirArvore(struct arvore *inicio){
    if (inicio != NULL){
        destruirArvore(inicio->esq);
        destruirArvore(inicio->dir);
        free(inicio);
    }
}
