#include <stdio.h>
#include <stdlib.h>
#include "Scan_data.h"
#include "route_cal.h"


int array_size = 0;

int main(void) {

    int start = 5, end = 11;

    //This function finds the array size.
    array_size = file_array_size();
    printf("%d", array_size);

    //Creates the 2d array
    int time_array[array_size][array_size];

    //Inputs the data form the data.txt file into the 2d array.
    data_reader (time_array,array_size);

    //Prints the array
    print_array(time_array,array_size);

    route_cal(time_array,array_size,start-1,end-1);

    return 0;
}


