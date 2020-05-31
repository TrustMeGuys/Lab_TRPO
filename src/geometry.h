#ifndef GEOMETRY_H
#define GEOMETRY_H

int calculating_circles(int z, float* circles_radius, float* all_circles);
int intersection_circles(int z, float* all_circles, float* circles_radius);
int input_circles();
void mfree(float* all_circles, float* circles_radius);

#endif
