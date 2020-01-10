#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 5
#define true 1
#define false 0

typedef int bool;

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

bool cmp(struct vector* scores, struct ivector* student_ids, int i, int j)
{
    if (scores->data[i] < scores->data[j])
        return true;
    else if (scores->data[i] > scores->data[j])
        return false;
    else
        return student_ids->data[i] < student_ids->data[j];
}

void swap(struct vector* scores, struct ivector* student_ids, int i, int j)
{
    float tmp_score;
    int tmp_id;
    tmp_score = scores->data[i];
    scores->data[i] = scores->data[j];
    scores->data[j] = tmp_score;
    tmp_id = student_ids->data[i];
    student_ids->data[i] = student_ids->data[j];
    student_ids->data[j] = tmp_id;
}

void bubble_sort(struct vector* scores, struct ivector* student_ids)
{
    for (int i = 0; i < scores->size; i++)
    {
        for (int j = 0; j < student_ids->size; j++)
        {
            if (cmp(scores, student_ids, i, j))
            {
                swap(scores, student_ids, i, j);
            }
        }
    }
}

int main()
{
    struct vector nums;
    struct ivector student_ids;
    vector_init(&nums);
    ivector_init(&student_ids); 
    float tmp; 
    int tmp_id;
    printf("Please type scores to be calculated:\n");
    while (scanf("%d %f", &tmp_id, &tmp) == 2)
    {       
        ivector_push(&student_ids, tmp_id);
        vector_push(&nums, tmp);
    } 
    bubble_sort(&nums, &student_ids);
    printf("---Results---\n");
    for (int i = 0; i < nums.size; i++)
    {
        printf("%d %.1f\n", student_ids.data[i], nums.data[i]);
    }
    free(nums.data);
    free(student_ids.data);
    return 0;
}



