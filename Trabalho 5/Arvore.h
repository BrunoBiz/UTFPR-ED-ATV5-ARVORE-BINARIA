#include <stdio.h>
#include <stdLib.h>
typedef struct {
    int matricula;
	char nome[100];
	char sobrenome[100];
	char email[100];
	char telefone[100];
	int diaNascimento;
	int mesNascimento;
	int anoNascimento;
}Aluno;

typedef struct arvore
{
    int info;
    Aluno aluno;
    struct arvore *esq,*dir;
};

void insere(struct arvore **inicio, Aluno aluno, int info);
void preOrdem(struct arvore *inicio);
void ImprimirAluno(Aluno aluno);
struct arvore* menorValor(struct arvore* arvore);
struct arvore* removeAluno(struct arvore* arvoreAux, int matriculaRemover);
void consultaMatricula(struct arvore* arvoreAux, int matriculaConsulta);
void destruirArvore(struct arvore *inicio);
