#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Heloisa de Oliveira Pinho", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME - 1] =
        '\0';  // adicionada terminação manual para caso de overflow
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20231961; }

int aleat(int min, int max){
    return min + (rand() % (max - min + 1));
}

void preencheVetorAleatorio(int *vetor, int tam){
    srand(time(NULL));

	for (int i = 0; i < tam; ++i)
		vetor[i] = aleat(0,49999);
}

//preenche o vetor ordenado seguindo o numero do indice
void preencheVetorOrdenado (int *vetor, int tam) {
	int i;
	for (i = 0; i < tam; i++)
		vetor[i]= i;
}

void imprimeVetor(int vetor[], int tam){
	for (int i = 0; i < tam; i++){
		printf("[%d] ", vetor[i]);
	}
	printf("\n");
}

// Imprime os primeiros 5 elementos do vetor e os ultimos cinco
void imprime_ini_fim(int vetor[], ssize_t tam){
    int i, j;

    for (i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }

    printf("...");

    for (j = tam - 6; j < tam; j++) {
        printf("%d ", vetor[j]);
    }
    printf("\n");
}

//troca elementos do vetor
void troca(int v[], int a, int b){
	int aux;
	aux = v[a];
	v[a] = v[b];
	v[b] = aux;
}

//------Busca Sequencial------

//busca um elemento no vetor e retorna seu indice
ssize_t buscaSequencial(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {
    ssize_t i;
    *numComparacoes = 0;

    for (i = 0;i < tam; i++){

        (*numComparacoes)++;
		if (vetor[i] == valor)
			return i;
    }  

    return -1;
}

//Algoritmo de busca ingenua. Retorna a posicao do vetor quando encontra o valor determinado, caso contrario, retorna -1.
ssize_t auxBuscaSequencialRec(int v[], int ini, int fim, int valor, uint64_t *numComparacoes){
    if (ini > fim)
        return -1;

    (*numComparacoes)++;
    if (v[ini] == valor)
        return ini;

    return auxBuscaSequencialRec(v, ini + 1, fim, valor, numComparacoes);
}

//Função principal do buscaSequencial
ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor,
                           uint64_t* numComparacoes) {
    int ini,fim;
    ssize_t indice;
    ini = 0;
    fim = tam - 1;
    *numComparacoes = 0;

    indice = auxBuscaSequencialRec(vetor, ini, fim, valor, numComparacoes);

    return indice; 
}

//------Busca Binaria------

//funcao interativa que retorna a posicao do elemento buscado, caso nao encontre retorna -1
ssize_t buscaBinaria(int vetor[], size_t tam, int valor,
                     uint64_t* numComparacoes) {
    size_t ini, fim;
    int m;
    ini = 0;
    fim = tam - 1;
    *numComparacoes = 0;

    if (ini > fim)
        return -1;

    while ( ini <= fim){
         m = (ini + fim)/2;

        (*numComparacoes)++;
         if (vetor[m] == valor)
            return m;

         if (vetor[m] > valor){
            fim = m - 1;
         }
        else{
            ini = m + 1;
         }
    }

    return -1;
}

//Função auxiliar que retorna a posicao do vetor quando encontra o valor, caso não, retorna -1.
ssize_t auxBuscaBinariaRec(int v[],int ini , int fim, int valor, uint64_t *numComparacoes){
    if (ini > fim)
        return -1;

    int meio;
    meio = (ini + fim)/2;

    (*numComparacoes)++;
    if (v[meio] == valor)
        return meio;

    if (valor < v[meio])
        return auxBuscaBinariaRec(v, ini, meio - 1, valor, numComparacoes);
    
    return auxBuscaBinariaRec(v, meio + 1, fim, valor, numComparacoes);
}   

//Função principal do buscaSequencial
ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {
    int ini,fim;
    ssize_t indice;

    ini = 0;
    fim = tam - 1;
    *numComparacoes = 0;
    indice = auxBuscaBinariaRec(vetor, ini, fim, valor, numComparacoes);

    return indice;
}

//------Insertion Sort------

// Função de ordenação por inserção que ordena um vetor
//de inteiros em ordem crescente realizando trocas.
uint64_t insertionSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    int i, j;
    
    for (i = 1; i < tam; i++) {
        j = i;
        while (j > 0 && vetor[j] < vetor[j - 1]) {
           (numComparacoes++);
            troca(vetor, j, j - 1);
            j--;
        }
    }

    return numComparacoes;   
}

//Função auxiliar usada em conjunto com o Insertion Sort.
//Ela determina a posição onde um valor deve ser inserido e realiza as trocas necessárias.
uint64_t inserir(int *v, int ini, int fim, uint64_t *numComparacoes){
	int i = fim;

    while (i > ini && v[i] < v[i - 1]) {
        troca(v, i, i - 1);
        i--;
        (*numComparacoes)++;
    }

    return *numComparacoes;
}

