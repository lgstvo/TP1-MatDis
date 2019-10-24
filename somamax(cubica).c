#include <stdio.h>
#include <stdlib.h>

int main(){

	int n = 0, init = 0, end = 0, iter = 0, r_init = 0, r_end = 0;
	float *vet, s_total = 0, s_aux = 0;

	scanf("%d", &n);

	vet =  (float*) malloc(n * sizeof(float));

	for(iter = 0; iter < n; iter++){
		scanf("%f", &vet[iter]);
	}

	for(init = 0; init < n; init++){
		for(end = 1; end <= n; end++){
			for(iter = init; iter < end; iter++){
				s_aux += vet[iter];
			}
			if(s_aux >= s_total){
				s_total = s_aux;
				r_init = init+1;
				r_end = end;
			}
			s_aux = 0;
		}
	}

	if(s_total <= 0){
		s_total = 0;
		r_init = 1;
		r_end = n;
	}

	printf("Soma: %.1f\nIndices: %d a %d\n", s_total, r_init, r_end);

	free(vet);

	return 0;
}