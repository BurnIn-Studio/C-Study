#include<stdio.h>

void main()
{
	
	int c, d, result;
	
	input(&c, &d);
	
	result = sum(c, d);
	
	printf("%d", result);
	
}

void input(int *c, int *d){
	
	scanf("%d %d", c, d);
}

int sum(int a, int b){
	return a*b;
}
