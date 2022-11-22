#include <stdio.h>
#include <stdlib.h>
#include "Scan_data.h"

/**
 * This function is for the implementation of the data in the 2d array, from a given text file
 * @param time_array; This is given empty 2d array, made in main
 * @param size_of_array; This is used for calculation in the function, and is the size of the array,
 * based on the amount of stations included
 */
void data_reader (int time_array[array_size][array_size],int size_of_array) {
    //Here we make a file pointer
    FILE *in_file;

    // Here the file is opened.
    in_file = fopen("data.txt", "r"); // Opens the file data.txt in read only mode.

    // tests if the file do not exist, and Exits the program if it do not.
    if (in_file == NULL) {
        printf("Error! Could not open file\n");
        exit(EXIT_FAILURE); // must include stdlib.h
    } else {
        printf("The file was found, yeeeey!!!\n");

        //This for loop, fills the array with 0's, such that we know later, with routes is unusable.
        for (int i = 0; i < size_of_array; ++i) {
            for (int j = 0; j < size_of_array; ++j) {
                time_array[i][j] = 0;
            }
        }
        //These variables is for the imputing the data into the array
        int start, end, time;

        //scans through the whole file, and fills in the raouts, and the time is takes
        //based on the starting point, and ending point.
        while(fscanf(in_file, "%d,%d,%d",&start,&end, &time) != EOF){
            //fscanf(in_file, "%d,%d,%d",&start,&end, &time);
            //printf("Read Integer %d|%d|%d\n", start, end, time);
            time_array[start-1][end-1] = time;//Have to -1, because the array starts at 0 and not 1.
        }
        fclose(in_file); //Here we close the file back down again.
    }
}


/**
 * This if for asking the user, how many different stations they want to include.
 * @return Return the amount of stations, in the form of an integer.
 */
int size_of_array(){
    int size_of_array;
    printf("Please enter the amount of cities, you want to see: \n");
    scanf("%d", &size_of_array);
    printf("You entered this value: %d\n", size_of_array);
    return size_of_array;
}


/**
 * This funktion is for printing 2d arrays
 * @param time_array; This is the imput 2d array, that you want to print in the terminal
 * @param size_of_array; This is the overall size of the array, e.g. 2x2 or 3x3,
 * this is based on the amount of stations you want to include.
 */
void print_array(int time_array[array_size][array_size],int size_of_array){
    for (int i = 0; i < size_of_array; ++i) {
        printf("\n");
        for (int j = 0; j < size_of_array; ++j) {
            printf("%d  ", time_array[i][j]);
        }
    }
}

int file_array_size(){
    int start, end, discard, file_array_size = 0;
    FILE *in_file;
    in_file = fopen("data.txt", "r"); // Opens the file data.txt in read only mode.
    if (in_file == NULL) {
        printf("Error! Could not open file\n"); exit(EXIT_FAILURE);
    }
    else {
        while(fscanf(in_file, "%d,%d,%d",&start,&end, &discard) != EOF){
            int i = 0, j = 0;
            i = compere_int(start,end);
            j = compere_int(i,file_array_size);
            file_array_size = j;
        }
    }
    return file_array_size;
    fclose(in_file); //Here we close the file back down again.
}

int compere_int(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}
