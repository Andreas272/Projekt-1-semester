#include <stdio.h>
#include "Scan_data.h"
#include "route_cal.h"
#include "user_inputs.h"


int array_size = 0;

int main(void) {
    int departure, arrival, train_time, plane_time, ask = 1;

    //This function finds the array size.
    array_size = file_array_size();

    printf("The available citys, 1 - %d\n",array_size);

    //Takes inputs from user of starting city and destination city
    user_inputs(&departure, &arrival);

    //Creates the 2d array for trains
    int time_array[array_size][array_size];

    //Creates the 2d array for planes
    int plane_time_array[array_size][array_size];

    //Reads the data form the data file into the 2d plane array.
    plane_reader(plane_time_array,array_size);

    //Reads the data form the data file into the 2d array.
    data_reader (time_array,array_size);

    //Will be 0 if no airport are available in the chosen citys.
    plane_time = plane_route_cal(plane_time_array,departure - 1,arrival - 1);


    //This while loop is to keep the program running until stoped by user.
    while (ask != 0) {

        //If the user input is 1, the program will rerun the calculation of the fastest route.
        if (ask == 1) {
            //Calculation of the shortest route in the train network
            train_time = route_cal(time_array, departure - 1, arrival - 1);

            //Only prints plane time if there is available airports.
            if (plane_time > 0) {
                int timer = (plane_time / 60), min = (plane_time % 60);
                printf("Time to reach end station by plane: %dh:%dmin", timer, min);
            } else
                printf("There is no flights between these stations.");

            //Prints the fastest time of plane or train, depending on with is fastest.
            travel_comparison(plane_time, train_time);
        }

        //If the user input is 2, the program will run the change route funktion.
        else if(ask == 2)
            change_route_time(time_array);

        //If the user input is 3, the program will print the time array for trains.
        else if(ask == 3){
            printf("Train time array:");
            print_array(time_array,array_size);//Prints the array
            print_line();
            printf("Plane time array:");
            print_array(plane_time_array,array_size);
        }

        //Asks the user for the next action, 1 rerun, 2 change route, 3 print array, 0 exit.
        ask = ask_action();
    }

    return 0;
}
