#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int sh_tree(char **args){
	int fid,status;
    char string[50];
    sprintf(string, "ps -A >> dir0/file.txt");
    fid=fork();
    if(fid==0)
    {
        mkdir("dir0",0777);
		exit(0);
        //wait(&status);
    }
    else if(fid<0)
    {
        printf("fork failed");
    }
    else
    {
        int c1 = wait(NULL);
        char s[100];
        printf("%s\n", getcwd(s, 100));
        chdir("dir0");
        printf("%s\n", getcwd(s, 100));
        FILE *t1 = fopen("t1.txt","wb"); // Open or Create file.txt
        fclose(t1);
        FILE *t2 = fopen("t2.txt","wb"); // Open or Create file.txt
        fclose(t2);
        FILE *t3 = fopen("t3.txt","wb"); // Open or Create file.txt
        fclose(t3);
        mkdir("dir1",0777);
	}
	
}