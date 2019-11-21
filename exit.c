// Worked on by Kevin Chen

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void sh_exit(char commands[1024][50], int count){ // Take in 2D Array and Counts
	printf("Last 4 Commands:\n"); // Print
	int start = count - 4; // Gets the Last Four Commands
	if (start < 4){ // If Less Than 4, Then Start at 0
		start = 0; // Start at 0
	}
	for(int i = start; i < count; i++){ // Prints the Last Four
		printf("%d: %s\n", i + 1, commands[i]); // Prints
	}
	int pid = fork(); // Fork
    if (pid < 0){ // Test For Fork Failed
        fprintf(stderr, "Fork Failed");
        exit(0);
    }
    if (pid > 0){ 
    	// Parent
    	wait(NULL); // Wait For Child
    	printf("\nHit The Return Key to Terminate The Shell\n"); // Print
    	getchar(); // Waits For Return Key
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
    else if (pid == 0){
    	// Child
    	char *myargs[3]; // Define Arg (ls -l)
    	myargs[0] = "ls";   // Perform ls
        myargs[1] = "-l"; // Perform -l
        myargs[2] =  NULL; // Marks End of Array
        execvp(myargs[0], myargs); // Execute ls -l
    	printf("This Shouldn't Run \n"); // In Case of Failure
    }
}