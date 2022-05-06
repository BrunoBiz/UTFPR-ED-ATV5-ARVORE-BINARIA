#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MenuPrincipal();
void LimparTela();
void InsereAlunoMenu(struct arvore **inicio);
void RemoveAlunoMenu(struct arvore **inicio);
void ConsultaMatriculaMenu(struct arvore **inicio);
int main()
{
    int Menu;
    struct arvore *abb = NULL;

    do{
        LimparTela();
        MenuPrincipal();
        Menu = 0;
        scanf("%d", &Menu);

        switch (Menu)
        {
            /* SAI DO MENU */
                case 9:
                break;

            /* INSERIR ALUNO */
                case 1:
                    InsereAlunoMenu(&abb);
                    break;

            /* CONSULTA PELA MATRICULA */
                case 2:
                    ConsultaMatriculaMenu(&abb);
                    break;

            /* REMOVE PELA MATRICULA */
                case 3:
                    RemoveAlunoMenu(&abb);
                    break;

            /* IMPRESSAO GERAL */
                case 4:
                    preOrdem(abb);

                    printf("Pressione ENTER para continuar...\n");
                    getch();

                    break;

            /* OPCAO INVALIDA */
                default:
                    printf("Opcao Invalida\n");
                    fflush(stdin);
                    break;
        }

    }while (Menu != 9);

    destruirArvore(abb);
    return 0;
}

void InsereAlunoMenu(struct arvore **inicio){
    Aluno NovoAluno;
    int NumMatricula;

    LimparTela();

    printf("X----------------X\n");
    printf("| Dados do Aluno |\n");
    printf("X----------------X\n");

    fflush(stdin);


    printf("Matricula [1-999]: ");
    char MatriculaAux[4];
    fgets(MatriculaAux, 4, stdin);
    NumMatricula = atoi(MatriculaAux);
    NovoAluno.matricula = NumMatricula;
    fflush(stdin);

    printf("\nNome......: ");
    fgets(NovoAluno.nome, 100, stdin);
    fflush(stdin);

    printf("Sobrenome.: ");
    fgets(NovoAluno.sobrenome, 100, stdin);
    fflush(stdin);

    printf("E-mail....: ");
    fgets(NovoAluno.email, 100, stdin);
    fflush(stdin);

    printf("Telefone..: ");
    fgets(NovoAluno.telefone, 100, stdin);
    fflush(stdin);

    printf("\nData de Nascimento\n");
    fflush(stdin);

    printf("Dia: ");
    char DiaDtNascimento[3];
    fgets(DiaDtNascimento, 3, stdin);
    NovoAluno.diaNascimento = atoi(DiaDtNascimento);
    fflush(stdin);

    printf("Mes: ");
    char MesDtNascimento[3];
    fgets(MesDtNascimento, 3, stdin);
    fflush(stdin);
    NovoAluno.mesNascimento = atoi(MesDtNascimento);

    printf("Ano: ");
    char AnoDtNascimento[5];
    fgets(AnoDtNascimento, 5, stdin);
    fflush(stdin);
    NovoAluno.anoNascimento = atoi(AnoDtNascimento);

    insere(&(*inicio), NovoAluno, NumMatricula);

    printf("\nPressione ENTER para continuar...\n");
    getch();
    fflush(stdin);
}

void RemoveAlunoMenu(struct arvore **inicio){
    int NumMatricula;

    LimparTela();

    printf("X------------------------X\n");
    printf("| Matricula para Remocao |\n");
    printf("X------------------------X\n");

    fflush(stdin);

    printf("Matricula [1-999]: ");
    char MatriculaAux[4];
    fgets(MatriculaAux, 4, stdin);
    NumMatricula = atoi(MatriculaAux);

    removeAluno(*inicio, NumMatricula);
    printf("\nPressione ENTER para continuar...\n");
    getch();
    fflush(stdin);
}

void ConsultaMatriculaMenu(struct arvore **inicio){
    int NumMatricula;

    LimparTela();

    printf("X-------------------------X\n");
    printf("| Matricula para Consulta |\n");
    printf("X-------------------------X\n");

    fflush(stdin);

    printf("Matricula [1-999]: ");
    char MatriculaAux[4];
    fgets(MatriculaAux, 4, stdin);
    NumMatricula = atoi(MatriculaAux);

    consultaMatricula(*inicio, NumMatricula);
    printf("\nPressione ENTER para continuar...\n");
    getch();
    fflush(stdin);
}

void MenuPrincipal(){
    printf("X-- Atividade 5 ---------------------X\n");
    printf("| 1 - Inserir aluno                  |\n");
    printf("| 2 - Consultar aluno pela matricula |\n");
    printf("| 3 - Eliminar aluno pela matricula  |\n");
    printf("| 4 - Impressao geral                |\n");
    printf("|                                    |\n");
    printf("| 9 - Sair                           |\n");
    printf("X------------------------------------X\n");
}

void LimparTela(){
    #ifdef _WIN32
    system("cls");

    #elif __linux__
    system("clear");

    #endif
}

