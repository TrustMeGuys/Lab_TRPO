#include "geometry.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
