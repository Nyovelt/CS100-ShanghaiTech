#include <stdio.h>
#include <assert.h>
#include <float.h>

/**
 * if you use Visual Studio IDE, you may need to define this
 * you should not change this
 */
#ifdef __WIN
#define _CRT_SECURE_NO_WARNINGS 1
#endif 

/**
 * The main function
 * you need to insert your code in this main function
 */
int main(int argc, char *argv[])
{
  /**
   * num_numbers is the number of input numbers
   * cur is the index of current input
   * maximum is the maximum number of input numbers
   * minimum is the minimum number of input numbers
   */ 
  int num_numbers = 0, cur_index = 0;
  float maximum, minimum;
  /* To print the prompt and get the number of input numbers */
  printf("Please type number of input: ");
  scanf("%d", &num_numbers);
  /**
   * To ensure the number of input numbers is correct 
   * You should not change the following line.
   */
  assert(num_numbers > 0);
  /* Insert your code here! */
  /* TODO: get input numbers and cal the maximum and minimum */
  maximum = 0, minimum = FLT_MAX;
  while (cur_index++ < num_numbers)
  {
    float current = 0;
    scanf("%f", &current);
    if (current > maximum) maximum = current;
    if (current < minimum) minimum = current;
  }
  printf("Max value: %.1f\n", maximum);
  printf("Min value: %.1f\n", minimum);
}

