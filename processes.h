#ifndef PROCESSES_H
#define PROCESSES_H 

/*
 * @file processes.h
 * Header file for the module that handles processes
 */ 

/*
 * @function execInChild
 * Has the same signature as execvp 
 * Executes a given program in a child process, then goes back to the parent process
 * using fork() 
 * @param prg: the name of the program to be executed (ex: ls)
 * @param args: array of strings the first one is the name of the program to be executed, 
 *             then all arguments to be given, the last element of the array must be: NULL
 *
 * @returns nothing if the program execution is successful, -1 otherwise
 *
 */ 
int execInChild(char *arg, char **argv); 

#endif
