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


    if (in_file == NULL) {  //Tests if the file exists, and exit if it doesn't
        printf("Error! Could not open file\n");
        exit(EXIT_FAILURE); // must include stdlib.h
    } else {
        printf("The file was found, you did good son!!!\n");

        //This for loop, fills the array with 0's, such that we know later, which routes is unusable.
        for (int i = 0; i < size_of_array; ++i) {
            for (int j = 0; j < size_of_array; ++j) {
                time_array[i][j] = 0;
            }
        }
        int start, end, time;  //Local variables used to input the data into the array

        //reads the file, and fills in the routes, and the time is takes
        //based on the starting point, and ending point.
        while(fscanf(in_file, "%d,%d,%d",&start,&end, &time) != EOF){
            time_array[start-1][end-1] = time;//Have to -1, because the array starts at 0 and not 1.
        }
        fclose(in_file); //Here we close the file back down again.
    }
}


/**
 * This if for asking the user, how many different stations they want to include.
 * @return Return the amount of stations, in the form of an integer.
 */
/*int size_of_array(){
    int size_of_array;
    printf("Please enter the amount of cities, you want to see: \n");
    scanf("%d", &size_of_array);
    printf("You entered this value: %d\n", size_of_array);
    return size_of_array;
}
*/

/**
 * This function prints 2D arrays.
 * @param time_array is the output 2D array, that is printed in the terminal. e. g. [2,3] = 1, reflects a
 * 1 hour travel time from city number 2 to city number 3.
 * @param size_of_array is the overall size of the train network array, e.g. [2,2] or [5,5].
 * The indices are reflecting the number of stations included.
 */
void print_array(int time_array[array_size][array_size],int size_of_array){
    //array_size og size_of_array beskriver umiddelbart det samme. Er det også tilfældet?
    for (int i = 0; i < size_of_array; ++i) {
        printf("\n");
        for (int j = 0; j < size_of_array; ++j) {
            printf("%d  ", time_array[i][j]);
        }
    }
}

/** File_array_size is used to figure out the number of stations in the train network
 * @return file_size_array which is the number of stations in the text file. This is used in the dimensions of the 2D array
 */
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
    fclose(in_file); //Here we close the file back down again.
    return file_array_size;
}

int compere_int(int a, int b){
    if(a > b)
        return a; //a is larger
    else
        return b; //b is larger
}
