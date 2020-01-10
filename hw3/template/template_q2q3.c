#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define RES_SIZE 128
#define NAME_SIZE 64

/*******************************Struct declarations****************************************/
//It's generally good to put all your structures at the beginning of a single file.

typedef /*YOUR STRUCTURE*/ Student; 

typedef /*YOUR STRUCTURE*/ Node; 

typedef /*YOUR STRUCTURE*/ LinkedList; 







/*******************************Part1: comparison and sorting******************************/
int compare (const char* str1, const char* str2)
{
    //YOUR CODE HERE    
}

void string_sort (char* strings[], int size)
{
    //YOUR CODE HERE
}

/*********************************New student function*************************************/
Student* new_student(const char* _name, float _score)
{
    //YOUR CODE HERE
}

/*******************************Part2: LinkedList & functions******************************/
void list_init(LinkedList* l)
{
    //YOUR CODE HERE
}


void list_insert(LinkedList* l, Student* stu_ptr)
{
    //YOUR CODE HERE
}

void list_erase(LinkedList* l)
{
    //YOUR CODE HERE
}

Node* list_remove(LinkedList* l, Node* target)
{
    //YOUR CODE HERE
}


/*******************************Part3: Searching*******************************************/
Node* list_search_by_name(LinkedList* l, char* search_name)
{
    //YOUR CODE HERE
}

int list_search_by_score(LinkedList* l, 
                         float lower_bound,
                         float upper_bound,
                         char* result[RES_SIZE])
{
    //YOUR CODE HERE
}


/*******************************Your Main Function*****************************************/
//DO NOT submit main function to OJ, or compile error may happen!
int main()
{

}
