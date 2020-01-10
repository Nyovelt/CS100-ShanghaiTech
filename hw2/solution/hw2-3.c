#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INIT_SIZE 5

struct ivector 
{
    int* data;
    int  size;
    int  max_size;
};

void ivector_init(struct ivector* v)
{
    v->data = (int*)malloc(INIT_SIZE * sizeof(int));
    v->size = 0;
    v->max_size = INIT_SIZE;
}

void ivector_push(struct ivector* v, int value)
{
    v->data[v->size++] = value;
    if (v->size == v->max_size)
    {
        printf("(resize) from %d to %d\n", v->size, 2 * v->size);
        v->max_size *= 2;
        v->data = (int*)realloc(v->data, v->max_size * sizeof(int));
    }
}

int main()
{
    struct ivector origin, subset;
    int tmp, min_diff = 0x7fffffff;
    ivector_init(&origin);
    ivector_init(&subset);
    printf("Please input the set A:\n");
    while (1)
    {
        scanf("%d", &tmp);
        if (tmp == -1) break;
        ivector_push(&origin, tmp);
    } 
    printf("Please input the set B:\n");
    while (1)
    {
        scanf("%d", &tmp);
        if (tmp == -1) break;
        ivector_push(&subset, tmp);
    } 

    for (int i = 0; i < origin.size - subset.size + 1; i++)
    {
        int diff = 0;
        for (int j = i; j < i + subset.size; j++)
        {
            diff += abs(origin.data[j] - subset.data[j - i]);
        }
        if (diff < min_diff) min_diff = diff;
    }

    printf("---Result---\n");
    for (int i = 0; i < origin.size - subset.size + 1; i++)
    {
        int diff = 0;
        for (int j = i; j < i + subset.size; j++)
            diff += abs(origin.data[j] - subset.data[j - i]);
        if (diff == min_diff)
        {
            for (int k = i; k < i + subset.size; k++)
                printf("%d ", origin.data[k]);
        }
    }
    printf("\n");
    return 0;
}

