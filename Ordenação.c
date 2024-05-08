//Nome: Luiz Henrique Nogueira dos Santos
//N�mero USP: 14755054

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Fun��o para trocar os valores de dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Fun��o para dividir o array e retornar o �ndice do piv�
int partition(int vetor[], int low, int high) {
    int pivot = vetor[high]; //Escolhe o �ltimo elemento como piv�
    int i = (low - 1); //Inicializa o �ndice do menor elemento

    //Percorre o array, rearranja os elementos menores que o piv�
    for (int j = low; j <= high - 1; j++) {
        if (vetor[j] <= pivot) {
            i++;
            swap(&vetor[i], &vetor[j]); //Troca elementos menores que o piv� para a esquerda
        }
    }

    swap(&vetor[i + 1], &vetor[high]); //Coloca o piv� na posi��o correta
    return (i + 1); //Retorna o �ndice do piv�
}

//Fun��o principal do QuickSort
void QuickSort(int vetor[], int low, int high) {
    if (low < high) {
        int pi = partition(vetor, low, high); //Obt�m o �ndice do piv�
        //Ordena os elementos antes e depois do piv� recursivamente
        QuickSort(vetor, low, pi - 1);
        QuickSort(vetor, pi + 1, high);
    }
}

int main(){
    //Declara��o de vari�veis
    int *vetor;
    int tamanho, u;
    //struct timespec inicio, fim;
    //float tempo;

    //Define o tamanho do vetor
    scanf("%d",&tamanho);

    //Aloca��o de mem�ria
    vetor = (int *)calloc(tamanho,sizeof(int));
    if (vetor == NULL){
        printf("Erro na aloca��o\n");
        return 1;
    }

    //Adiciona os elementos ao vetor
    for (u=0;u<tamanho;u++){
        scanf("%d",&vetor[u]);
    }

    //Medi��o do tempo de execu��o
    //clock_gettime(CLOCK_MONOTONIC,&inicio);
    QuickSort(vetor,0,tamanho-1);
    //clock_gettime(CLOCK_MONOTONIC,&fim);
    //tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;

    //Imprimindo o vetor ordenado
    for(u=0;u<tamanho;u++){
        printf("%d ",vetor[u]);
    }

    //Imprimindo o tempo de execu��o
    //printf("\n");
    //printf("Tempo de execucao: %.4f milisegundos",tempo*1000);

    //Liberando mem�ria alocada
    free(vetor);
    return 0;
}
