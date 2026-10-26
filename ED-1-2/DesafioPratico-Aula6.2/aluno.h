#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// Estrutura do aluno
typedef struct aluno {
    int rga;
    char nome[100];
    float media;
    float notas[4];
    struct aluno *proximo;
} Aluno;

// Estrutura da lista
typedef struct ListaAlunos {
    Aluno *dados;
    int tamanho;
} ListaAlunos;

// Protótipos
void mostrarMenu(void);
void cadastrarAluno(void);
void calcularMedia(Aluno *aluno);
const char* calcularSituacao(Aluno *aluno);
void listarAlunos(void);
void inicializaListaGlobal(void);
int existeLista(void);
int vazia(void);
Aluno* lerAluno(void);
void imprimirAluno(Aluno *a);
Aluno *fimDaLista(void);

#endif