#include <stdio.h>
#include <stdlib.h>
#include "Scan_data.h"
#include "route_cal.h"


int array_size = 0;

int main(void) {

    //We start by finding the array size, by asking the user.
    //array_size = size_of_array();

    array_size = file_array_size();
    printf("%d", array_size);


    //Creates the 2d array
    int time_array[array_size][array_size];
    //Inputs the data form the data.txt file into the 2d array.
    data_reader (time_array,array_size);

    //Prints the array
    print_array(time_array,array_size);

    dik(time_array, 0);


    return 0;
}


