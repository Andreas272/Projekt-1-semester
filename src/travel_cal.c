#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int start_loc;
    int time;
    int end_loc;
} travel_time_t;

typedef struct {
    travel_time_t travel_time;
    struct node_t* next;
}node_t;


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

        node_t* new_node = (node_t*) malloc(sizeof(node_t));

        //Test if memory is allocated
        if (new_node == NULL) {
            printf("Memory not allocated.\n");
            exit(EXIT_FAILURE);
        }
        else {
            printf("you are great\n");
            int year[4];
            char route[10];
            for (int i = 0; i < 4 ; ++i) {
                fscanf(in_file, "%s %d",route,&year[i]);
                printf("%d Read Integer %s|%d|\n",i,route, year[i]);
            }



        }






    }
}