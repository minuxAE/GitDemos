#include <stdio.h>
#include <stdlib.h>

int compare(const void *n1, const void *n2){
	return (*(int *)n1 - *(int *)n2);
}

int main(){
	int num[5] = {39, 21, 77, 56, 32};
	qsort((void *)num, 5, sizeof(num[0]), compare);
	for(int i=0; i<5; ++i){
		printf("%d ", num[i]);
	}
	printf("\n");
	return 0;
}
