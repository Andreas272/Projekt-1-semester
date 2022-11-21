#include <stdio.h>

double plane_cal ();
void travel_comparison(double plane, int train);

int main(void){

    double plane = plane_cal();
    int train = 1;
    travel_comparison(plane, train);

}


double plane_cal (){
    char start_airport, end_airport;
    printf("choose 2 airports, (start airport) (end_airport)");
    printf("Here is the list of airports:\n(f)Frankfurt, (s)Stuttgart, (m)Munich\n");
    scanf("%c %c", &start_airport, &end_airport);

    int speed = 2, extra_time = 2;
    double plane_time = 0;

    if(start_airport == 'f' && end_airport == 'm' || start_airport == 'm' && end_airport == 'f'){
        int frank_munc = 301;
        plane_time =  ((1/speed)*frank_munc+extra_time);
    } else if(start_airport == 'f' && end_airport == 's' || start_airport == 's' && end_airport == 'f') {
        int frank_stutt = 157;
        plane_time =  ((1/speed)*frank_stutt+extra_time);
    } else if(start_airport == 'm' && end_airport == 's' || start_airport == 's' && end_airport == 'm') {
        int munich_stutt = 193;
        plane_time =  ((1/speed)*munich_stutt+extra_time);
    }

    return plane_time;
}

void travel_comparison(double plane, int train) {

    if (plane > train) {
        printf("The plane is the fastest mean of travel at %lf h", plane);
    } else {
        printf("The train is the fastest mean of travel at %d h", train);
    }

}