#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Function prototypes

// Counts the number of vowels in a given string
int count_vowels(char *str);

// Reverses a given string in place
void reverse_string(char *str);

// Checks if a given string is a palindrome (returns 1 for yes, 0 for no)
int is_palindrome(char *str);

// Checks if a given number is prime (returns 1 for yes, 0 for no)
int is_prime(int num);

// Prints the first n numbers in the Fibonacci sequence
void print_fibonacci(int n);

// Finds the maximum value in a given array of integers
int find_max(int *arr, int size);

// Sorts a given array of integers in ascending order
void sort_array(int *arr, int size);

#endif
