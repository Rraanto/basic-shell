#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

#include "builtins.h"

int cd(char *path) {
    return chdir(path); 
}

void help() {
    printf("Minimal unix shell built in C\n"); 
    printf("Type program names and argumets, press Enter to execute\n"); 
    printf("Type exit to exit the shell\n"); 
}

