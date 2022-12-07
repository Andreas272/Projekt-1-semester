//
// Created by Gustav on 18-11-2022.
//

#ifndef P1___TRAIN_VS_PLANES_SCAN_DATA_H
#define P1___TRAIN_VS_PLANES_SCAN_DATA_H

//Makes the variable usable in other files that have included Scan_data.h//
extern int array_size;
int compere_int(int a, int b);
int file_array_size();
void data_reader (int time_array[array_size][array_size],int size_of_array);
int size_of_array();
void print_array(int time_array[array_size][array_size],int size_of_array);
void plane_reader (int time_array[array_size][array_size],int size_of_array);


#endif //P1___TRAIN_VS_PLANES_SCAN_DATA_H
