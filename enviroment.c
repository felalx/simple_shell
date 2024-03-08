#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

int main(void) {
    char command[100];
    char *args[10];

    while (1) {
        printf("$ ");
        fgets(command, sizeof(command), stdin);
        strtok(command, "\n");  // remove trailing newline

        if (strcmp(command, "exit") == 0) {
            exit(EXIT_SUCCESS);
        } else if (strcmp(command, "env") == 0) {
            char **env = environ;
            while (*env != NULL) {
                printf("%s\n", *env);
                env++;
            }
            continue;
        }

        args[0] = command;
        args[1] = NULL;

        if (fork() == 0) {
            if (execve(args[0], args, NULL) == -1)
                perror("Error");
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
        }
    }

    return (0);
}
