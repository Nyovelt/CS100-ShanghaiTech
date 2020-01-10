#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 5

struct vector 
{
    float* data;
    int  size;
    int  max_size;
};

void vector_init(struct vector* v)
{
    v->data = (float*)malloc(INIT_SIZE * sizeof(float));
    v->size = 0;
    v->max_size = INIT_SIZE;
}

void vector_push(struct vector* v, float value)
{
    v->data[v->size++] = value;
    if (v->size == v->max_size)
    {
        printf("(resize) from %d to %d\n", v->size, 2 * v->size);
        v->max_size *= 2;
        v->data = (float*)realloc(v->data, v->max_size * sizeof(float));
    }
}

void vector_destroy(struct vector* v)
{
    free(v->data);
}

float calculate_avg(struct vector* v)
{
    float sum = 0;
    int curr = 0;
    while (curr < v->size)
    {
        sum += v->data[curr++];
    } 
    return sum / (float)curr;
}


int main()
{
    struct vector nums;
    vector_init(&nums); 
    float tmp;
    printf("Please type scores to be calculated:\n");
    while (1)
    {
        scanf("%f", &tmp);
        if (tmp == -1) break;
        vector_push(&nums, tmp);
    } 
    printf("Average score: %.2f\n", calculate_avg(&nums));
    vector_destroy(&nums);
    return 0;
}




