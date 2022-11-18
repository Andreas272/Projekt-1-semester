cmake_minimum_required(VERSION 3.23)
project(P1___train_vs_planes C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(P1___train_vs_planes
        travel_cal.c Scan_data.c Scan_data.h route_cal.c route_cal.h)

link_libraries(travel_cal.c Scan_data.c Scan_data.h route_cal.c route_cal.h)
