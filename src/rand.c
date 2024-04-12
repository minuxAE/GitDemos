#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Use a better random generator
void init_rand(void){
	srand(time(NULL));
}

// To generate random integer
int random_int(int max){
	return rand() * max / RAND_MAX;
}

// Add Test function
void say_hello(){
	printf("Hello Git!\n");
}

// Main Function
int main(int argc, char *argv[]){
	if(argc!=2){
		fprintf(stderr, "Usage : %s <number>\n", argv[0]);
		return EXIT_FAILURE;
	}
	
	init_rand(); // work on the Win11 OS
	// transform to integer
	int max = atoi(argv[1]);
	// srand(time(NULL));
	int res = random_int(max);
	printf("%d\n", res);

	return EXIT_SUCCESS;
}
