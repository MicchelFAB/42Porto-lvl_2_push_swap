#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *ft_calloc(size_t nmemb, size_t size);

int main(void) {
    int *numbers;
    size_t i;

    // Allocate an array of 5 integers using ft_calloc
    numbers = (int *)ft_calloc(5, sizeof(int));

    // Check if the allocation was successful
    if (numbers == NULL) {
        printf("Error: Unable to allocate memory.\n");
        return 1;
    }

    // Initialize the array with values 1 to 5
    for (i = 0; i < 5; i++) {
        numbers[i] = i + 1;
    }

    // Print the contents of the array
    printf("The array contains: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(numbers);

    return 0;
}

void *ft_calloc(size_t nmemb, size_t size) {
    void *ptr;

    // Allocate memory using malloc
    ptr = malloc(nmemb * size);

    // Check if the allocation was successful
    if (ptr == NULL) {
        return NULL;
    }

    // Initialize the memory to zero
    memset(ptr, 0, nmemb * size);

    return ptr;
}
