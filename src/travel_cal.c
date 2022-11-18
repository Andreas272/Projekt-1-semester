#include <stdio.h>
#include <stdlib.h>
#include "Scan_data.h"

int array_size = 0;

int main(void) {

    array_size = size_of_array(); //We start by finding the array size, by asking the user.
    int time_array[array_size][array_size];
    data_reader (time_array,array_size);
    print_array(time_array,array_size);



}


