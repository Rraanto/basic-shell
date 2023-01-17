#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <readline/readline.h> 

#define MAX_PATH 32

/**
 * accept the command as user input 
 */ 
char **get_input (char *input) {
    char **command = malloc(8 * sizeof(char *));
    if (command == NULL) {
        perror("out of memory");
        exit(1); 
    }
    char *separator = " "; 
    char *parsed; 
    int index = 0; 

    // the command split with spaces to an array 
    parsed = strtok(input, separator); 
    while (parsed != NULL) {
        command[index] = parsed; 
        index++; 

        parsed = strtok(NULL, separator); 
    }

    command[index] = NULL; 
    return command; 
}

/**
 * implementation of cd, as some built in commands can't be executed with forked exec
 */
int cd (char *path) {
    return chdir(path); 
}

/**
 * executes a command, same parameters as execv with proper determinism (fork) 
 * */
int execInChild(char *arg, char **argv) {
    pid_t child_pid; 
    int stat_loc; 

    child_pid = fork(); 
    
    // execute child process 
    if (child_pid == 0) {
        if(execvp(arg, argv) < 0) {
            perror(arg); 
            exit(1); 
        } 
    }
    // main process 
    else {
        waitpid(child_pid, &stat_loc, WUNTRACED); 
    }
}

int main() {
    char **command; // to store the array of commands 
    char *input;    // to receive the user input 
    
    while (1) {
        // read input from user 
        input = readline("$"); 
        command = get_input(input); 
        
        if (strcmp(command[0], "cd") == 0) {
            if (cd(command[1]) < 0) {
                perror(command[1]); 
            }
        } else {
            execInChild(command[0], command); // execute the command 
        }

        free(command); 
    }
}
