#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "list.h"


struct list *create_list( int init_cap )
{
    struct list *l = (struct list *)malloc( sizeof(struct list) );
	
	if( init_cap <= 0 ) init_cap = 10;
	l->ele = (T *)malloc( init_cap * sizeof(T) );

	l->capacity = init_cap;
    l->counter = 0; 
    return l;	
}
struct list* insert(struct list* l, int i, T e) {
    int j;
    if (l->counter == l->capacity) 
    {
        int new_cap = l->capacity * 2;
        T* new_ele = (T*)malloc(sizeof(T) * new_cap);
        for (j = 0; j < l->counter; j++) 
        {
            new_ele[j] = l->ele[j];
        }
        l->capacity = new_cap;
        free(l->ele);
        l->ele = new_ele;
    }
    assert(i >= 0 && i <= l->counter);
    for (j = l->counter; j > i; j--) 
    {
        l->ele[j] = l->ele[j - 1];
    }
    l->counter++;
    l->ele[i] = e;
    return l;
}
struct list* delete_at(struct list* l, int i)
{
    int j;
    assert(i >= 0 && i < l->counter);
    for (j = i; j < l->counter - 1; j++) 
    {
        l->ele[j] = l->ele[j + 1];
    }
    l->counter--;
    return l;
}
