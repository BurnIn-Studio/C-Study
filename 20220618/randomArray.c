#include <stdio.h>
#include <stdlib.h>

void main(){
	int i;

	int data[10];

	srand((int)time(NULL));

	for (i = 0; i < 10; i++){
	data[i] = rand() % 100;
	}
	
	for (i = 0; i < 10; i++){
	printf("%d ", data[i]);
	}
	
	int *firstpoint = data[10];
	
	int sumresult = getMinMax();
	
	printf("SumResult: %d", sumresult);
	
	changelist();
	
	for (i = 0 ; i < 10; i ++) printf("%d", firstpoint[i]);
}

int getMinMax( int *firstpoint){
	
    int max = firstpoint[0];
    int min = firstpoint[0];
    
    int i;
    
    for (i = 0; i < 10; i++) {
        if (firstpoint[i] > max) max = firstpoint[i];
        if (firstpoint[i] < min) min = firstpoint[i];
    }
    
    int sumresult = max+min; 
    return sumresult;
}

void changelist(int *firstpoint){
	
	int left, right;
	
	int i,temp;
	
	for(i = 0; i < 10 ; i++)
	
	left = 0;
	right = 10 -1;
	
	for(i = 0 ; i < 10 / 2 ; i++){
		temp = firstpoint[left];
		firstpoint[left] = firstpoint[right];
		firstpoint[right] = temp;
		
		left ++;
		right --;
	}
	
}

