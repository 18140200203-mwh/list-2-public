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
