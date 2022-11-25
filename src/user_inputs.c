
#include "user_inputs.h"
#include <stdio.h>

/**
 * user_inputs scans the starting city in the train network together with the destination. These can later be used by other
 * functions to calculate the shortest distance between them.
 * @param departure is the starting city in the network
 * @param arrival is the destination in the network
 */
void user_inputs (int *departure, int *arrival) {
    printf("\nInput user starting city>");
    scanf("%d", departure);

    printf("Input user destination>");
    scanf("%d", arrival);
}
