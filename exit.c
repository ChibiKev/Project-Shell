#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sh_exit(char **args){
	printf("exit\n");
	return 1;
}