#include "route_cal.h"
#include <stdio.h>

//Number of cities
#define C 3

int is_j_in_no_loop_array (double array[C], int j);
double journey_simulator(double network_matrix[C][C], int star, int end);

void m2() {
    int start = 1, end = 1;

    double network_matrix[C][C] = {0, 2, 3,
                                   2, 0, 2,
                                   3, 2, 0};

    while(start !=0){
        //user input for chosen city
        printf("Choose your city!");
        scanf("%d",&start);
        printf("choose your destination");
        scanf("%d", &end);

        printf("Duration is %lf\n", journey_simulator(network_matrix,start,end));
    }
}

/**
 * Journey_simulator is an brute force function that simulates all unique routes from city A (start) to city B (end).
 * @param network_matrix is a 2D matrix of the train network chosen by the user. the size [s][s] is equal to number of cities
 * in the network.
 * @param start is the starting node. it is from this node the function runs.
 * @param end is the finishing node. When the function has found its way to end, it stops
 * @return The function returns the durations of all unique routes from start to end.
 */
double journey_simulator(double network_matrix[C][C], int start, int end){
    double no_loop_array[C]={0,0,0};

    int j = start - 1;
    int i = start - 1;
    int k = 0;
    int l = 0;

    double duration;

    while (j != end && j < C) {
        printf("Note while: We have looped\n");
        if (network_matrix[i][j] == 0 || is_j_in_no_loop_array(no_loop_array, j) ){
            printf("Note if: (i,j)=(%d,%d)\n",i,j);
            j++;
            printf("Note if: (i,j)=(%d,%d)\n",i,j);
        }
        else {
            printf("Note else: (i,j)=(%d,%d)\n",i,j);

            duration = duration + network_matrix[i][j];
            no_loop_array[k] = i;

            k++;
            i = j;
            j = 0;
            printf("Note else: (i,j)=(%d,%d)\n",i,j);
        }
        l++;

    }
    return duration;
}

/**
 * The function is_j_in_loop_array is a linear search algorithm, that searches for parameter j in an array
 * @param array is a one-dimensional array passed.
 * @param j is searched for in array by the function
 * @return Either true(1), if j is found in the array or false(0) if element j is not found.
 */
int is_j_in_no_loop_array (double array[C], int j){
    int i = 0;

    while (i < C && j != array[i]){
        i = i + 1;
    }
    if (i < C){
        return 1;
    }
    else
        return 0;
}





