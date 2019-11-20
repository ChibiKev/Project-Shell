//Worked on by Andy Li

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

 int sh_path(char **args){
	FILE* file = fopen("t2.txt", "w"); // open t2.txt in write mode to write path to
	if(file == NULL) // t2.txt doesn't exist
 	{
		printf("File t2.txt not found. Aborting command...\n");
		return 1;
	}
	char c; // used to write file contents to t3.txt
	char current[1024]; // used to store current directory
	getcwd(current, sizeof(current)); //get current directory and store in current var
	printf("Current directory: %s\n", current);
	fputs(current, file); // write current dir to t2.txt
	fclose(file);
	rename("t2.txt", "path-info.txt"); // rename t2.txt to path-info.txt
	printf("Renamed t2.txt to path-info.txt\n");

	FILE* tree = fopen("tree.txt", "r"); // open tree.txt to read contents and store into t3
	FILE* path = fopen("path-info.txt", "r"); // open path-info.txt to read contents and store into t3
	FILE* t3 = fopen("t3.txt", "a"); // open t3.txt to append to from tree.txt and path-info.txt

	if(tree == NULL || t3 == NULL) // tree.txt or t3.txt doesn't exist
	{
		printf("Missing necessary files. Please make sure tree.txt and t3.txt are in the current directory. Aborting command...\n");
		return 1;
	}
	c = fgetc(tree);
	while(c != EOF) // write tree.txt contents into t3.txt
	{
		fputc(c, t3);
		c = fgetc(tree);
	}

	c = fgetc(path);
	while(c != EOF) // write path-info.txt contents into t3.txt
	{
		fputc(c, t3);
		c = fgetc(path);
	}
	rename("t3.txt", "log.txt");
	printf("Concatenated tree.txt and path-info.txt into t3.txt and renamed t3.txt to log.txt\n");

	remove("tree.txt"); // delete tree.txt
	remove("path-info.txt"); // delete path-info.txt
	printf("Deleted tree.txt and path-info.txt files.\n");
	return 0;
}
