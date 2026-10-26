#include "aluno.h"

// Lista global
ListaAlunos *listaGlobal = NULL;

//Calcular a media do aluno
void calcularMedia(Aluno *aluno){
    float soma = 0.0f;
            
    for(int i = 0; i < 4; i++){
        soma += aluno->notas[i];
    }
    aluno->media = soma / 4.0f;
}


// Calcular situação do aluno
const char* calcularSituacao(Aluno *aluno) {
    if (aluno->media >= 5.0f) {
        return "Aprovado";
    } else {
        return "Reprovado";
    }
}


// Lê os dados de um aluno
Aluno* lerAluno() {
    Aluno *a = malloc(sizeof(struct aluno));
    
    printf("Digite o RGA:\n");
    scanf("%d", &a->rga);

    printf("Digite o Nome:\n");
    scanf("%s", a->nome);

    printf("Digite as Notas:\n");
    for (int i = 0; i < 4; i++) {
        printf("\tNota %d: ", i + 1);
        scanf("%f", &a->notas[i]);
    }

    calcularMedia(a);
    a->proximo = NULL;

    #ifdef DEBUG
    printf("\n[DEBUG] Novo aluno lido com sucesso!\n");
    imprimirAluno(a);
    #endif

    return a;
}


// Exibe os dados do aluno
void imprimirAluno(Aluno *a) {
    printf("\n========================================\n");
    printf("         DADOS DO ALUNO\n");
    printf("========================================\n");

    printf("RGA   : %d\n", a->rga);
    printf("Nome  : %s\n", a->nome);
    printf("Média : %.2f\n", a->media);
    printf("Situação : %s\n", calcularSituacao(a));
    printf("Notas : ");

    for (int i = 0; i < 4; i++) {
        printf("%.2f |", a->notas[i]);
    }
    printf("\n========================================\n");
}


// Retorna o último aluno
Aluno *fimDaLista() {
    Aluno *aux = listaGlobal->dados;

    if (aux == NULL)
        return NULL;
    
    while (aux->proximo != NULL)
        aux = aux->proximo;

    return aux;
}

// Cadastra um novo aluno
// Assume que a inserção sempre será no final da lista
void cadastrarAluno(void) {
    if (!existeLista())
        inicializaListaGlobal();

    Aluno *novo = lerAluno();

    if (listaGlobal->tamanho == 0) {
        listaGlobal->dados = novo;
    } else {
        Aluno *fim = fimDaLista();
        fim->proximo = novo;
    }

    listaGlobal->tamanho++;
}

// Lista todos os alunos
// Assume que o chamador da função
// verifica que a lista foi criada
void listarAlunos(void) {
    if (!existeLista() || vazia()) {
        printf("Lista Vazia!\n");
        return;
    }

    Aluno *aux = listaGlobal->dados;
    while (aux != NULL) {
        imprimirAluno(aux);
        aux = aux->proximo;
    }
}


// Inicializa a lista
void inicializaListaGlobal() {
    listaGlobal = malloc(1 * sizeof(struct ListaAlunos));
    listaGlobal->tamanho = 0;
    listaGlobal->dados = NULL;
}

// Verifica se a lista existe
int existeLista() {
    return (listaGlobal != NULL) ? TRUE : FALSE;
}


// Verifica se a lista está vazia
int vazia() {
    return (!existeLista() || listaGlobal->tamanho == 0) ? TRUE : FALSE;
}
