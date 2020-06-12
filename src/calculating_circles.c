#include "calculating_circles.h"
#include <stdio.h>
#include <stdlib.h>

int calculating_circles(int z, float* circles_radius, float* all_circles)
{
    float pi = 3.1415;
    int g = 0, t = 1;
    for (int i = 0; i < z; i++) {
        float perimetr = circles_radius[i] * pi * 2,
              area = circles_radius[i] * circles_radius[i] * pi;
        g = i;
        printf("Окружность №%d (%-7.3f,%-7.3f)\n",
               t,
               all_circles[g],
               all_circles[g + 1]);
        printf("P = %-10.4f\n", perimetr);
        printf("S = %-10.4f\n", area);
        g = g + 2;
        t++;
    }
    return 0;
}
