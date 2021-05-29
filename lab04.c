#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int *v, int tam){

	int i;
	for(i = 0; i < tam; i++) printf("%d ", v[i]);
	printf("\n");
}

void swap(int *p1, int *p2){

	int aux = *p1;
	*p1 = *p2;
	*p2 = aux;

}

void bubbleSort(int tam, int *v){
	printf("Execucao do Bubble Sort\n");
	clock_t t;
	t = clock();
	int i;
	int j;
	int comp = 0;
	for(j = 1; j <= tam; j++) {
		int flag = 1;
		for(i = 0; i < tam-j; i++) {
			comp++;
			if( v[i] > v[i+1]) {
				swap(&v[i], &v[i+1]);
				flag = 2;
			}
		}
		if(flag == 1) break;
	}
	printf("Comparacoes: %d\n", comp);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Tempo de execucao: %f segundos para executar.\n\n", time_taken);
}

void selectionSort (int tam, int *v){
	printf("Execucao do Selection Sort\n");
	clock_t t;
	t = clock();
	int i;
	int menor;
	int comp = 0;
	int j;
	for(j = 0; j < tam-1; j++){
		menor = j;
		for(i = j+1; i < tam; i++){
			comp++;
			if(v[i] < v[menor]) menor = i;
		}
		swap(&v[j], &v[menor]);
	}
	printf("Comparacoes: %d\n", comp);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Tempo de execucao: %f segundos para executar.\n\n", time_taken);
}

void insertionSort(int tam, int *v){
	printf("Execucao do Insertion Sort\n");
	clock_t t;
	t = clock();
	int i;
	int j;
	int aux;
	int comp = 0;
	
	for (i = 1; i < tam; i++){
		aux = v[i];
		for(j = i-1; j >= 0 && v[j] > aux; j--){
			comp++;
			v[j+1] = v[j];
		}
		v[j+1] = aux;
	}
	printf("Comparacoes: %d\n", comp);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Tempo de execucao: %f segundos para executar.\n\n", time_taken);
}

void main () {
	int tam;
	int *v;
	int k;
	char arquivo[100];
	printf("Numero de elementos: \n");
	scanf("%d", &tam);
	v = (int *) malloc(tam * sizeof(int));
	printf("Nome do arquivo: \n");
	scanf("%s", arquivo);
	FILE *p = fopen(arquivo, "r");
	for(int i = 0; i < tam; i++) fscanf(p, "%d", &v[i]);
	fclose(p);
	
	printf("Digite 1 para aplicar Buuble Sort.\nDigite 2 para aplicar Selection Sort.\nDigite 3 para aplicar Insertion Sort.\nDigite 4 para executar os tres algoritmos.\n");
	scanf("%d", &k);
	switch(k){
		case 1:
			bubbleSort(tam, v);
			break;
		case 2:
			selectionSort(tam, v);
			break;
		case 3:
			insertionSort(tam, v);
			break;
		case 4:
			insertionSort(tam, v);
			p = fopen(arquivo, "r");
			for(int i = 0; i < tam; i++) fscanf(p, "%d", &v[i]);
			fclose(p);
			
			bubbleSort(tam, v);
			p = fopen(arquivo, "r");
			for(int i = 0; i < tam; i++) fscanf(p, "%d", &v[i]);
			fclose(p);
			
			selectionSort(tam, v);
			
			break;
	}
}
