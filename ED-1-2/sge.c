#include<stdlib.h>
#include<stdio.h>
#include<string.h>


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

// Lista global
ListaAlunos *listaGlobal = NULL;

// Protótipos
void mostrarMenu(void);
void cadastrarAluno(void);
void listarAlunos(void);
void inicializaListaGlobal(void);
int existeLista(void);
Aluno* lerAluno(void);
void imprimirAluno(Aluno *a);
Aluno *fimDaLista(void);

// Lê os dados de um aluno
Aluno* lerAluno() {
    Aluno *a = malloc(sizeof(struct aluno));
    

    printf("Digite o RGA\n");
    scanf("%d", &a->rga);

    // Podemos melhorar esta leitura!
    // Podemos suar o fgets
    printf("Digite o Nome\n");
    scanf("%s", a->nome);

    printf("Digite as Notas\n");
    float m = 0;

    // Lê as quatro notas
    for (int i = 0; i < 4; i++) {
        printf("\tNota %d ", i + 1);
        scanf("%f", &a->notas[i]);
        m = m + a->notas[i];
    }

    // Calcula a média
    a->media = m / 4;
    a->proximo = NULL;

    #ifdef DEBUG
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
// Decisão de projeto: a inserção sempre será no final da lista
void cadastrarAluno(void) {
    if (!existeLista())
        inicializaListaGlobal();
    else {
        Aluno *novo = lerAluno();

        // Insere o primeiro aluno
        if (listaGlobal->tamanho == 0) {
            listaGlobal->dados = novo;
        }
        else {
            // Insere no final
            Aluno *fim = fimDaLista();
            fim->proximo = novo;
        }

        listaGlobal->tamanho = listaGlobal->tamanho + 1;
    }
}

// Lista todos os alunos
// decisão de projeto: estamos assumindo que o chamador da função
//verifica que a lista foi criada
void listarAlunos(void) {
    Aluno *aux = listaGlobal->dados;
    if (aux == NULL)
      printf("Lista Vazia!\n");
    else {
      // Percorre a lista
      while (aux != NULL) {
          imprimirAluno(aux);
          aux = aux->proximo;
      }
    }
}

// Exibe o menu principal
void mostrarMenu(void) {
    int opcao;

    do {
        printf("\n=====================================\n");
        printf("       SISTEMA DE ALUNOS\n");
        printf("=====================================\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar aluno\n");
        printf("0 - Sair\n");
        printf("-------------------------------------\n");
        printf("Digite uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;

            case 2:
                listarAlunos();
                break;

            case 3:
                // buscarAluno();
                printf("Funcao de busca ainda nao implementada.\n");
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);
}

// Inicializa a lista
void inicializaListaGlobal() {
    listaGlobal = malloc(1 * sizeof(struct ListaAlunos));
    listaGlobal->tamanho = 0;
    listaGlobal->dados = NULL;
}

// Verifica se a lista existe
int existeLista() {
    if (listaGlobal == NULL)
        return FALSE;

    return TRUE;
}

// Verifica se a lista está vazia
int vazia() {
    if (!existeLista() || listaGlobal->tamanho == 0)
        return TRUE;

    return FALSE;
}

// Função principal
int main() {
    #ifdef EDUARDO
    printf("macro eduardo ativada\n");
    #endif


    #ifdef DEBUG
    printf("macro debug ativada\n");
    #endif
    
    #ifdef DEBUG_ANNA
    printf("macro debug ativada\n");
    #endif
    
    inicializaListaGlobal();

    mostrarMenu();

    return 0;
}
