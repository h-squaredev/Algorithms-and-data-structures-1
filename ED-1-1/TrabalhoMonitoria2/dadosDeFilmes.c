#include "dadosDeFilmes.h"

// Funcao para carregar dados de aqruivo CSV 
// e retornar um array de filmes
Filme* carregarDados(const char* nomeArquivo, int* numFilmes) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL){
        printf("ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO!\n");
        return NULL;
    }
    
    char linha[512];
    int capacidade = 100;

    Filme* filmes = (Filme*)malloc(capacidade * sizeof(Filme));
    *numFilmes = 0;
    
    // le a primeira linha e nao faz nada com ela
    fgets(linha, sizeof(linha), arquivo);

    // Ler o arquivo linha por linha a partir da segunda linha
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (*numFilmes >= capacidade) {
            capacidade *= 2;
            filmes = (Filme*)realloc(filmes, capacidade * sizeof(Filme));
        }
    // equanto tiver linha pra ler, ele vai ler a linha e jogar cada pedaco na variavel certa
    while (fgets(linha, sizeof(linha), arquivo)) {
        if (*numFilmes >= capacidade) {
            capacidade *= 2;
            filmes = (Filme*)realloc(filmes, capacidade * sizeof(Filme));
        }

        // Usando sscanf para ler tudo de uma vez
        // ele vai ler a 'linha' e jogar cada pedaço na variavel certa
        int itensLidos = sscanf(linha, "%254[^;];%d;%99[^;];%99[^;];%f", 
                                filmes[*numFilmes].titulo, 
                                &filmes[*numFilmes].ano, 
                                filmes[*numFilmes].genero, 
                                filmes[*numFilmes].diretor, 
                                &filmes[*numFilmes].rating);

        // Verifica se conseguiu ler exatamente os 5 campos exigidos
        if (itensLidos == 5) {
            (*numFilmes)++;
        }
    }
    return filmes;
}
fclose(arquivo); // Fecha o ficheiro da memória
    return filmes;   // Devolve o array carregado para o main
}


// Funcao para imprimir os 10 primeiros filmes do array
void imprimirTop10(Filme* arr) {
    for (int i = 0; i < 10; i++) {
        printf("%2d. %s (%d) | Diretor: %s | Nota: %.1f\n", 
               i + 1, 
               arr[i].titulo, 
               arr[i].ano, 
               arr[i].diretor, 
               arr[i].rating);
    }
}

// Funcao para comparar dois filmes com base no criterio escolhido
int precisaTrocar(Filme a, Filme b, int criterio) {
    if (criterio == 1) { // Por Título (Ordem Alfabetica)
        return strcmp(a.titulo, b.titulo) > 0;
    } else if (criterio == 2) { // Por Ano
        return a.ano > b.ano;
    } else if (criterio == 3) { // Por Rating
        return a.rating < b.rating; //maior nota primeiro
    }
    return 0;
}

// Implementacao do Quick Sort
void quickSort(Filme* arr, int inicio, int fim, int criterio) {
    if (inicio < fim) {
        Filme pivo = arr[fim];
        int i = (inicio - 1);

        for (int j = inicio; j < fim; j++) {
            if (!precisaTrocar(arr[j], pivo, criterio)) {
                i++;
                Filme temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        Filme temp = arr[i + 1];
        arr[i + 1] = arr[fim];
        arr[fim] = temp;

        int p = i + 1;
        quickSort(arr, inicio, p - 1, criterio);
        quickSort(arr, p + 1, fim, criterio);
    }
}

// Implementacao do Heap Sort
void heapify(Filme* arr, int n, int i, int criterio) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && precisaTrocar(arr[esq], arr[maior], criterio)) maior = esq;
    if (dir < n && precisaTrocar(arr[dir], arr[maior], criterio)) maior = dir;

    if (maior != i) {
        Filme temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;
        heapify(arr, n, maior, criterio);
    }
}

void heapSort(Filme* arr, int n, int criterio) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i, criterio);
    for (int i = n - 1; i > 0; i--) {
        Filme temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0, criterio);
    }
}

//Implementacao do Merge Sort
void merge(Filme* arr, int l, int m, int r, int criterio) {
    int n1 = m - l + 1;
    int n2 = r - m;
    Filme *L = malloc(n1 * sizeof(Filme));
    Filme *R = malloc(n2 * sizeof(Filme));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (!precisaTrocar(L[i], R[j], criterio)) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}

void mergeSort(Filme* arr, int l, int r, int criterio) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, criterio);
        mergeSort(arr, m + 1, r, criterio);
        merge(arr, l, m, r, criterio);
    }
}