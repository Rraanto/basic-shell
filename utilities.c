#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <readline/readline.h> 

#include "utilities.h"

char **parseInput(char *s) {
    char **command = malloc(8 * sizeof(char *)); // to store the output 
    if (command == NULL) {
        perror("Memory error (OS)"); // mostly max capacity reached 
        exit(1)                    ;  
    }

    char *sep = " "; 
    char *parsed; 

    int id; 
    parsed = strtok(s, sep); 
    for (id=0; parsed != NULL; id++) { // fill command array 
        command[id] = parsed; 
        parsed = strtok(NULL, sep); 
    }

    command[id] = NULL; 
    return command; 
}
