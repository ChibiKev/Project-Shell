#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define READ_END 0
#define WRITE_END 1


int sh_list(char **args) {

    //clear Screen();
    system("clear");

    int pid_ls;

    int file_desc = open("t1.txt", O_WRONLY | O_CREAT, 0666);


    // Fork a process to run ls -l
    pid_ls = fork();

    if (pid_ls < 0) {
        fprintf(stderr, "parent: Could not fork process to run ls\n");
        return -1;
    } else if (pid_ls == 0) {

        printf("\n");

        dup2(file_desc, 1);



        // Setup the arguments/environment to call
        char *new_argv[] = {"ls", "-l", 0};

        // Call execvp() which will replace the executable image of this
        // process
        execvp(new_argv[0], new_argv);

        // Execution will never continue in this process unless execve returns
        // because of an error
        fprintf(stderr, "child ls -l failed!\n");
        return -1;
    } else {

        close(file_desc);
        // Wait for children to finish
        wait(NULL);



        // open file and print to stdout
        FILE *file = fopen("t1.txt", "r");
        if (file == NULL) {
            printf("File t1.txt not found.\n");
            return 1;
        }
        char c;

        c = fgetc(file);
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(file);
        }

        fclose(file);

        // renaming file

        rename("t1.txt", "tree.txt");

    }

    return 0;
}


