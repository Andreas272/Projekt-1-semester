cmake_minimum_required(VERSION 3.23)
project(P1___train_vs_planes C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(P1___train_vs_planes
        main.c Scan_data.c Scan_data.h route_cal.c route_cal.h user_inputs.c user_inputs.h plane_time_comparison.c)

link_libraries(main.c Scan_data.c Scan_data.h route_cal.c route_cal.h user_inputs.c user_inputs.h plane_time_comparison.c)
