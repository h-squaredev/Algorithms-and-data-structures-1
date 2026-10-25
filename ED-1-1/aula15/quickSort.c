// Implementa ordenacao.h
#include "ordenacao.h"

// Implementacao do medoto de ordenacao BOLHA (BOBBLE SORT)
void bobbleSort(tipo_lista *lst) {
    int i, troca, aux;

    //Laco principal, que verifica se houve troca
    do {
        troca = 0; //Inicializa com falso (0)
        for (i=0; i<lst->contador-1; i++) {
            if (lst->lista[i] > lst->lista[i+1]) {
                aux = lst->lista[i];
                lst->lista[i] = lst->lista[i+1];
                lst->lista[i+1] = aux;
                troca = 1;
            }
        } 
    } while (troca); //Verifica se houve troca (1)
}

// Implementacao do metodo de ordenacao SHELL Sort
void shellSort(tipo_lista *lst) {
    int i, troca, aux, salto, contador;

    salto = (int) lst->contador / 2;
    contador = 0;
    // Verificacao dos valores considenrando o salto (Shell)
    while (salto > 1) {
        for (i=0; (i+salto) < lst->contador; i++) {
            if ( lst->lista[i] > lst->lista[i+salto]) {
                aux = lst->lista[i];
                lst->lista[i] = lst->lista[i+salto];
                lst->lista[i+salto] = aux;
            }
        }
        contador++;
        salto = (int) salto/2;
    }
    printf("ShellSort: Quantidade de passagens com saltos = %d\n", contador);
    contador = 0;
    //mesmo algoritmo do Bobble Sort
    do {
        troca = 0; //Inicializa com falso (0)
        for (i=0; i<lst->contador-1; i++) {
            if (lst->lista[i] > lst->lista[i+1]) {
                aux = lst->lista[i];
                lst->lista[i] = lst->lista[i+1];
                lst->lista[i+1] = aux;
                troca = 1;
            }
        }
        contador++;
    } while (troca); //Verifica se houve troca (1)
    printf("ShellSort: Quantidade de passagens SEM saltos = %d\n", contador);
}

// Metodo de ordenacao INSERT sort
void insertSort(tipo_lista *lst) {
    int i, pos;
    tipo_lista lst_ordenada;
    lst_ordenada.contador = 0;
    

    //Para cada valor na lista, serah inserido na lista ordenada
    for (i=0; i < lst->contador; i++) {
        //Insere ordenado
        for (pos=(lst_ordenada.contador-1); ( (pos>=0) && (lst_ordenada.lista[pos] > lst->lista[i]) ); pos--)
            lst_ordenada.lista[pos+1] = lst_ordenada.lista[pos];
        lst_ordenada.lista[pos+1] = lst->lista[i];
        lst_ordenada.contador++;
    }

    //Copia a list ordenada para a lista original
    for(i=0; i < lst->contador; i++)
        lst->lista[i] = lst_ordenada.lista[i];
}

// MEtodo de ordenacao MERGE Sort
// O metodo possui 2 subfuncoes, uma para cada fase do algoritmo (quebra e juncao)
void mergeSort(tipo_lista *lst) {
    //Inicia processo de quebra
    mergeSort_broken(lst, 0, lst->contador-1);
}
// Fase de quebra
void mergeSort_broken(tipo_lista *lst, int start, int end) {
    int half;
    half = (int) ((end-start)+1)/2;
    if ((end-start) > 0) {
        mergeSort_broken(lst, start, start+half-1);
        mergeSort_broken(lst, start+half, end);
        mergeSort_merge(lst, start, end);
    }
}
// Fase de juncao
void mergeSort_merge(tipo_lista *lst, int start, int end) {
    int half, i, j, pos, *sortedList, size;
    size = (end-start)+1;
    sortedList = (int*) malloc(sizeof(int)*size);
    half = (int) (size)/2;
    i = start; //percorre 1a metade
    j = start + half; //percorre 2a metade
    pos = 0; //Representa a posicao onde os valores estao sendo armazenados na lista ordenada
    //Percorre as metades, comparando-as
    while ((i <= start+half-1) && (j <= end)) {
        if (lst->lista[i] < lst->lista[j]) {
            sortedList[pos++] = lst->lista[i++];
        } else {
            sortedList[pos++] = lst->lista[j++];
        }
    }
    //Finaliza a copia dos valores que restaram em alguma das listas
    while (i <= start+half-1)
        sortedList[pos++] = lst->lista[i++];
    while (j <= end)
        sortedList[pos++] = lst->lista[j++];
    //Copia lista ordenada para a lista
    for (pos = 0; pos < size; pos++) {
        lst->lista[start+pos] = sortedList[pos];
    }
    free(sortedList);
}

//Funcao principal do quick sort, que recebe a lista a ser ordenada
void quickSort(tipo_lista *lst) {
    //Executa chamada a funcao que realiza a ordenacao do quick sort
    quickSort_rec(lst, 0, lst->contador-1);
}

//Funcao que implementa a ordenacao do quick sort
void quickSort_rec(tipo_lista *lst, int start, int end) {
    int pivot, i, j, bkp;

    //Verifica se a lista contem mais de 1 valor
    if (end-start > 0) {
        //seleciona Pivo
        pivot = lst->lista[ (start + (int)((end-start+1)/2))]; //seleciona valor/pivo do meio da lista
        //pivot = lst->lista[end];
        printf("Pivo=%d\n", pivot);

        i = start;
        j = end;
        //Laco principal, enquanto a posicao do pivo nao for encontrada
        while (i <= j) {
            while (lst->lista[i] < pivot)
                i++;
            while (lst->lista[j] > pivot)
                j--;
            if ( i <= j) { //MUdei aqui para garantir que nao aconteca o loop infinito 
                //realiza a troca dos valores de posicao
                bkp = lst->lista[i];
                lst->lista[i] = lst->lista[j];
                lst->lista[j] = bkp;

                //e aqui para avancar no codigo
                i++;
                j--;
            }
        }
        //Realiza chamada recursiva para 1a parte e 2a parte da lista (em relacao ao pivo)
        quickSort_rec(lst, start, j);  //Do inicio ate onde o J parou
        quickSort_rec(lst, j+1, end);  //Do proximo numero em diante
    }

    
}

// Funcao para gerar valores aleatorios
void geraLista(tipo_lista *lst, int n) {
    lst->contador = n; // Define o tamanho da lista

    for (int i = 0; i < n; i++) {
        // Preenche cada posicofo com um número de 0 a 1000
        lst->lista[i] = rand() % 1001;
    }
}

/*
int main() {
    tipo_lista lista;
    int tamanhos[] = {50, 100, 1000}; // Os tamanhos pedidos
    int i;

    for (i = 0; i < 3; i++) {
        int n = tamanhos[i];
        
        printf("--- Testando com %d elementos ---\n", n);
        
        // 1. Gera a lista aleatória
        geraLista(&lista, n);
        
        // 2. Ordena
        quickSort(&lista);
        
        // 3. Verifica (mostra apenas o primeiro e último para não poluir)
        printf("Ordenado! Primeiro: %d | Ultimo: %d\n\n", lista.lista[0], lista.lista[n-1]);
    }

    return 0;
}
*/