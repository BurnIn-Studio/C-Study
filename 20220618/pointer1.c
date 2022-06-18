#include<stdio.h>

int sum(int c, int d);
int main(void){
	int a = 10;
	int b = 20;
	sum(a,b);
}

int sum(int c, int d){
	int sum;
	
	sum = c+d;
	printf("sum : %d", c+d);
}
