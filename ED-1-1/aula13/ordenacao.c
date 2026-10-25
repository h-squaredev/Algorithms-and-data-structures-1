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