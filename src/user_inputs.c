#include "route_cal.h"
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


/**
 * Ask the user for the next action.
 * @return the user input in the form of an int.
 */
int ask_action(){
    int scan;
    print_line();
    printf("What do you want to do?\n");
    printf("\tExit program(0)\n");
    printf("\tRerun fastest route calculation(1)\n");
    printf("\tChange route time(2)\n");
    printf("\tPrint time array(3)\n");
    printf(">");
    scanf("%d", &scan);

    return scan;
}