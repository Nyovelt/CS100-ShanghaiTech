#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef int BOOL;

float decrease_value(int h1, int m1, int h2, int m2)
{
    int duration = h2*60 + m2 - h1*60 - m1;
    if (duration < 60)
    {
        return 0.4*duration;
    }
    else
    {
        return 24 + 0.8*(duration - 60);
    }
}

int main()
{
    /* lectures number and start time */
    int num_lectures, last_time = 480;
    /* mood value of Gezi Wang */
    float mood_val = 100;
    /* indicate if he is dead */
    BOOL is_dead;
    /* get number of lectures */
    scanf("%d", &num_lectures);
    /* calculate mood value for each lecture */ 
    for (int i = 0; i < num_lectures; ++i)
    {
        /* h1: start hour, h2: end hour, m1: start minute, m2: end minute */
        /* idle_time: time with no lectures */
        int h1, h2, m1, m2, idle_time;
        float decrease;
        /* get lecture time */
        scanf("%d:%d-%d:%d", &h1, &m1, &h2, &m2);
        /* calculate idle_time */
        idle_time = (60*h1 + m1) - last_time;
        /* Update mood value */
        if (0.5*idle_time + mood_val > 100)
            mood_val = 100;
        else
            mood_val = 0.5*idle_time + mood_val;
        /* calculate decrease of his mood */
        decrease = decrease_value(h1, m1, h2, m2);
        /**
         * Update mood value
         * if he is dead, set is_dead to true
         */
        if (decrease > mood_val) 
            is_dead = TRUE;
        else
            mood_val -= decrease;
        /* Update last_time to the end time of lecture */
        last_time = 60*h2 + m2;
    }
    /* calculate the end state of mood_val */
    /* 1320: minutes from 0:00 to 22:00 */
    if (mood_val + (1320 - last_time)*0.5 > 100)
        mood_val = 100;
    else
        mood_val += (1320 - last_time)*0.5;
    /* print the result */
    if (is_dead)
        printf("Dead\n");
    else
        printf("mood: %.1f\n", mood_val);
    return 0;
}