//Função auxiliar recursiva para o algoritmo de ordenação por inserção.
// Ordena uma parte do vetor delimitada pelos índices ini e fim.
uint64_t auxInsertionSortRec(int *vetor, int ini, int fim, uint64_t *numComparacoes){
	if (ini > fim)
		return -1;

	auxInsertionSortRec(vetor, ini, fim - 1, numComparacoes);
	inserir(vetor, ini, fim, numComparacoes);

    return *numComparacoes;
}


uint64_t insertionSortRec(int vetor[], size_t tam) {
    int ini, fim;
    uint64_t numComparacoes;
    numComparacoes = 0;
    if(tam <= 0)
        return -1;

    ini = 0;
    fim = tam -1;

    return auxInsertionSortRec(vetor, ini, fim, &numComparacoes);;
}

//------Selection Sort------

uint64_t selectionSort(int vetor[], size_t tam) { 
    uint64_t numComparacoes = 0;
    size_t i,j,indice_min;

    for (i = 0; i < tam - 1; i++){
		indice_min = i;

		for (j = i + 1; j < tam; j++){
			numComparacoes++;
			if (vetor[j] < vetor[indice_min])
				indice_min = j;
		}

		if (indice_min != i)
			troca(vetor, i, indice_min);
	}

    return numComparacoes;
}

//Funcao responsavel por retornar o menor valor de um vetor de n posicoes
int minimo(int v[], int ini, int  fim, uint64_t *numComparacoes){
	if (ini >= fim)
		return ini; 
	int m;
	m = minimo(v, ini,fim - 1, numComparacoes);
	(*numComparacoes)++;
	if (v[m] > v[fim])
		m = fim;

	return m;
}

// Função auxiliar responsável por ordenar o vetor usando o algoritmo do Selection Sort.
uint64_t auxSelectionSortRec(int v[],int ini,int fim, uint64_t *numComparacoes){
    if (ini >= fim)
         return -1 ;
    int m;
    m = minimo(v, ini, fim, numComparacoes);
    troca(v, ini, m);
    auxSelectionSortRec(v, ini + 1, fim, numComparacoes);

    return *numComparacoes;
}

uint64_t selectionSortRec(int vetor[], size_t tam) {
    if (tam <= 0)
		return -1;
	int ini, fim;
	uint64_t numComparacoes;
	ini = 0;
    numComparacoes = 0;
	fim = tam - 1;
	auxSelectionSortRec(vetor, ini, fim, &numComparacoes);

	return numComparacoes;
}

//------Merge Sort Recursivo------

void copia_Vetor(int v[], int V_aux[], int tam){
    int i;

	for(i = 0; i < tam; i++)
		v[i] = V_aux[i];
    
	return;
}

//ordena o vetor usando um vetor secundário. Ela divide o vetor principal ao meio e ordena nesse subvetor criado.
int merge(int v[], int ini, int meio, int fim, uint64_t *numComparacoes){
    if (ini >= fim)
        return -1;
    
    int i,j,k,aux,tam;

    tam = fim - ini + 1;

    //cria vetor auxiliar
    int *v_Aux = malloc(tam * sizeof(int));
	if (v_Aux == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return -1;
	}

    aux = k = 0;
	i = ini;
	j = meio +1;

    while (k <= fim - ini) {
		if (j > fim || (i <= meio && v[i] <= v[j])) {
			aux = i;
			i++;
		}
		else {
			aux = j;
			j++;
		}
		(*numComparacoes)++;
		v_Aux[k] = v[aux];
		k++;
	}

copia_Vetor(v + ini,v_Aux, tam);
    free(v_Aux);

    return 1;
}

// Função auxiliar responsável por particionar os 
//subvetores para permitir que sejam agrupados de forma ordenada.
int auxMergeSort(int v[], int ini, int fim, uint64_t *numComparacoes){
	if (ini >= fim)
		return -1;

	int meio;
	meio = (ini + fim) / 2;

	auxMergeSort(v, ini, meio, numComparacoes);
	auxMergeSort(v, meio + 1, fim, numComparacoes);
	merge(v, ini, meio, fim, numComparacoes);

	return 1;
}

uint64_t mergeSortRec(int vetor[], size_t tam) {
    int ini,fim;
    uint64_t numComparacoes;

    numComparacoes = 0;
    ini = 0;
    fim = tam - 1;

    auxMergeSort(vetor, ini, fim, &numComparacoes);

    return numComparacoes;
}
