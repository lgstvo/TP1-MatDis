#include <stdio.h>

int main(){

	int n = 0, r_init = 0, r_end = 0, init_aux = 1, i = 0;
	float entrada, s_total = 0, s_aux = 0;

	scanf("%d", &n);
	if(n < 3) n = 3;
	if( n > 20) n = 20;

	for(i = 0; i < n; i++){
		scanf("%f", &entrada);

		s_aux += entrada;

		if(s_aux < 0){
			s_aux = 0;
			init_aux = i+2;
		}
		if(s_aux >= s_total){
			s_total = s_aux;
			r_init = init_aux;
			r_end = i+1;
		}
	}

	if(s_total <= 0){
		s_total = 0;
		r_init = 1;
		r_end = n;
	}

	printf("Soma: %.1f\nIndices: %d a %d\n", s_total, r_init, r_end);
	return 0;
}