#include <stdio.h>
#include <string.h>
#include "5-functions.h"

// Test function
int main() {
    // Example string for testing
    char testString[81] = "Hello, World!";
    char expectedResult[81] = "!dlroW ,olleH";

    // Reverse the string using our compute function
    process(testString);

    // Check if the result matches the expected output
    if (strcmp(testString, expectedResult) == 0) {
        printf("Test Passed!\n");
        return 0;  // Indicates success
    } else {
        printf("Test Failed: Expected '%s', got '%s'\n", expectedResult, testString);
        return 1;  // Indicates failure
    }
}