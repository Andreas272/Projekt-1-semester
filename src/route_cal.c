#include <stdio.h>
#include <stdlib.h>
#include "route_cal.h"
#include "Scan_data.h"

/**
 * This functions is for the printing of the fastest route, with all the stations e.g [1 -> 5 -> 7].
 * @param previous_array In this array there is the last city visited before arriving at the current city.
 * @param end The given end location.
 */
void route_extractor(int previous_array[array_size], int end) {
    int route[array_size];  //This is to save the used route, before printing.

    //In this loop, we extract the route used to arrive at the end
    //location from the previous_array into the route array.
    for (int i = 0; i < array_size; i++) {
        if (i == 0)
            route[i] = end;
        else
            route[i] = previous_array[route[i - 1]];
    }

    //Here we print the route array, and because not all there spots in the array necessarily
    //get used, there is some if statements to ensure, that is do not print a lot of zeros.
    printf("\n\nThe fastest route is [ ");
    for (int i=array_size-1;i > -1;i--){
        if(route[i] != route[i-1]) {
            printf("%d ",route[i]+1);
            if(i > 0){
                printf("-> ");
            }
        }
    }
    printf("]\n\n");
}


/**
 * This function is for finding the fastest route, in a given railway network.
 * @param array Is the adjacency matrix of the network
 * @param start The given start location
 * @param end The given end location
 * @return The fastest route in total minutes
 */
int route_cal(int array[array_size][array_size], int start, int end){

    int result_time_array[array_size];  //This array will contain the fastest time from start to alle other locations.
    int previous_array[array_size];     //In this array there is the last city visited before arriving at the current city i.


    //This for loop is filling the array with high numbers,
    //so that we are sure its bigger then the results that go here later
    for (int i = 0; i < array_size; ++i)
        result_time_array[i] = 100000;


    //We know that it takes 0 time to get the start station from the start station.
    result_time_array[start] = 0;
    previous_array[start] = start;

    //In this algorithm we go froth the whole 2d array, finding all that fastest routes from the start to all
    //the other station, and saving the results in the result_array.
    for (int r = 0; r < array_size; r++) {
        for (int i = 0; i < array_size; ++i) {
            for (int j = 0; j < array_size; ++j) {
                int I = (i + start) % array_size; //This variable is to make the code better to read.

                //This if statement is to ensure that the result_array only is changed when the current route is faster.
                if (array[I][j] > 0 && array[I][j] + result_time_array[I] < result_time_array[j]) {

                    result_time_array[j] = result_time_array[I] + array[I][j];

                    previous_array[j] = I;  //If you go from start to j, then the j's element of
                                            // this array says were you would have come from in the final edge
                }
            }
        }
    }

    //The functions for printing the used fastest route.
    route_extractor(previous_array, end);

    //result time is calculated in hours and minutes and printed.
        int hours = result_time_array[end] / 60, mins = result_time_array[end] % 60;
        printf("Time to reach end station by train: %dh %dm\n", hours, mins);

    //returns the fastest route to given location.
    return result_time_array[end];
}

/**
 * Thhis function Calculates average travel tim in network, from a given origin
 * @param array is the adjacency matrix of the network
 * @param start is the origin station
 * @return sum of travel times for all possible journeys originating from start
 */
int sum_time_from_origin(int array[array_size][array_size], int start){
    int result_time_array[array_size];  //This array will contain the fastest time from start to alle other locations.
    //In this array there is the last city visited before arriving at the current city i.
    int sum;

    //This for loop is filling the array with high numbers,
    //so that we are sure its bigger then the results that go here later
    for (int i = 0; i < array_size; ++i)
        result_time_array[i] = 100000;

    //We know that it takes 0 time to get the start station from the start station.
    result_time_array[start] = 0;

    //In this algorithm we go froth the whole 2d array, finding all that fastest routes from the start to all
    //the other station, and saving the results in the result_array.
    for (int r = 0; r < array_size; r++) {
        for (int i = 0; i < array_size; ++i) {
            for (int j = 0; j < array_size; ++j) {
                int I = (i + start) % array_size; //This variable is to make the code better to read.

                //This if statement is to ensure that the result_array only is changed when the current route is faster.
                if (array[I][j] > 0 && array[I][j] + result_time_array[I] < result_time_array[j]) {

                    result_time_array[j] = result_time_array[I] + array[I][j];
                    sum=sum+result_time_array[j];
                }
            }
        }
    }
    return sum;
}


/**
 * This function is for changing the different times in the time array
 * @param array
 */
void change_route_time(int array[array_size][array_size]){

    int start, end, change;

    print_line();

    printf("\n\nFrom which station do the edge you want to change start?\n");
    //Prints all available starting points.
    for (int i = 0; i < array_size; ++i) {
        printf("%d  ", i + 1);
    }

    //Scans for user input on starting station.
    printf("\n\nChoose on of the stations above > ");
    scanf("%d", &start);
    start-=1;
    print_line();

    // Termination of program if start is invalid
    int station_array[array_size];
    for(int i=0; i<array_size; i++){
        station_array[i] = i;
    }
    int presence_start = 0;

    for(int i = 0; i < array_size; i++)
    {
        if(station_array[i] == start)
        {
            presence_start++;
        }
    }

    if(presence_start ==0 )
    {
        printf("Invalid input. The program will terminate");
        exit(EXIT_FAILURE);
    }


    printf("\n\nPick the end station for the route you want to change\n");
    //Prints all available end station, from the given starting station.
    for (int i = 0; i < array_size; ++i) {
        if(array[start][i] != 0)
            printf("%d  ", i + 1);
    }

    //Scans for user input on end station.
    printf("\n\nChoose on of the stations above > ");
    scanf("%d", &end);
    end -= 1;
    print_line();

    //
    int presence_end = 0;

    for(int i = 0; i < array_size; i++)
    {
        if(array[start][i] != 0)
        {
            presence_end++;
        }
    }

    if(presence_end ==0 )
    {
        printf("Invalid input. The program will terminate");
        exit(EXIT_FAILURE);
    }

    //Prints the current time of the chosen route, and take in a new time for this route.
    printf("\n\nWhat do you want to change the travel duration on this route to in minutes?\n");
    printf("The current time of the route is: %d min\n", array[start][end]);
    printf("\nInput the new travel duration > ");
    scanf("%d", &change);

    //Ensures that the ned duration is non-negative
    if(change<0){
        printf("Invalid input. The program will terminate");
        exit(EXIT_FAILURE);
    }


    //Changes the chosen route, to the given time, do so for both way,e.g  1 -> 5 and 5 -> 1.
    array[start][end] = change;
    array[end][start] = change;

}

//Help function just for printing a dividing line.
void print_line(){
    printf("\n____________________________________________________________________\n");
}
