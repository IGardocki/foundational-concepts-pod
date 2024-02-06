#pragma once
#include <stdlib.h>


// // function to generate random numbers for benchmarking
// int *generate_random_numbers(int number_of_items){
//     int * random_numbers = malloc(sizeof(int) * number_of_items);
//     srand(0);
//     for (int i = 0; i < number_of_items; i++) {
//         random_numbers[i] = rand();
//     }
//     return random_numbers;
// }

// define codes for results. We don't need to return many results in C since we store results of functions via memory addresses, so it is better to
// return a result code.
// According to Dale, the k prefix to the code names is from the Google standard.

typedef enum Result {
    kSuccess = 0,
    kFailure = -1,
    kFound = 2,
    kNotFound = 3,
    kNullGuard = -2
} Result;

typedef Result ResultCode; 