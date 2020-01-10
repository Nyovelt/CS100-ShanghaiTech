#include <stdio.h>
#include <math.h>

/* for the triangle, it must have 3 vertices */
#define MAX_VERTICES 3
#define MAX_OF_2(a,b) (((a) > (b)) ? (a) : (b))
#define MAX_OF_3(a, b, c) (MAX_OF_2(MAX_OF_2((a), (b)), (c)))
#define MIN_OF_2(a,b) (((a) < (b)) ? (a) : (b))
#define MIN_OF_3(a, b, c) (MIN_OF_2(MIN_OF_2((a), (b)), (c)))
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
   * @param radius: the radius of the circle.
   * @param center_x: the x coordinate of the center of the circle.
   * @param center_y: the y coordinate of the center of the circle.
   */
  float dis_max, dis_min, center_x, center_y;
  /**
   * TODO: 
   * (1) get the input
   * (2) calculate the coordinate of the center.
   * (3) calculate the radius of the circle.
   */
  float x_coords[MAX_VERTICES], y_coords[MAX_VERTICES];
  for (; num_vertices < MAX_VERTICES; num_vertices++)
  {
    printf("Input vertex %d: ", num_vertices);
    scanf("%f %f", &x_coords[num_vertices], &y_coords[num_vertices]);
  }
  center_x = (x_coords[1] + x_coords[0] + x_coords[2]) / 3;
  center_y = (y_coords[1] + y_coords[0] + y_coords[2]) / 3;
  float dis1 = sqrt(pow(center_x-x_coords[0], 2) + pow(center_y-y_coords[0], 2));
  float dis2 = sqrt(pow(center_x-x_coords[1], 2) + pow(center_y-y_coords[1], 2));
  float dis3 = sqrt(pow(center_x-x_coords[2], 2) + pow(center_y-y_coords[2], 2));
  dis_max = MAX_OF_3(dis1, dis2, dis3);
  dis_min = MIN_OF_3(dis1, dis2, dis3);
  /* print the center and radius, you should not modify the code below */
  printf("The center of the circle is: %.1f %.1f\n", center_x, center_y);
  printf("The maximum distance between center and vertices: %.2f\n", dis_max);
  printf("The minimum distance between center and vertices: %.2f\n", dis_min);
  return 0;
}