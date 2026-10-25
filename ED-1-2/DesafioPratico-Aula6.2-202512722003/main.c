#include "aluno.h"

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

// Função principal
int main() {
    #ifdef DEBUG
    printf("Macro DEBUG ativada - Modo de depuração ligado.\n");
    #endif
    
    inicializaListaGlobal();
    mostrarMenu();

    return 0;
}