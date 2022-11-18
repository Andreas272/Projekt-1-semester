#include <stdio.h>
#include <stdlib.h>
#include "Scan_data.h"

int main(void) {

    int x = size_of_array();
    int time_array[x][x];
    data_reader (time_array,x);
    print_array(time_array,x);



}


