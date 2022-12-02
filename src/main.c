#include <stdio.h>
#include "Scan_data.h"
#include "route_cal.h"
#include "user_inputs.h"


int array_size = 0;

int main(void) {
    int departure, arrival, train_time, ask = -1;
    double plane_time;//variables for the starting and ending city

    //Takes inputs from user of starting city and destination city
    user_inputs(&departure, &arrival);

    //Enter places with airports (1 or 3 or 9)
    plane_time = plane_cal(departure, arrival);

    //This function finds the array size.
    array_size = file_array_size();


    //Creates the 2d array
    int time_array[array_size][array_size];

    //Inputs the data form the data.txt file into the 2d array.
    data_reader (time_array,array_size);

    //Prints the array
    print_array(time_array,array_size);


    while (ask != 0) {
        //Calculation of the shortest route in the train network
        train_time = route_cal(time_array, departure - 1, arrival - 1);
        printf("Time to reach end station by plane: %lf", plane_time);

        travel_comparison(plane_time, train_time);

        ask = ask_for_change();
        if (ask > 0)
            change_route_time(time_array);


    }

    return 0;
}


