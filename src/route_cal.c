#include "route_cal.h"
#include <stdio.h>
#include "Scan_data.h"



void route_extractor(int previous_array[], int end, int edge_counter, int start, int route[array_size], int duration_array[])
{
    int x;
for(int i=0; i<array_size;i++){
    if(i==0){
        route[i]=end;
    }
    else {
        x = route[i - 1];
        printf("x is %d\n", x);
        route[i] = previous_array[x];
    }
    printf("route[%d] is %d \n",i,route[i]);
}
    printf("The route_extractor route:[ ");
    for (int i=array_size-1;-1<i;i--)
    {
        printf(" %d ",route[i]+1);
    }
    printf("]\n");
}

int route_cal(int array[array_size][array_size], int size_of_array, int start, int end) {

    printf("start is %d\n", start);
    printf("end is %d\n", end);
    printf("array size is %d\n", array_size);


    int result_array[array_size];
    int previous_array[array_size];

    int route_array[array_size];

    //This for loop is filling the array with high numbers,
    //so that we are sure its bigger then the results that go here later
    for (int i = 0; i < array_size; ++i) {
        result_array[i] = 100;
        previous_array[i] = -1;
        route_array[i] = -1; //array for the route from A to B.

    }
    //We know that it takes 0 time to get the start station.
    result_array[start] = 0;

    //printf("\n");
    //printf("\n");

    previous_array[start] = start;

    for (int r = 0; r < array_size; r++) {
        for (int i = 0; i < array_size; ++i) {
            for (int j = 0; j < array_size; ++j) {
                if (array[(i + start) % array_size][j] > 0 &&
                    array[(i + start) % array_size][j] + result_array[(i + start) % array_size] <
                    result_array[j]) {


                    result_array[j] =
                            result_array[(i + start) % array_size] + array[(i + start) % array_size][j];

                    //previous_array[j] =i;
                    previous_array[j] = (i + start) % array_size; //If you go from start to j, then the j's element of this array says were you would have come from in the final
                                                                  //  edge

                    printf("previous_array (i,j)=(%d,%d): \n", i, j);
                    printf("[");
                    for (int i = 0; i < array_size; ++i) {
                        printf(" %d ", previous_array[i]);
                    }
                    printf("]\n");

                    /*
                    printf("\nThe path to %d:\n[",j+1);
                    for (int i = 0; i < array_size; i++){
                        printf(" %d ", result_array[end].path[i]);
                    }
                    printf("]\n");
                     */


                    //printf(" %d ", result_array[j]);
                }
                //else printf(" 0 ");
            }
            //printf("\n");

        }
    }


    route_extractor(previous_array, end, 0, start, route_array, result_array);

    printf("\nTime to end stations: %d\n", result_array[end]);

}
