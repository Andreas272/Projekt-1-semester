#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

double data_reader ();

typedef struct{
    int start_loc;
    int time;
    int end_loc;
} travel_time_t;

typedef struct {
    travel_time_t travel_time;
    struct node_t* next;
}node_t;




int main(void) {

    data_reader();
}
double data_reader () {
    FILE *in_file;

    // Here the fil is opened.
    in_file = fopen("C:/Users/Bruger/CLionProjects/P1---train-vs-planes/data.txt", "r"); // read only

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
            printf("you are great");
        }






    }
}