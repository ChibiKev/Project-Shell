// Worked on by Andy Li

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sh_path(char **args){
	FILE* file = fopen("t2.txt", "w");
	if(file == NULL)
	{
		printf("File t2.txt not found. Aborting command...\n");
		return 1;
 	}
	char current[1024];
	char c;
	getcwd(current, sizeof(current));
	printf("Current directory: user@user:~%s->\n", current);
	printf("Writing current directory to t2.txt\n");
	fputs(current, file);
	fclose(file);
	rename("t2.txt", "path-info.txt");
	printf("Renamed t2.txt to path-info.txt\n");

	FILE* tree = fopen("tree.txt", "r");
	FILE* path = fopen("path-info.txt", "r");
	FILE* t3 = fopen("t3.txt", "a");

	if(tree == NULL || t3 == NULL)
	{
		printf("Missing necessary files. Please make sure tree.txt and t3.txt are in the current directory. Aborting command...\n");
		return 1;
	} 
	c = fgetc(tree);
	while(c != EOF)
	{
		fputc(c, t3);
		c = fgetc(tree);
	} 

	c = fgetc(path);
	while(c != EOF)
	{
		fputc(c, t3);
		c = fgetc(path);
	}
	rename("t3.txt", "log.txt");
	printf("Concatenated tree.txt and path-info.txt into t3.txt and renamed t3.txt to log.txt\n");

	remove("tree.txt");
	remove("path-info.txt");
	printf("Deleted tree.txt and path-info.txt files.\n");
	return 0;
}
