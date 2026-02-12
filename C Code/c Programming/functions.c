#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

// Counts the number of vowels in a given string
int count_vowels(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

// Reverses a given string in place
void reverse_string(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

// Checks if a given string is a palindrome (returns 1 for yes, 0 for no)
int is_palindrome(char *str)
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

// Checks if a given number is prime (returns 1 for yes, 0 for no)
int is_prime(int num)
{
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Prints the first n numbers in the Fibonacci sequence
void print_fibonacci(int n)
{
    if (n <= 0) {
        return;
    }
    
    int a = 0, b = 1;
    printf("%d", a);
    
    for (int i = 1; i < n; i++) {
        printf(" %d", b);
        int temp = a + b;
        a = b;
        b = temp;
    }
    printf("\n");
}

// Finds the maximum value in a given array of integers
int find_max(int *arr, int size)
{
    if (size <= 0) {
        return 0;
    }
    
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Sorts a given array of integers in ascending order
void sort_array(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

}
