#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include "red.h"

#define GIBBERISH_THRESHOLD 0.5 // Threshold for gibberish detection

// Function to check if a text is gibberish
bool is_gibberish(const char *text) {
    int non_alpha_count = 0;
    int total_count = 0;

    // Loop through each character in the text
    for (int i = 0; text[i] != '\0'; i++) {
        if (!isalpha(text[i])) {
            non_alpha_count++; // Count non-alphabetic characters
        }
        total_count++; // Count total characters
    }

    // Check for empty string
    if (total_count == 0) {
        return false; // An empty string is not gibberish
    }

    // Calculate the ratio of non-alphabetic characters
    float ratio = (float)non_alpha_count / (float)total_count;

    // Return true if the ratio exceeds the threshold
    return ratio > GIBBERISH_THRESHOLD;
}

// A simple grammar check function (dummy implementation)
void grammar_check(const char *text) {
    // Here, you can implement actual grammar checking logic.
    // For now, we will just print a message.
    printf("Grammar suggestions for improvement:\n");
    printf("- Check punctuation and sentence structure.\n");
    printf("- Ensure subject-verb agreement.\n");
    printf("- Avoid run-on sentences.\n");
}

// Function to read user input
char* my_get_string(void) {
    char *buffer = malloc(1024); // Allocate memory for input
    if (buffer == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }

    if (fgets(buffer, 1024, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
        return buffer; // Return user input
    }

    free(buffer); // Free memory only if fgets fails and buffer allocated
    return NULL; // Return NULL if reading fails
}

// Readability function implementation
void readability() {
    printf("provide a text atleast 100 words long, pls avoid gibberish\nText: "); // Prompt for user input
    char *text = my_get_string(); // Get user input

    if (text == NULL) {
        printf("Error reading input.\n");
        return; // Exit if input reading fails
    }

    // Check for gibberish
    if (is_gibberish(text)) {
        printf("The provided text is gibberish.\n");
        free(text); // Free allocated memory for the input string
        return;
    }

    int letters = 0;
    int sentences = 0;
    int words = 1; // Start with 1 word to account for the last word

    // Calculate letters, words, and sentences
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            letters++; // Count letters
        } else if (text[i] == ' ') {
            words++; // Count words
        } else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++; // Count sentences
        }
    }

    // Calculate the Coleman-Liau index
    float L = ((float)letters / (float)words) * 100;
    float S = ((float)sentences / (float)words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Determine Band Score based on adjusted internal scores
    int band_score;
    if (index >= 16) {
        band_score = 9; // Cap at Band 9 for highest complexity
    } else if (index <= 1) {
        band_score = 1; // Floor at Band 1 for lowest complexity
    } else {
        // Scale the index to fit the range 1-9
        band_score = (index - 1) / 2; // Scale index down to 1-9 range
        if (band_score < 1) {
            band_score = 1; // Ensure minimum is Band 1
        } else if (band_score > 9) {
            band_score = 9; // Ensure maximum is Band 9
        }
    }

    // Output the Band Score
    printf("Band Score: %i\n", band_score);

    // Perform grammar check
    grammar_check(text);

    free(text); // Free allocated memory for the input string
}
