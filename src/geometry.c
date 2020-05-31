#include "geometry.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int input_circles()
{
    //Считывание кругов
    int number_circles = 0;
    printf("Введите количество окружностей:\n");
    scanf("%d", &number_circles);
    if (number_circles < 0) {
        printf("Вы ввели что-то не то...");
        exit(1);
    }
    int f = number_circles * 2, j = 0, number = 1;
    float *all_circles, *circles_radius;
    all_circles = (float*)malloc(f * sizeof(float));
    if (all_circles == NULL) {
        printf("Error: can't allocate memory\n");
        return 1;
    }
    circles_radius = (float*)malloc(f * sizeof(float));
    if (circles_radius == NULL) {
        printf("Error: can't allocate memory\n");
        return 1;
    }

    for (int i = 0; i < number_circles; i++) {
        float x = 0, y = 0, radius = 0;
        printf("Введите координаты окружности № %d:\n", number);
        printf("X=");
        scanf("%f", &x);
        printf("Y=");
        scanf("%f", &y);
        printf("\nВведите радиус окружности:\n");
        scanf("%f", &radius);
        if (radius <= 0) {
            printf("Вы ввели что-то другое...\n");
            exit(1);
        }
        all_circles[j] = x;
        all_circles[j + 1] = y;
        circles_radius[i] = radius;
        j = j + 2;
        number++;
    }
    calculating_circles(number_circles, circles_radius, all_circles);
    if (number_circles > 1) {
        intersection_circles(number_circles, all_circles, circles_radius);
    }
    return 0;
}
