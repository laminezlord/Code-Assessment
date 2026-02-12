#include <stdio.h>
#include <string.h>
#include "functions.h"

int main()
{
    printf("===== Assignment 10: Function Testing =====\n\n");
    
    // Test 1: count_vowels
    printf("1. Testing count_vowels():\n");
    printf("   Input: \"hello\"\n");
    printf("   Output: %d vowels\n\n", count_vowels("hello"));
    
    // Test 2: reverse_string
    printf("2. Testing reverse_string():\n");
    char str[] = "hello";
    printf("   Input: \"%s\"\n", "hello");
    reverse_string(str);
    printf("   Output: \"%s\"\n\n", str);
    
    // Test 3: is_palindrome
    printf("3. Testing  a palindrome():\n");
    printf("   Input: \"madam\"\n");
    printf("   Output: %d (1 = yes, 0 = no)\n", is_palindrome("madam"));
    printf("   Input: \"hello\"\n");
    printf("   Output: %d (1 = yes, 0 = no)\n\n", is_palindrome("hello"));
    
    // Test 4: is_prime
    printf("4. Testing  a prime():\n");
    printf("   Input: 7\n");
    printf("   Output: %d (1 = yes, 0 = no)\n", is_prime(7));
    printf("   Input: 10\n");
    printf("   Output: %d (1 = yes, 0 = no)\n\n", is_prime(10));
    
    // Test 5: print_fibonacci
    printf("5. Testing print_fibonacci():\n");
    printf("   Input: 5\n");
    printf("   Output: ");
    print_fibonacci(5);
    printf("\n");
    
    // Test 6: find_max
    printf("6. Testing find_max():\n");
    int arr1[] = {1, 2, 3, 4, 5};
    printf("   Input: [1, 2, 3, 4, 5], size = 5\n");
    printf("   Output: %d\n\n", find_max(arr1, 5));
    
    // Test 7: sort_array
    printf("7. Testing sort_array():\n");
    int arr2[] = {5, 2, 8, 1, 9};
    printf("   Input: [5, 2, 8, 1, 9], size = 5\n");
    sort_array(arr2, 5);
    printf("   Output: [");
    for (int i = 0; i < 5; i++) {
        printf("%d", arr2[i]);
        if (i < 4) printf(", ");
    }
    printf("]\n\n");
    
    printf("===== All tests completed =====\n");
    
    return 0;
}
