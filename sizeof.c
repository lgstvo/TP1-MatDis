#include <stdio.h>
#include <stdlib.h>

int main(){

	float a = (float) sizeof(float);

	printf("%f", a);

	int b = (int) sizeof(int);

	printf("%d", b);

	return 0;
}