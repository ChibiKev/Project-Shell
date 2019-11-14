#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void sh_exit(char commands[1024][50], int count){ // Take in 2D Array and Counts
	FILE *f = fopen("file.txt","wb"); // Open or Create file.txt
	for(int i = 0; i < count; i++){ // From 0 to When Exit is Typed
		fprintf(f,"%s\n",commands[i]); // Print Into file.txt of Each Command Written
	}
	fclose(f); // Close File
	printf("You've Successfully Exited, Check 'file.txt' For History of Commands.\n\n");
	printf("\tTeam D\n");
	printf("________________________\n");
	printf("     Team Members\n");
	printf("Kevin Chen (Team Leader)\n");
	printf("Tenzin Sherpa\n");
	printf("Andy Li\n");
	printf("Christian Pizarro\n");
	printf("Jia Peng (Alex) Zhen\n");
}