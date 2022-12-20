#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Scan_data.h"
#include "route_cal.h"
#include "user_inputs.h"

int array_size = 0;

int main(void) {
    int departure, arrival, train_time, plane_time, ask = 1,choose_file;
    int units;

    //Selection of data file
    choose_file=data_selector();
    units=ask_units();

    //This function finds the array size.
    array_size = file_array_size(choose_file);

    //Takes inputs from user of starting city and destination city
    user_inputs(&departure, &arrival);

    //Creates the 2d array for trains
    int time_array[array_size][array_size];

    //Creates the 2d array for planes
    int plane_time_array[array_size][array_size];

    //Reads the data form the data file into the 2d plane array.
    plane_reader(plane_time_array,array_size);

    //Reads the data form the data file into the 2d array.
    data_reader (time_array,array_size,units,choose_file);

    //Will be 0 if no airport are available in the chosen cities.
    plane_time = plane_route_cal(plane_time_array,departure - 1,arrival - 1);


    //This while loop is to keep the program running until stopped by user.
    while (ask != 0) {

        //If the user input is 1, the program will rerun the calculation of the fastest route.
        if (ask == 1) {
            //Calculation of the shortest route in the train network
            train_time = route_cal(time_array, departure - 1, arrival - 1);

            //Calculation of average travel time
            double avg_time;
            int sum=0;
            for (int i = 0; i < array_size; ++i) {
                    sum= sum + sum_time_from_origin(time_array, i);
            }

            double sum_double;
            sum_double= (double) sum;

            double array_size_double= (double) array_size;
            double n=(array_size_double)*(array_size_double-1);//Number of combinations of start and end cities P(11,,2)

            avg_time=sum_double/(2*n);

            //Printing average travel time
            int avg_time_int=floor(avg_time);
            double remainder= (avg_time- (double) avg_time_int)*60;
            int remainder_int=floor(remainder);
            int hours = avg_time_int / 60, mins = avg_time_int % 60;
            printf("The average travel time in the network: %dh %dm %ds\n",hours,mins,remainder_int);

            //Only prints plane time if there is data for available airports and if start and end stations have airports.
            if ((choose_file==1 || choose_file==2 )&& plane_time > 0) {
                int timer = (plane_time / 60), min = (plane_time % 60);
                printf("Time to reach end station by plane: %dh %dm", timer, min);
            } else
                printf("There is no flights between these stations.");

            //Prints the fastest time of plane or train, depending on with is fastest.
            travel_comparison(plane_time, train_time);
        }

        //If the user input is 2, the program will run the change route function.
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
        else{
            printf("Invalid input. The program will terminate");
            exit(EXIT_FAILURE);
        }

        //Asks the user for the next action, 1 rerun, 2 change route, 3 print array, 0 exit.
        ask = ask_action();
    }
    return 0;
}
