#include <stdio.h>
#include <math.h>

/* for the triangle, it must have 3 vertices */
#define MAX_VERTICES 3

/**
 * if you use Visual Studio IDE, you may need to define this
 * you should not modify this
 */
#ifdef __WIN
#define _CRT_SECURE_NO_WARNINGS 1
#endif 

int main(int argc, char *argv[])
{
  /* current index of the input vertex */
  int num_vertices = 0;
  /**
   * dis_max: the maximum distance.
   * dis_min: the minimum distance.
   * center_x: the x coordinate of the center of the circle.
   * center_y: the y coordinate of the center of the circle.
   */
  float dis_max, dis_min, center_x, center_y;
  /**
   * TODO: 
   * (1) get the input
   * (2) calculate the coordinate of the center.
   * (3) calculate the radius of the circle.
   */








  /* print the center and radius, you should not modify the code below */
  printf("The center of the circle is: %.1f %.1f\n", center_x, center_y);
  printf("The maximum distance between center and vertices: %.2f\n", dis_max);
  printf("The minimum distance between center and vertices: %.2f\n", dis_min);
  return 0;
}