
#ifndef P1___TRAIN_VS_PLANES_ROUTE_CAL_H
#define P1___TRAIN_VS_PLANES_ROUTE_CAL_H

extern int array_size;
int route_cal(int array[array_size][array_size], int start, int end);
int sum_time_from_origin(int array[array_size][array_size], int start);
int plane_cal(int departure, int arrival);
void travel_comparison(int plane, int train);
void change_route_time(int array[array_size][array_size]);
void print_line();
int plane_route_cal(int array[array_size][array_size], int start, int end);


#endif //P1___TRAIN_VS_PLANES_ROUTE_CAL_H