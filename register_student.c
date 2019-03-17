#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Nota{
    float P1;
    float P2;
    float T;
    float media;
} NOTA;

typedef struct Aluno {
    char nome[40];
    int matricula;
    NOTA *nota;

} ALUNO;

int alunos;
float CalcMedia(ALUNO *a, int);
void imprime(ALUNO *alunos, int);
void imprimeDados(ALUNO);

int main(){
    setlocale(LC_ALL, "Portuguese");

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &alunos);

    system("cls");

    ALUNO *al;
    float mediaP1 = 0;
    al = (ALUNO*) malloc(sizeof(ALUNO) * alunos);

    for(int i = 0; i < alunos; i++){
        al[i].nota = (NOTA*) malloc(sizeof(NOTA) * 1);
        printf("Dados do aluno [%d]\n", i +1);
        printf("Nome: ");
        fflush(stdin);
        gets(al[i].nome);
        printf("Matrícula: ");
        scanf("%d",&al[i].matricula);
        printf("Nota P1: ");
        scanf("%f",&al[i].nota->P1);
        printf("Nota P2: ");
        scanf("%f",&al[i].nota->P2);
        printf("Nota T1: ");
        scanf("%f",&al[i].nota->T);

        printf("\n");

        al[i].nota->media = (al[i].nota->P1 + al[i].nota->P2 + al[i].nota->T) / 3;
    }

    mediaP1 = CalcMedia(al, alunos);
    printf("\nMédia geral da P1: %.1f\n", mediaP1);
    imprime(al, alunos);

    free(al->nota);
    free(al);

    return 0;
}

float CalcMedia(ALUNO *a, int qtde){
    float sum = 0;
    for(int i = 0; i < qtde; i++)
        sum += a[i].nota->P1;

    return sum / qtde;
}

void imprime(ALUNO *a, int qtde){
    printf("\n\n");
    printf("|====================|====|====|====|=======|\n");
    printf("| Aluno              | P1 | P2 | T1 | Média |\n");
    printf("|====================|====|====|====|=======|\n");

    for(int i = 0; i < qtde; i++)
        imprimeDados(a[i]);

    printf("|====================|====|====|====|=======|\n");
    printf("\n");
}

void imprimeDados(ALUNO aluno){
        printf("| %-18s | %2.1f| %2.1f| %2.1f| %4.1f  |\n", aluno.nome, 
            aluno.nota->P1, aluno.nota->P2, aluno.nota->T, aluno.nota->media);
}