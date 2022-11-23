//
// Created by anlyn on 23-11-2022.
//

#include "user_inputs.h"
#include "Scan_data.h"
#include <stdio.h>

/**
 * user_inputs scans the starting city in the train network together with the destination. These can later be used by other
 * functions to calculate the shortest distance between them.
 * @param start is the starting city in the network
 * @param end is the destination in the network
 */
void user_inputs (int *departure, int *arrival) {
    printf("\nInput user starting city");
    scanf("%d", departure);

    printf("Input user destination");
    scanf("%d", arrival);
}