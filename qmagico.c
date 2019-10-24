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



int main(){
	int n = 0, **matriz, i = 0, j = 0, num_max = 0, sum_max = 0, sum_mag = 0, counter = 0;

	scanf("%d", &n);
	num_max = n*n;

// alocação da matriz
	matriz = (int**)malloc(n * sizeof(int));
	for(i = 0; i < n; i++){
		matriz[i] = (int*)malloc(n* sizeof(int));
	}

// calculo da soma total da matriz
	for(i = 1; i <= num_max; i++){
		sum_max += i;
	}

// inicialização da matriz
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			counter++;
			matriz[i][j] = counter;
		}
	}

// calculo da soma mágica
	sum_mag = n*(n*n + 1)/2;








// liberação
	for(i = 0; i < n; i++){
		free(matriz[i]);
	}

	free(matriz);

	return 0;
}