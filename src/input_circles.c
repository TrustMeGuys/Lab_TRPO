#include "input_circles.h"
#include "calculating_circles.h"
#include "intersection_circles.h"
#include <stdio.h>
#include <stdlib.h>

int check(int number)
{
    if (number <= 0) {
        printf("Вы ввели что-то другое.\n");
        return 1;
    } else
        return 0;
}
int input_coordinates(
        int number_circles, float* all_circles, float* circles_radius)
{
    int j = 0, number = 1;
    for (int i = 0; i < number_circles; i++) {
        float x = 0, y = 0, radius = 0;
        printf("Введите координаты окружности № %d:\n", number);
        printf("X=");
        scanf("%f", &x);
        printf("Y=");
        scanf("%f", &y);
        printf("\nВведите радиус окружности:\n");
        scanf("%f", &radius);
        check(radius);
        all_circles[j] = x;
        all_circles[j + 1] = y;
        circles_radius[i] = radius;
        j = j + 2;
        number++;
    }
    return 0;
}
int input_circles()
{
    //Считывание кругов
    int number_circles = 0;
    printf("Введите количество окружностей:\n");
    scanf("%d", &number_circles);
    int n = check(number_circles);
    if (n == 1) {
        exit(1);
    }
    int f = number_circles * 2;
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
    input_coordinates(number_circles, all_circles, circles_radius);

    calculating_circles(number_circles, circles_radius, all_circles);
    if (number_circles > 1) {
        intersection_circles(number_circles, all_circles, circles_radius);
    }
    return 0;
}
