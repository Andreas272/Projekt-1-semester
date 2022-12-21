#include "route_cal.h"
#include "user_inputs.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * user_inputs scans the starting city in the train network together with the destination. These can later be used by other
 * functions to calculate the shortest distance between them.
 * @param origin is the starting city in the network
 * @param destination is the destination in the network
 */
void user_inputs (int *origin, int *destination) {
    print_line();
    printf("The available citys, 1 - %d\n",array_size);
    printf("\nInput user starting city>");
    scanf("%d", origin);

    printf("Input user destination>");
    scanf("%d", destination);


    // Termination of program if input is invalid
    int station_array[array_size];
    for(int i=0; i<array_size; i++){
        station_array[i]= i + 1;
    }

    int presence_origin = 0, presence_departure = 0;

    for(int i = 0; i < array_size; i++)
    {
        if(station_array[i] == *origin)
        {
            presence_origin++;
        }
        if(station_array[i] == *destination)
        {
            presence_departure++;
        }
    }

    if(presence_origin ==0 || presence_departure==0 )
    {
        printf("Invalid input. The program will terminate");
        exit(EXIT_FAILURE);
    }
}


/**
 * Ask the user for the next action.
 * @return the user input in the form of an int.
 */
int ask_action(){
    int scan=-1;
    print_line();
    printf("What do you want to do?\n");
    printf("\t(0) Exit program\n");
    printf("\t(1) Rerun fastest route calculation\n");
    printf("\t(2) Change route time\n");
    printf("\t(3) Print time array\n");
    printf(">");
    scanf("%d", &scan);

    return scan;
}

/**
 * Asks the user for time units in data file
 * @return the user input as an int
 */
int ask_units(int choose_file) {
    int scan;

    if (choose_file == 0) {

        // Define units of users data
        print_line();
        printf("What is the time unit of the supplied data?\n");
        printf("\t(1) Minutes\n");
        printf("\t(2) Hours\n");
        printf(">");
        scanf("%d", &scan);


        return scan;
    }

    else if (choose_file == 1){
        scan = 1;
        return scan;
    }
    else if (choose_file == 2 || choose_file == 3 || choose_file == 4)
    {
        scan = 2;
        return scan;
    }
        else {
        printf("Invalid input. The program will terminate");
        exit(EXIT_FAILURE);
        }}

/**
 * Asks the user for which data set to use
 * @return the user intput as an int
 */
int data_selector() {
    int scan;
    print_line();
    printf("Which data file do you want to use?\n");
    printf("\t(0) my_data.txt\n");
    printf("\t(1) data_11Station_minutes.txt\n");
    printf("\t(2) data_11Station_hours.txt \n");
    printf("\t(3) data_6Station_hours.txt \n");
    printf("\t(4) data_4Station_hours.txt \n");
    printf(">");
    scanf("%d", &scan);

    if (!((scan == 0) || (scan == 1) || (scan == 2) || (scan == 3) || (scan == 4))) {
        printf("Invalid input. The program will terminate");
        exit(EXIT_FAILURE);
    }
    return scan;
}