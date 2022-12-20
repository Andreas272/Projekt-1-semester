#include <stdio.h>
#include <stdlib.h>
#include "Scan_data.h"

/**
 * This function is for the implementation of the data in the 2d array, from a given text file
 * @param time_array; This is given empty 2d array, made in main
 * @param size_of_array; This is used for calculation in the function, and is the size of the array,
 * based on the amount of stations included
 */
FILE *open_file(int choose_file){
    FILE *in_file;   //Here we make a file pointer

    //Opens the specified txt-file in read only mode.
    if(choose_file==0)
        in_file = fopen("my_data.txt", "r");
    if(choose_file==1)
        in_file = fopen("data_11Stations_minutes.txt", "r");
    if(choose_file==2)
        in_file = fopen("data_11Stations_hours.txt", "r");
    if(choose_file==3)
        in_file = fopen("data_6Stations_hours.txt", "r");
    if(choose_file==4)
        in_file = fopen("data_4Stations_hours.txt", "r");

    if (in_file == NULL) {  //Tests if the file exists, and exit if it doesn't
        printf("Error! Could not open file\n");
        exit(EXIT_FAILURE);
    }
    return in_file;
}


/**
 * Reads data from data fil and into a 2D-array
 * @param time_array is the 2D array to represent the data
 * @param size_of_array is the number of stations.
 * @param units units is either 1 for miutes or 2 for hours
 * @param choose_file is either 0,1,2,3 or 4. Depending on the value, a specific data file ins opened.
 */
void data_reader(int time_array[array_size][array_size],int size_of_array, int units,int choose_file) {
    int start, end, time;

    FILE *in_file= open_file(choose_file);

        //This for loop, fills the array with 0's, such that we know later, which routes is unusable.
        for (int i = 0; i < size_of_array; ++i) {
            for (int j = 0; j < size_of_array; ++j) {
                time_array[i][j] = 0;
            }
        }

        //reads the file, and fills in the routes, and the time is takes
        //based on the starting point, and ending point.
        while(fscanf(in_file, "%d,%d,%d",&start,&end, &time) != EOF){
            if(units==1)
            time_array[start-1][end-1] = time;//Have to -1, because the array starts at 0 and not 1.
            else
                time_array[start-1][end-1] = time*60; //If the durations are given in hours
        }
        fclose(in_file); //Here we close the file back down again.

}


/**
 * This function prints 2D arrays.
 * @param time_array is the output 2D array, that is printed in the terminal. e. g. [2,3] = 1, reflects a
 * 1 hour travel time from city number 2 to city number 3.
 * @param size_of_array is the overall size of the train network array, e.g. [2,2] or [5,5].
 * The indices are reflecting the number of stations included.
 */
void print_array(int time_array[array_size][array_size],int size_of_array){
    for (int i = 0; i < size_of_array; ++i) {
        printf("\n");
        for (int j = 0; j < size_of_array; ++j) {
            printf("%d\t", time_array[i][j]);
        }
    }
}


/** File_array_size is used to figure out the number of stations in the train network
 * @return file_size_array which is the number of stations in the text file. This is used in the dimensions of the 2D array
 */
int file_array_size(int choose_file){
    int start, end, discard, file_array_size = 0;

    FILE *in_file= open_file(choose_file);

        //While keep going until end of file (EOF)
        while(fscanf(in_file, "%d,%d,%d",&start,&end, &discard) != EOF){
            int i , j;

            i = max_value(start, end);
            j = max_value(i, file_array_size);
            file_array_size = j;
        }

    fclose(in_file);        //Here we close the file back down again.
    return file_array_size; //Return the size of the array.
}


/**
 * This function is reading data into the 2d array from a given text file while adding the hidden time.
 * @param time_array; This is the empty 2D array that holds the data from the file.
 * @param size_of_array; This is the size of the array based on the amount of stations included.
 */
void plane_reader (int time_array[array_size][array_size],int size_of_array) {

    FILE *in_file;//Here we make a file pointer
    in_file = fopen("my_data.txt", "r"); // Opens the .txt file in read only mode.

    if (in_file == NULL) {  //Tests if the file exists, and exit if it doesn't
        printf("Error! Could not open file\n");
        exit(EXIT_FAILURE); // must include stdlib.h
    }
    else {
        //This for loop, fills the array with 0's, such that we know later, which routes is unusable.
        for (int i = 0; i < size_of_array; ++i) {
            for (int j = 0; j < size_of_array; ++j) {
                time_array[i][j] = 0;
            }
        }

    int start, end, time;  //Local variables used to input the data into the array

    //reads the file, and fills in the routes, and the time is takes based on the starting point, and ending point.
    while(fscanf(in_file, "%d,%d,%d",&start,&end, &time) != EOF){
        time_array[start-1][end-1] = time + 90; //Have to -1, because the array starts at 0 and not 1.
                                                // 90 is hidden time for domestic routes.
        }
    fclose(in_file); //Here we close the file back down again.
    }
}



/**
 * This is a helping function for comparison of two ints.
 * @param a is the one int
 * @param b is the other int
 * @return the larger of a and b. If a=b, b is returned.
 */
int max_value(int a, int b){
    if(a > b)
        return a; //a is larger
    else
        return b; //b is larger
}


