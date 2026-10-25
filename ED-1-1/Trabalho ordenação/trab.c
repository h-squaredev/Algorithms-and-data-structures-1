#include <stdio.h>
#include <stdlib.h>
#include <time.h> // mede o tempo
#include <string.h>

// Estrutura que armazena as medicoes de tempo e troca
typedef struct {
    long long trocas;
    double tempo;
} Resultado;

// ---- GERAR OS ARQUIVOS ----
// Fiz uma pesquisa na internet e descobri um algoritmo que "sorteia" numeros sem repeticao. se chama fisher yates
// Bascicamente ele pega um vetor já criado e reorganiza, ou seja, isso evita que numeros ja criados sejam novamente criados,
// pois ele reorganiza o proprio vetor, sem criar nenhum auxiliar

void gerarArquivos() {
    int tamanhos[] = {1000, 10000, 100000};  //eu tentei usar #define mas por algum motivo tava dando erro, entao preferi ir assim msm
    int *pool = malloc(999999 * sizeof(int)); //criamos um ponteiro
    for (int i = 0; i < 999999; i++){
        pool[i] = i + 1; // criamos um vetor inicial que vai de 0 até 999999, e prenchemos em ordem crescente, de qualquer modo
                         // o algoritmo fisher yates vai embaralhar tudo. Isso só garante que nao tenhamos repetidos
    }

    srand(time(NULL));

    for (int i = 0; i < 3; i++) {
        int n = tamanhos[i];
        for (int f_index = 1; f_index <= 5; f_index++) {
            // aqui que entra o fisher yates
            for (int j = 0; j < n; j++) { // o "n" que vai decidir quantas trocas fazemos, isso garante que o arquivo de mil dados tenha realmente mil dados
                int k = j + rand() % (999999 - j);      // sorteia uma posicao pra efetuar a troca, poderiamos fazer essa troca
                int temp = pool[j];                     // numa funcao exterior, como no quick sort, usando ponteiros,
                pool[j] = pool[k];                      // mas isso adicionaria uma complexidade desnecessaria
                pool[k] = temp;
            }

            // cria o arquivo
            char nome[30];
            sprintf(nome, "%d-arq%d.txt", n, f_index);
            FILE *f = fopen(nome, "w");
            for (int z = 0; z < n; z++) fprintf(f, "%d\n", pool[z]);
            fclose(f);
        }
    }
    free(pool);
}

// --- OS ALGORITMOS DE ORDENACAO ---

Resultado bubbleSort(int *vetor, int tam) { // BUBBLE SORT //
    long long trocas = 0;
    clock_t inicio = clock();  // inicia o tempo, primeiro ele marca o inicio, para depois subtrair do final
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int tmp = vetor[j]; 
                vetor[j] = vetor[j + 1]; 
                vetor[j + 1] = tmp;
                trocas++;
            }
        }
    }
    return (Resultado){trocas, (double)(clock() - inicio) / CLOCKS_PER_SEC};
}

Resultado insertionSort(int *vetor, int tam) { // INSERTION SORT //
    long long trocas = 0;
    clock_t inicio = clock();
    for (int i = 1; i < tam; i++) {
        int chave = vetor[i], j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
            trocas++;
        }
        vetor[j + 1] = chave;
    }
    return (Resultado){trocas, (double)(clock() - inicio) / CLOCKS_PER_SEC};
}

Resultado shellSort(int *vetor, int tam) {
    long long trocas = 0;
    clock_t inicio = clock();
    for (int lacuna = tam / 2; lacuna > 0; lacuna = lacuna / 2) {
        for (int i = lacuna; i < tam; i++) {
            int temp = vetor[i], j;
            for (j = i; j >= lacuna && vetor[j - lacuna] > temp; j -= lacuna) {
                vetor[j] = vetor[j - lacuna];
                trocas++;
            }
            vetor[j] = temp;
        }
    }
    return (Resultado){trocas, (double)(clock() - inicio) / CLOCKS_PER_SEC};
}

