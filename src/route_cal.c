#include "route_cal.h"
#include <stdio.h>
#include "Scan_data.h"
#include "user_inputs.h"

void route_extractor(int previous_array[], int end, int route[array_size], int start){
    int x;

    for(int i=0; i<array_size;i++){
        if(i==0){
            route[i]=end;
        }
        else {
            x = route[i - 1];
            route[i] = previous_array[x];
        }
    }

    printf("\n\nThe fastest route is [ ");

    for (int i=array_size-1;0 <= i;i--)
    {
        if(route[i] != route[i+1]) {
            printf("%d ",route[i]+1);
            if(i > 0){
                printf("-> ");
            }
        }
    }

    printf("]\n\n");

}

int route_cal(int array[array_size][array_size], int start, int end) {

    //printf("\nStart is %d\n", start+1);
    //printf("End is %d\n", end+1);
    //printf("Number of stations: %d\n", array_size);


    int result_array[array_size];
    int previous_array[array_size];

    int route_array[array_size];

    //This for loop is filling the array with high numbers,
    //so that we are sure its bigger then the results that go here later
    for (int i = 0; i < array_size; ++i) {
        result_array[i] = 100000;
        previous_array[i] = -1;
        route_array[i] = -1; //array for the route from A to B.

    }
    //We know that it takes 0 time to get the start station.
    result_array[start] = 0;

    previous_array[start] = start;

    for (int r = 0; r < array_size; r++) {
        for (int i = 0; i < array_size; ++i) {
            for (int j = 0; j < array_size; ++j) {
                if (array[(i + start) % array_size][j] > 0 &&
                    array[(i + start) % array_size][j] + result_array[(i + start) % array_size] <
                    result_array[j]) {

                    result_array[j] = result_array[(i + start) % array_size] + array[(i + start) % array_size][j];

                    previous_array[j] = (i + start) % array_size; //If you go from start to j, then the j's element of
                    // this array says were you would have come from in the final edge
                }
            }
        }
    }

    route_extractor(previous_array, end, route_array, start);

    int timer = result_array[end] / 60, min = result_array[end] % 60;
    printf("Time to reach end station by train: %dh:%dmin\n", timer, min);

    return result_array[end];

}

/**
 * This function is for changing the different times in the time array
 * @param array
 */
void change_route_time(int array[array_size][array_size]){

    int start, end, change;

    print_line();

    printf("\n\nFrom which station do the edge you want to change start?\n");
    for (int i = 0; i < array_size; ++i) {
        printf("%d  ", i + 1);
    }
    printf("\n\nChose on of the stations above > ");
    scanf("%d", &start); start -= 1;

    print_line();

    printf("\n\nPick the end station for the route you wanner change\n");
    for (int i = 0; i < array_size; ++i) {
        if(array[start][i] != 0)
            printf("%d  ", i + 1);
    }
    printf("\n\nChose on of the stations above > ");
    scanf("%d", &end); end -= 1;

    print_line();

    printf("\n\nWhat do you want to change the travel duration on this route to in minutes?\n");
    printf("The current time of the route is: %d min\n", array[start][end]);
    printf("\nInput the new travel duration > ");
    scanf("%d", &change);

    array[start][end] = change;
    array[end][start] = change;

    print_line();

}

void print_line(){
    printf("\n\n____________________________________________________________________");
}
