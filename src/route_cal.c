#include "route_cal.h"
#include <stdio.h>

//Number of cities
#define C 3

int is_j_in_no_loop_array (double array[C], int j);
double journey_simulator(double network_matrix[C][C], int star, int end);

void m2() {
    int start=1, end=1;

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

double journey_simulator(double network_matrix[C][C], int start, int end){
    double no_loop_array[C]={0,0,0};

    int j = start - 1;
    int i = start - 1;
    int k=0;
    int l=0;

    double duration;

    while (j != end && j < C && l<100){
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





