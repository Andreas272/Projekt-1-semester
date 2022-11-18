#include <stdio.h>
#include <stdlib.h>
#include "Scan_data.h"




double data_reader (int time_array[x][x],int size_of_array) {
    FILE *in_file;

    // Here the fil is opened.
    in_file = fopen("data.txt", "r"); // read only

    // test for files not existing.
    if (in_file == NULL) {
        printf("Error! Could not open file\n");
        exit(EXIT_FAILURE); // must include stdlib.h
    } else {
        printf("it worked\n");


        int start, end, time;

        for (int i = 0; i < size_of_array; ++i) {
            for (int j = 0; j < size_of_array; ++j) {
                time_array[i][j] = 0;
            }
        }

        while(fscanf(in_file, "%d,%d,%d",&start,&end, &time) != EOF){
            //fscanf(in_file, "%d,%d,%d",&start,&end, &time);
            printf("Read Integer %d|%d|%d\n", start, end, time);
            time_array[start-1][end-1] = time;
        }

        fclose(in_file); //Here we close the file back down again.

    }
}

int size_of_array(){
    int size_of_array;
    printf("Please enter the amount of cities, you want to see: \n");
    scanf("%d", &size_of_array);
    printf("%d\n", size_of_array);
    return size_of_array;
}

void print_array(int time_array[x][x],int size_of_array){
    for (int i = 0; i < size_of_array; ++i) {
        printf("\n");
        for (int j = 0; j < size_of_array; ++j) {
            printf("%d ", time_array[i][j]);
        }
    }
}