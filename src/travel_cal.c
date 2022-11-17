#include <stdio.h>
#include <stdlib.h>




double data_reader ();

int main(void) {

    data_reader();
}
double data_reader () {
    FILE *in_file;

    // Here the fil is opened.
    in_file = fopen("data.txt", "r"); // read only

    // test for files not existing.
    if (in_file == NULL) {
        printf("Error! Could not open file\n");
        exit(EXIT_FAILURE); // must include stdlib.h
    } else {
        printf("it worked\n");


        int size_of_arry;
        printf("Please enter the amount of cities, you want to see: \n");
        scanf("%d", &size_of_arry);
        printf("%d\n", size_of_arry);

        int start, end, time;
        int time_array[size_of_arry][size_of_arry];

        for (int i = 0; i < size_of_arry; ++i) {
            for (int j = 0; j < size_of_arry; ++j) {
                time_array[i][j] = 0;
            }
        }

/*
            for (int i = 0; i < size_of_arry; ++i) {
                for (int j = 0; j < size_of_arry; ++j) {
                    fscanf(in_file, "%d,%d,%d",&start,&end, &time_array[start][end]);
                }
            }
            for (int i = 0; i < size_of_arry; ++i) {
            fscanf(in_file, "%d,%d,%d", &start, &end, &time);
            time_array[start][end] = time;
            printf("Read Integer %d|%d|%d\n", start, end, time);
        }
    */


            while(fscanf(in_file, "%d,%d,%d",&start,&end, &time) != EOF){
                fscanf(in_file, "%d,%d,%d",&start,&end, &time);
                printf("Read Integer %d|%d|%d\n", start, end, time);
                time_array[start][end] = time;
            }






        for (int i = 0; i < size_of_arry; ++i) {
            printf("\n");
            for (int j = 0; j < size_of_arry; ++j) {
                printf("%d ", time_array[i][j]);
            }
        }


    }
}