// Auxiliares para quick e merge
void quickSortRec(int *vetor, int esq, int dir, long long *t) { // QUICK SORT //
    if (esq < dir) {
        int p = vetor[dir], i = esq - 1;
        for (int j = esq; j < dir; j++) {
            if (vetor[j] < p) {
                i++;
                int tmp = vetor[i]; 
                vetor[i] = vetor[j]; 
                vetor[j] = tmp;
                (*t)++;
            }
        }
        int tmp = vetor[i + 1]; 
        vetor[i + 1] = vetor[dir]; 
        vetor[dir] = tmp;
        (*t)++;
        int pi = i + 1;
        quickSortRec(vetor, esq, pi - 1, t);
        quickSortRec(vetor, pi + 1, dir, t);
    }
}

void merge(int *vetor, int esq, int meio, int dir, long long *t) {
    int tam_esq = meio - esq + 1;
    int tam_dir = dir - meio;
    int *t_esq = malloc(tam_esq * sizeof(int));
    int *t_dir = malloc(tam_dir * sizeof(int));

    for (int i = 0; i < tam_esq; i++){
        t_esq[i] = vetor[esq + i];
    }
    for (int i = 0; i < tam_dir; i++){
        t_dir[i] = vetor[meio + 1 + i];
    }

    int i = 0; 
    int j = 0;
    int k = esq;
    while (i < tam_esq && j < tam_dir) {
        if (t_esq[i] <= t_dir[j]){
            vetor[k] = t_esq[i];
            i++;
        } else {
            vetor[k] = t_dir[j];
            j++;
        }
        k++;
        (*t)++;
    }

    while (i < tam_esq) { 
        vetor[k] = t_esq[i];
        i++;
        k++;
        (*t)++; 
    }

    while (j < tam_dir) { 
        vetor[k] = t_dir[j];
        j++;
        k++; 
        (*t)++; 
    }

    free(t_esq); 
    free(t_dir);
}

void mergeSortRec(int *vetor, int esq, int dir, long long *t) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        mergeSortRec(vetor, esq, meio, t);
        mergeSortRec(vetor, meio + 1, dir, t);
        merge(vetor, esq, meio, dir, t);
    }
}

// --- FUNÇÃO DE TESTE ---

void rodarTestes(char *nome_arquivo, int tam) {
    FILE *f = fopen(nome_arquivo, "r"); //abre o arquivo que contem os numeros
    if (!f) return; // sai da funcao caso nao consiga abrir o arquivo ou nao exista

    int *orig = malloc(tam * sizeof(int));
    int *temp = malloc(tam * sizeof(int));
    for (int i = 0; i < tam; i++) {
        fscanf(f, "%d", &orig[i]);
    }
    fclose(f);

    printf("\nArquivo %s\n", nome_arquivo);
    printf("Metodo          | Trocas        | Tempo em seg\n");
    printf("--------------------------------------------\n");

    const char *nomes[] = {"Bubble", "Insertion", "Shell", "Quick", "Merge"};
    for (int i = 0; i < 5; i++) {
        memcpy(temp, orig, tam * sizeof(int));
        Resultado res;
        long long t_rec = 0;
        clock_t start;

        switch(i) { // chama cada metodo de ordenacao ordenadamente
            case 0: res = bubbleSort(temp, tam); break;
            case 1: res = insertionSort(temp, tam); break;
            case 2: res = shellSort(temp, tam); break;
            case 3:  // aqui muda um pouco pq temos os metodos de ordenacao recursivos (merge e quicksort)
                start = clock();                                                        // devemos calcular o tempo aqui, pq se calculassemos na funcao recursiva
                quickSortRec(temp, 0, tam - 1, &t_rec);                                 // ele iria medir o tempo de cada iteracao da chamada recursiva
                res = (Resultado){t_rec, (double)(clock() - start) / CLOCKS_PER_SEC};
                break;
            case 4:
                start = clock();
                mergeSortRec(temp, 0, tam - 1, &t_rec);
                res = (Resultado){t_rec, (double)(clock() - start) / CLOCKS_PER_SEC};
                break;
        }
        printf("%-15s | %-12lld | %-10.4f\n", nomes[i], res.trocas, res.tempo);
    }
    free(orig); free(temp);
}

int main() {
    gerarArquivos();

    // chama todos os testes
    int tamanhos[] = {1000, 10000, 100000};
    for (int t = 0; t < 3; t++) {
        for (int f = 1; f <= 5; f++) {
            char nome[30];
            sprintf(nome, "%d-arq%d.txt", tamanhos[t], f);
            rodarTestes(nome, tamanhos[t]);
        }
    }

    return 0;
}