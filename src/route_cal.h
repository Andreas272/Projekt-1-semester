//
// Created by Gustav on 18-11-2022.
//

#ifndef P1___TRAIN_VS_PLANES_ROUTE_CAL_H
#define P1___TRAIN_VS_PLANES_ROUTE_CAL_H

extern int array_size;
int route_cal(int array[array_size][array_size], int start, int end);
double plane_cal(int departure, int arrival);
void travel_comparison(double plane, int train);
void change_route_time(int array[array_size][array_size]);
void print_line();


#endif //P1___TRAIN_VS_PLANES_ROUTE_CAL_H
