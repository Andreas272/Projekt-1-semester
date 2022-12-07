#include <stdio.h>
#include "route_cal.h"

/**
 * This function compares travel duration of aviation and railway and prints
 * the fastest method combined with it's duration in hours and minutes
 * @param plane is the duration of the aviation trip in minutes
 * @param train is the duration of the railway trip in minutes
 */
void travel_comparison(int plane, int train) {

    if (plane < train && plane != 0) {
        int timer = (plane/60), min = (plane % 60);
        printf("\n\nThe plane is the fastest means of travel at %dh:%dmin",timer, min);
    } else {
        int timer = train / 60, min = train % 60;
        printf("\n\nThe train is the fastest means of travel at %dh:%dmin", timer, min);
    }

}

/**
 *This function finds the shortest route from departure city to arrival city with aviation transport in a given network
 * @param array is the given aviation network represented as a 2D array. Every element reflects a route duration from
 * array[i] to array[j].
 * @param start is the city of departure.
 * @param end is the city of arrival.
 * @return is the duration of the shortest route in minutes.
 */

int plane_route_cal(int array[array_size][array_size], int start, int end) {

    int result_array[array_size]; //Holds the shortest route from start to end.


    //This for loop is filling the array with high numbers,
    //so that we are sure its bigger then the results that go here later
    for (int i = 0; i < array_size; ++i) {
        result_array[i] = 100000;
    }

    result_array[start] = 0; //We know that it takes 0 time to get the start station.


    for (int r = 0; r < array_size; r++) {
        for (int i = 0; i < array_size; ++i) {
            for (int j = 0; j < array_size; ++j) {
                if (array[(i + start) % array_size][j] > 0 &&
                    array[(i + start) % array_size][j] + result_array[(i + start) % array_size] <
                    result_array[j]) {

                    result_array[j] = result_array[(i + start) % array_size] + array[(i + start) % array_size][j];

                }
            }
        }
    }


    for (int i = 0; i < array_size; ++i) { //replaces the high values with 0's to indicate no route was taken.
        if (result_array[i] >= 1000){
            result_array[i] = 0;
        }
    }

    return result_array[end];

}


/*
int plane_cal(int departure, int arrival) {

    int plane_time = 0;

    // (0)Frankfurt, (1)Stuttgart, (2)Munich
    if (departure == 1 && arrival == 11 ||
        departure == 11 && arrival == 1) {
        int frank_munc = 300;
        plane_time = 115 + (0.2103055473 * frank_munc);
        return plane_time;

    } else if (departure == 1 && arrival == 6 ||
               departure == 6 && arrival == 1) {
        int frank_stutt = 157;
        plane_time = 115 + (0.2103055473 * frank_stutt);
        return plane_time;

    } else if (departure == 11 && arrival == 6 ||
               departure == 6 && arrival == 11) {
        int munich_stutt = 193;
        plane_time = 115 + (0.2103055473 * munich_stutt);
        return plane_time;
    }
    return plane_time;

}
*/
