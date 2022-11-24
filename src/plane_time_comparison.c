#include <stdio.h>
#include "route_cal.h"


double plane_cal (int departure, int arrival){
    char start_airport, end_airport;
    printf("choose 2 airports, (start airport) (end_airport)");
    printf("Here is the list of airports:\n(f)Frankfurt, (s)Stuttgart, (m)Munich\n");
    scanf(" %c %c", &start_airport, &end_airport);

    int speed = 500, extra_time = 4;
    double plane_time = 0;

    if(start_airport == 'f' && end_airport == 'm' || start_airport == 'm' && end_airport == 'f'){
        int frank_munc = 301;
        plane_time =  (((1.0/speed)*frank_munc)+extra_time);
    } else if(start_airport == 'f' && end_airport == 's' || start_airport == 's' && end_airport == 'f') {
        int frank_stutt = 157;
        plane_time =  ((1.0/speed)*frank_stutt+extra_time);
    } else if(start_airport == 'm' && end_airport == 's' || start_airport == 's' && end_airport == 'm') {
        int munich_stutt = 193;
        plane_time =  ((1.0/speed)*munich_stutt+extra_time);
    }

    return plane_time;
}

void travel_comparison(double plane, int train) {


    if (plane < train) {
        printf("\n\nThe plane is the fastest mean of travel at %lf h", plane);
    } else {
        printf("\n\nThe train is the fastest mean of travel at %d h", train);
    }

}
