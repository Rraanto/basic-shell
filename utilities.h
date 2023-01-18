#ifndef UTILITIES_H
#define UTILITIES_H

/*
* @file utilities.h 
 * header file for module utilities: contains auxiliary functions used for manipulating 
 * strings 
 */ 

/**
 * @function parseInput: parses an input (string) to an array of strings by splitting 
 * the input with the space character and adds the NULL element at the end. The returned 
 * format is compatible to be used as an argument with argvp function 
 * @param s: (char pointer) the string to parse 
 * @returns: an array of strings 
 */ 
char **parseInput (char *s);


#endif 
