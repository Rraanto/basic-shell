#ifndef BUILTINS_H
#define BUILTINS_H

/* 
 * @file builtins: header file for the module builtins containing the implementations 
 * of builtin functions (cd, help) 
 */ 

/*
 * @function cd: goes to a specific directory given as argument. 
 * @param path: path (absolute or relative) to the destination directory 
 * @returns: -1 if errors occur, 0 otherwise 
 */ 
int cd(char *path); 

/* 
 * @function help: displays help message concerning the shell
 */
void help(); 


#endif 
