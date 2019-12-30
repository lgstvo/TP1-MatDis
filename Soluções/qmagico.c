#include <stdio.h>
#include <stdlib.h>

// calcula a soma da linha
int sum_line(int linha, int n, int** matriz){
	int i = 0, sum = 0;
	for(i = 0; i < n; i++){
		sum += matriz[linha][i];
	}
	return(sum);
}

// calcula a soma da coluna
int sum_col(int coluna, int n, int** matriz){
	int i = 0, sum = 0;
	for(i = 0; i < n; i++){
		sum += matriz[i][coluna];
	}
	return(sum);
}

// calcula a soma da diagonal
int sum_diag(int n, int** matriz){
	int i = 0, sum = 0;
	for(i = 0; i < n; i++){
		sum += matriz[i][i];
	}
	return(sum);
}

// calcula a soma da diagonal reversa
int sum_rev_diag(int n, int** matriz){
	int i = 0, sum = 0;
	for(n = n - 1; n >= 0; n--){
		sum += matriz[i][n];
		i++;
	}
	return(sum);
}

// checa as condições para o quadrado mágico
int check(int n, int** matriz, int sum_mag){
	int i = 0, linhas = 1, colunas = 1, diagonais = 1;
	for(i = 0; i < n; i++){
		linhas = linhas && (sum_line(i, n, matriz) == sum_mag);
	}
	for(i = 0; i < n; i++){
		colunas = colunas && (sum_col(i, n, matriz) == sum_mag);
	}
	diagonais = diagonais && (sum_diag(n, matriz) == sum_mag) && (sum_rev_diag(n, matriz) == sum_mag);

	return(linhas && colunas && diagonais);
}

// aplicacao do metodo siames
void siamese(int** store, int n){
	n = n-1;
	int i = 1, idxi = 0, idxj = n/2, value = 1;

	while(value != ((n+1)*(n+1) + 1)){
		if(idxi > n) idxi -= n+1;
		if(idxj < 0) idxj += n+1;
		if(idxi < 0) idxi += n+1;
		if(idxj > n) idxj -= n+1;
		if(store[idxi][idxj] != -1){
			idxi += 2;
			idxj--;
			continue;
		}
		store[idxi][idxj] = value;
		idxi--;
		idxj++;
		value++;
	}

}

// aplicacao do metodo para a construcao do quadrado n = 4
void four_method(int** store){
	int i = 0, j = 0;

	store[0][1] = 15;
	store[0][2] = 14;
	store[1][0] = 12;
	store[2][0] = 8;
	store[1][3] = 9;
	store[2][3] = 5;
	store[3][1] = 3;
	store[3][2] = 2;
}

// aplicacao do metodo siames para quadrantes de strachey
void strachey_siamese(int start, int end, int store[][3], int n){
	n = n-1;
	int i = 1, idxi = 0, idxj = n/2;

	while(start != (end + 1)){
		if(idxi > n) idxi -= n+1;
		if(idxj < 0) idxj += n+1;
		if(idxi < 0) idxi += n+1;
		if(idxj > n) idxj -= n+1;
		if(store[idxi][idxj] != -1){
			idxi += 2;
			idxj--;
			continue;
		}
		store[idxi][idxj] = start;
		idxi--;
		idxj++;
		start++;
	}

}

void unite(int** store, int A[][3], int C[][3], int D[][3], int B[][3], int n){
	int i = 0, j = 0;

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(i < 3 && j < 3) store[i][j] = A[i][j];
			if(i < 3 && j >= 3) store[i][j] = C[i][j-3];
			if(i >= 3 && j < 3) store[i][j] = D[i-3][j];
			if(i >= 3 && j >= 3) store[i][j] = B[i-3][j-3];
		}
	}
}

void invertAD(int** store){
	int aux = 0, i = 0;
	for(i = 0; i < 3; i++){
		aux = store[i][0];
		store[i][0] = store[i+3][0];
		store[i+3][0] = aux;
	}
}

void invertmiddle(int** store){
	int aux = 0;
	aux = store[1][1];
	store[1][1] = store[4][1];
	store[4][1] = aux;

	aux = store[1][0];
	store[1][0] = store[4][0];
	store[4][0] = aux;	
}



int main(){
	int n = 0, i = 0, j = 0, sum_mag = 0, count = 1;
	int qA[3][3], qB[3][3], qC[3][3], qD[3][3];

	scanf("%d", &n);

// calculo da soma mágica
	sum_mag = n*(n*n + 1)/2;

// alocacao
	int **matriz = (int**)(malloc(n * sizeof(int*)));
	for(i = 0; i < n; i++){
		matriz[i] = (int*)(malloc(n * sizeof(int)));
	}

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			matriz[i][j] = -1;
		}
	}

	

	switch(n){

		case 3:

			siamese(matriz, n);

			break;

		case 4:

			for(i = 0; i < n; i++){
				for(j = 0; j < n; j++){
					matriz[i][j] = count;
					count++;
				}
			}

			four_method(matriz);

			break;

		case 5:

			siamese(matriz, n);

			break;

		case 6:

			for(i = 0; i < 3; i++){
				for(j = 0; j < 3; j++){
					qA[i][j] = -1;
					qB[i][j] = -1;
					qC[i][j] = -1;
					qD[i][j] = -1;
				}
			}

			strachey_siamese(1,9,qA,3);
			strachey_siamese(10,18,qB,3);
			strachey_siamese(19,27,qC,3);
			strachey_siamese(28,36,qD,3);

			unite(matriz, qA, qC, qD, qB, n);

			invertAD(matriz);
			invertmiddle(matriz);

			break;

	}

	printf("n = %d, Soma = %d\n", n, sum_mag);

	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d\t", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for(i = 0; i < n; i++){
		free(matriz[i]);
	}
	free(matriz);

	return 0;
}

