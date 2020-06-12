#include "intersection_circles.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int intersection_circles(
        int number_circles, float* all_circles, float* circles_radius)
{
    int fix = 0, next = 0, fix_radius = 0, next_radius = 1, fix_number = 1,
        next_number = 2, intersection = 0, l = 0;

    for (int i = 0; i < number_circles * 2; i = i + 2) {
        fix = i;
        next = i;
        for (; next < number_circles * 2 - 2; next = next + 2) {
            float x = all_circles[fix] - all_circles[next + 2];
            float y = all_circles[fix + 1] - all_circles[next + 3];
            float distance = sqrt((pow(x, 2) + pow(y, 2)));
            if (distance == 0
                && circles_radius[fix_radius] == circles_radius[next_radius]) {
                printf("Окружность №%d и окружность №%d одинаковы\n",
                       fix_number,
                       next_number);
            } else if (
                    distance
                    < abs(circles_radius[fix_radius]
                          - circles_radius[next_radius])) {
                if (distance == circles_radius[fix_radius]
                    || distance == circles_radius[next_radius]) {
                    if (circles_radius[fix_radius]
                        < circles_radius[next_radius]) {
                        printf("Окружность №%d лежит и соприкасается в одной "
                               "точке в окружности №%d\n",
                               fix_number,
                               next_number);
                        intersection++;
                    } else {
                        printf("Окружность №%d лежит и соприкасается в одной "
                               "точке в окружности №%d\n",
                               next_number,
                               fix_number);
                        intersection++;
                    }
                } else if (
                        circles_radius[fix_radius]
                        < circles_radius[next_radius])
                    printf("Окружность №%d лежит внутри окружности №%d и не "
                           "касается ее\n",
                           fix_number,
                           next_number);
                else
                    printf("Окружность №%d лежит внутри окружности №%d и не "
                           "касается ее\n",
                           next_number,
                           fix_number);

            } else if (
                    distance
                    < (circles_radius[fix_radius]
                       + circles_radius[next_radius])) {
                printf("Окружность № %d пересекается с окружностью №%d\n",
                       fix_number,
                       next_number);
                intersection++;

            } else if (
                    distance
                    == (circles_radius[fix_radius]
                        + circles_radius[next_radius])) {
                printf("Окружность № %d соприкасется с окружностью № %d\n",
                       fix_number,
                       next_number);
                intersection++;
            }
            if (next_number + 1 > number_circles) {
                next_number--;
                next_radius--;
                if (next_radius == next_number - 1)
                    next_number++;
            } else {
                next_number++;
                next_radius++;
            }
        }
        fix_number++;
        fix_radius++;
        l++;
        if (l == number_circles - 1) {
            next_number++;
        }
        if (next_number + 1 > number_circles) {
            next_number--;
        }
    }
    if (intersection == 0)
        printf("Персечений окружностей нет\n");
    mfree(all_circles, circles_radius);
    return 0;
}

void mfree(float* all_circles, float* circles_radius)
{
    free(all_circles);
    free(circles_radius);
}
