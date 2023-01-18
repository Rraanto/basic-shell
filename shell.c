#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <readline/readline.h> 

#include "processes.h"
#include "builtins.h"
#include "utilities.h"

#define MAX_PROMPT 32


int main() {
    char **command; // to store the array of commands 
    char *input;    // to receive the user input 
    
    // getting username to use as prompt 
    char *prompt = (char*)malloc(MAX_PROMPT);   
    FILE *tmp = popen("whoami", "r"); 
    int i; 
    for (i=0; !feof(tmp); i++) 
        fscanf(tmp, "%c", &prompt[i]);

    prompt[i-2] = '\0'; // removing \n
    
    while (1) {

        // read input from user 
        printf("%s", prompt); 
        input = readline("$ "); 
        command = parseInput(input); 
        
        if (strcmp(command[0], "exit") == 0)
            return 0;                          // quit the program 

        if (strcmp(command[0], "cd") == 0) {   // cd 
            if (cd(command[1]) < 0) 
                perror(command[1]); 
        } 
        else if (strcmp(command[0], "help") == 0) { // help 
            help(); 
        }
        else {
            execInChild(command[0], command); // execute the command 
        }

        free(command); 
    }
}
