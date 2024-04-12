#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// To generate random integer
int random_int(int max){
	return rand() % max;
}

int main(int argc, char *argv[]){
	if(argc!=2){
		fprintf(stderr, "Usage : %s <number>\n", argv[0]);
		return EXIT_FAILURE;
	}

	int max = atoi(argv[1]);
	srand(time(NULL));
	int res = random_int(max);
	printf("%d\n", res);

	return EXIT_SUCCESS;
}
