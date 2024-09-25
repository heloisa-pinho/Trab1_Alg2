#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#include "ordenacao.h"


int main() {
    char nome[MAX_CHAR_NOME];
    size_t idxBusca;
    uint64_t numComp;

    // Dica: somente é posśivel criar vetores grandes utilizando alocação
    // dinâmica de memória Veja um exemplo de alocação dinâmica a seguir
    ssize_t tamVetor = 50000;
    int* vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }

    // Minhas informacoes
    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    // Para medir o tempo, inclua time.h, e siga o exemplo:
    clock_t start, end;  // variáveis do tipo clock_t
    double total;

    //-----Algotirimos de Ordenacao-----

    //---Insertion Sort Interativo---
    printf("-----Insertion Sort Iterativo-----\n");
    preencheVetorAleatorio(vetor, tamVetor);
    printf("Vetor: ");
    imprime_ini_fim (vetor, tamVetor);
    start = clock(); // start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, tamVetor);
    end = clock();
	printf("Vetor ordenado: ");
	imprime_ini_fim (vetor, tamVetor);
	printf("\n");
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf ("Resultado: com %ld elementos fez %ld comparacoes em %f segundos\n", tamVetor, numComp, total);
    printf("\n");
    
    //---Insertion Sort Recursivo---
	printf("-----Insertion Sort Recursivo-----\n");
    preencheVetorAleatorio(vetor, tamVetor);
    printf("Vetor: ");
    imprime_ini_fim (vetor, tamVetor);
    start = clock(); // start recebe o "ciclo" corrente
	numComp = insertionSortRec(vetor, tamVetor);
    end = clock();
	printf("Vetor ordenado: ");
    imprime_ini_fim (vetor, tamVetor);
	printf("\n");
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf ("Resultado: com %ld elementos fez %ld comparacoes em %f segundos\n", tamVetor, numComp, total);
    printf("\n");

    //---Selection Sort Interativo---
    printf("-----Selection Sort Interativo-----\n");
    preencheVetorAleatorio(vetor, tamVetor);
    printf("Vetor: ");
    imprime_ini_fim (vetor, tamVetor);
    start = clock(); // start recebe o "ciclo" corrente
	numComp = selectionSort(vetor, tamVetor);
    end = clock();
	printf("Vetor ordenado: ");
    imprime_ini_fim (vetor, tamVetor);
	printf("\n");
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf ("Resultado: com %ld elementos fez %ld comparacoes em %f segundos\n", tamVetor, numComp, total);
    printf("\n");

    //---Selection Sort Recursivo---
    printf("-----Selection Sort Recursivo-----\n");
    preencheVetorAleatorio(vetor, tamVetor);
    printf("Vetor: ");
    imprime_ini_fim (vetor, tamVetor);
    start = clock(); // start recebe o "ciclo" corrente
	numComp = selectionSortRec(vetor, tamVetor);
    end = clock();
	printf("Vetor ordenado: ");
    imprime_ini_fim (vetor, tamVetor);
	printf("\n");
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf ("Resultado: com %ld elementos fez %ld comparacoes em %f segundos\n", tamVetor, numComp, total);
    printf("\n");

    //---Merge Sort---
    printf("-----Merge Sort-----\n");
    preencheVetorAleatorio(vetor, tamVetor);
    printf("Vetor: ");
    imprime_ini_fim (vetor, tamVetor);
    start = clock(); // start recebe o "ciclo" corrente
	numComp = mergeSortRec(vetor, tamVetor);
    end = clock();
	printf("Vetor ordenado: ");
    imprime_ini_fim (vetor, tamVetor);
	printf("\n");
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf ("Resultado: com %ld elementos fez %ld comparacoes em %f segundos\n", tamVetor, numComp, total);
    printf("\n");

    //-----Algoritimos de Busca-----

    //seleciona numero aleatorio
    int numBusca = rand() %9;
	printf("buscar o numero %d: \n", numBusca);

    //---Busca Sequencial Interativo---
    printf("-----Busca Sequencial Iterativa-----\n");
	preencheVetorAleatorio(vetor, tamVetor);
	printf("Vetor: ");
    //imprimeVetor(vetor,tamVetor);
    start = clock();
	idxBusca = buscaSequencial(vetor, tamVetor, numBusca, &numComp);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("-Resultado-\nIndice: %ld\nComparacoes: %ld Tempo: %f\n", idxBusca, numComp, total);
    printf("\n");

    //---Busca Sequencial recursiva---
    printf("-----Busca Sequencial Recursiva-----\n");
	preencheVetorAleatorio(vetor, tamVetor);
	printf("Vetor: ");
    //imprimeVetor(vetor,tamVetor);
    start = clock();
	idxBusca = buscaSequencialRec(vetor, tamVetor, numBusca, &numComp);
    end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("-Resultado-\nIndice: %ld\nComparacoes: %ld Tempo: %f\n", idxBusca, numComp, total);
    printf("\n");
    
    //---busca binaria interativa---
    printf("-----Busca Binaria Iterativa-----\n");
	preencheVetorOrdenado(vetor, tamVetor);
	printf("Vetor: ");
    //imprimeVetor(vetor,tamVetor);
    start = clock();
	idxBusca = buscaBinaria(vetor, tamVetor, numBusca, &numComp);
    end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("-Resultado-\nIndice: %ld\nComparacoes: %ld Tempo: %f\n", idxBusca, numComp, total);
    printf("\n");

    //---busca binaria Recursiva---
    printf("-----Busca Binaria Recursiva-----\n");
	preencheVetorOrdenado(vetor, tamVetor);
	printf("Vetor: ");
    //imprimeVetor(vetor,tamVetor);
    start = clock();
	idxBusca = buscaBinariaRec(vetor, tamVetor, numBusca, &numComp);
    end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;
	printf("-Resultado-\nIndice: %ld\nComparacoes: %ld Tempo: %f\n", idxBusca, numComp, total);

    free(vetor);

    return 0;
}
