#include <stdio.h>

int main() {
    // Single Dimensional Arrays
    printf("Single Dimesnional Array Access\n");
    int single_dimension_array[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int *p_single_dimension_array = single_dimension_array;
    // printing using array indexes
    for (int i = 0; i < 8; i++) {
        printf("%i ", single_dimension_array[i]);
    }
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf("%i ", *(p_single_dimension_array + i));
    }
    printf("\n");

    // Mulit Dimensional Arrays
    printf("Multi Dimesnional Array Access\n");
    int two_dimension_array[2][4] = {{0, 1, 2, 3},
                                     {4, 5, 6, 7}}; // row major form
    // columns are 4 wide, aka "stride"
    // 0, 1, 2, 3
    // 4, 5 ,6, 7

    // Looks like this in memory
    // 0, 1, 2, 3, | 4, 5 ,6, 7

    int *p_two_dimension_array = (int *) two_dimension_array;
    // printing using array indexes
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%i ", two_dimension_array[row][col]);
        }
    }
    printf("\n");
    // p_two_dimension_array is element 0
    // add length of row * row length to access first element of that row
    // add column number col to get offset to that column
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 4; col++) {
            printf("%i ", *(p_two_dimension_array + (row * 4) + col));
        }
    }
    printf("\n");

    printf("Multi Dimesnional Array Access with single dimensional array\n");
    p_single_dimension_array = (int *) two_dimension_array;
    for (int i = 0; i < 8; i++) {
        // using an array pointer like an array
        printf("%i ", p_single_dimension_array[i]);
    }
    printf("\n");

    printf("Multi Dimesnional Array Access with col major access\n");
    for (int col = 0; col < 4; col++) {
        // for each col
        for (int row = 0; row < 2; row++) {
            // for each row
            printf("%i ", *(p_two_dimension_array + (row * 4) + col));
        }
    }
    printf("\n");
    return 0;
}