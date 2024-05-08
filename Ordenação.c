#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Função para trocar os valores de dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Função para dividir o array e retornar o índice do pivô
int partition(int vetor[], int low, int high) {
    int pivot = vetor[high]; //Escolhe o último elemento como pivô
    int i = (low - 1); //Inicializa o índice do menor elemento

    //Percorre o array, rearranja os elementos menores que o pivô
    for (int j = low; j <= high - 1; j++) {
        if (vetor[j] <= pivot) {
            i++;
            swap(&vetor[i], &vetor[j]); //Troca elementos menores que o pivô para a esquerda
        }
    }

    swap(&vetor[i + 1], &vetor[high]); //Coloca o pivô na posição correta
    return (i + 1); //Retorna o índice do pivô
}

//Função principal do QuickSort
void QuickSort(int vetor[], int low, int high) {
    if (low < high) {
        int pi = partition(vetor, low, high); //Obtém o índice do pivô
        //Ordena os elementos antes e depois do pivô recursivamente
        QuickSort(vetor, low, pi - 1);
        QuickSort(vetor, pi + 1, high);
    }
}

int main(){
    //Declaração de variáveis
    int *vetor;
    int tamanho, u;
    struct timespec inicio, fim;
    float tempo;

    //Define o tamanho do vetor
    scanf("%d",&tamanho);

    //Alocação de memória
    vetor = (int *)calloc(tamanho,sizeof(int));
    if (vetor == NULL){
        printf("Erro na alocação\n");
        return 1;
    }

    //Adiciona os elementos ao vetor
    for (u=0;u<tamanho;u++){
        scanf("%d",&vetor[u]);
    }

    //Medição do tempo de execução
    clock_gettime(CLOCK_MONOTONIC,&inicio);
    QuickSort(vetor,0,tamanho-1);
    clock_gettime(CLOCK_MONOTONIC,&fim);
    tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;

    //Imprimindo o vetor ordenado
    for(u=0;u<tamanho;u++){
        printf("%d ",vetor[u]);
    }

    //Imprimindo o tempo de execução
    printf("\n");
    printf("Tempo de execucao: %.4f milisegundos",tempo*1000);

    //Liberando memória alocada
    free(vetor);
    return 0;
}
