#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "HeaderFiles/tree.h"
#include "HeaderFiles/list.h"
#include "HeaderFiles/path.h"
#include "HeaderFiles/exit.h"

char current[1024]; // Global Current Directory, In Case It Gets Changed
char commands[1024][50];
int count = 0;

void runShell();
void currentDirectory();
void help();


void runShell(){
	getcwd(current, sizeof(current)); // Get Our Current Folder Location
	while(1){ // Constant Running Shell Loop
		currentDirectory(); // Output Shell Setup
		char input[1024]; // String To Take Input
		fgets(input,1024,stdin); // Obtain Input
		int length = strlen(input); // Get Length of Input
		input[length-1]='\0'; // Limit The length so it Isn't 1024.
		strcpy(commands[count++],input);
		if(strcmp(input,"help") == 0){ // Help
			help();
		}
		else if(strcmp(input,"tree") == 0){ // Tree
			sh_tree(NULL);
			getcwd(current, sizeof(current)); // Get Our Current Folder Location
		}
		else if(strcmp(input,"list") == 0){ // List
			sh_list(NULL);
		}
		else if(strcmp(input,"path") == 0){ // Path
			sh_path(NULL);
		}
		else if(strcmp(input,"exit") == 0){ // Exit
			break;
		}
		else{ // Incorrect Input
			printf("Invalid Input, You Inputted %s. Type 'help' For List of Commands. \n", input);
		}
	}
	sh_exit(commands,count); // Exit
}


void currentDirectory(){ // Outputs Current Directory Using Global Variable
	printf("user@user:~%s->",current);
}

void help(){ // Help
	printf("List of Commands Avaliable:\n");
	printf("___________________________\n");
	printf("tree: this new command will create a directory and call it Dir0. Then it will change the working directory to Dir0, and create three empty text files namely; t1.txt, t2.txt, and t3.txt, and one empty directory, called Dir1, inside it.\n\n");
	printf("list: this new command will clear the terminal screen and print a detailed list of all content of the current directory (similar to ls -l) to the terminal and t1.txt. Finally, it will change the name of text file to tree.txt.\n\n");
	printf("path: this new command will print the path of the current directory to the terminal and t2.txt, and change the name of text file to path-info.txt. Concatenate the content of tree.txt and path.txt into t3.txt and change the last to log.txt. Finally, delete tree and path text files.\n\n");
	printf("exit: this new command will print a list the last 4 commands to the terminal, a detailed list of all content of the current directory (similar to ls -l). Finally, it will wait for the user to hit the “return” key to terminate the shell and return the control to the original shell program on your machine.\n\n");
}

int main (){ // Main
	runShell(); // Shell Function
	return 0;
}
