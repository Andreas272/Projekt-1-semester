#include <stdio.h>
#include "Scan_data.h"
#include "route_cal.h"
#include "user_inputs.h"


int array_size = 0;

int main(void) {
    int departure, arrival, train_time, ask = 1;
    int plane_time;//variables for the starting and ending city

    //Takes inputs from user of starting city and destination city
    user_inputs(&departure, &arrival);

    //This function finds the array size.
    array_size = file_array_size();

    //Creates the 2d array for trains
    int time_array[array_size][array_size];

    //Creates the 2d array for planes
    int plane_time_array[array_size][array_size];

    //Reads the data form the data file into the 2d plane array.
    plane_reader(plane_time_array,array_size);

    //Reads the data form the data file into the 2d array.
    data_reader (time_array,array_size);

    //Enter places with airports (1 or 6 or 11)
    plane_time = plane_route_cal(plane_time_array,departure - 1,arrival - 1);



    while (ask != 0) {

        if (ask == 1) {
            //Calculation of the shortest route in the train network
            train_time = route_cal(time_array, departure - 1, arrival - 1);

            if (plane_time > 0) {
                int timer = (plane_time / 60), min = (plane_time % 60);
                printf("Time to reach end station by plane: %dh:%dmin", timer, min);
            } else
                printf("There is no flights between these stations.");

            travel_comparison(plane_time, train_time);
        }
        else if(ask == 2)
            change_route_time(time_array);
        else if(ask == 3)
            print_array(time_array,array_size);//Prints the array


        ask = ask_action();
    }

    return 0;
}