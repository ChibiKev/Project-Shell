#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int sh_tree(char **args){
	int fid;
    fid=fork();
    if(fid==0)								// Fork a child to make a new directory
    {
        mkdir("dir0",0777);					// Make dir0 with all access
        //wait(&status);
    }
    else if(fid<0)							// Prints error message if fork failed
    {
        printf("fork failed");
    }
    else
    {
        wait(NULL);				// wait for child to complete
		chdir("dir0");						// change directroy internally
        FILE *t1 = fopen("t1.txt","wb"); 	// Create t1.txt
        fclose(t1);
        FILE *t2 = fopen("t2.txt","wb"); 	// Create t2.txt
        fclose(t2);
        FILE *t3 = fopen("t3.txt","wb"); 	// Create t3.txt
        fclose(t3);
        mkdir("dir1",0777);					// Make dir1 with all access
	}
	return 0;
}