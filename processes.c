#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h> 

#include "processes.h"

int execInChild(char *arg, char **argv) {
    pid_t child_pid; 
    int stat_loc; 

    child_pid = fork(); // entry point in the fork: creation of a child process

    if (child_pid == 0) {             // inside child process 
        if (execvp(arg, argv) < 0) {  // execution of the program, 
                                      // if it fails, returns -1 then shows error 
            perror(arg); 
            exit(1)    ; 
        }
    }

    else {              // back to parent process 
        waitpid(child_pid, &stat_loc, WUNTRACED); 
    }
}
