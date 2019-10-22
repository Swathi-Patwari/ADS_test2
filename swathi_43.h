#ifndef _INCLUDED_HEAP_
#define _INCLUDED_HEAP_

#include <stdint.h>
#define HEAP_MAX_SIZE 64

//typedef struct event Event;
typedef struct _heap_ Heap;
/*
struct event
{
	Event *eve;
};
*/
struct  _heap_
{
	int32_t time[HEAP_MAX_SIZE];
	int32_t plane_no[HEAP_MAX_SIZE];
	uint32_t	size;
	char event[HEAP_MAX_SIZE]; 
	//int32_t		data[HEAP_MAX_SIZE]	;
};

//Heap        new();
Heap 		add_new(int32_t time[], int32_t plane_no[], uint32_t len, char event[]);
Heap*		heap_sort(Heap *heap);
Heap*		heap_insert(Heap *heap, int32_t key);
Heap*		heap_test(Heap *heap);
int32_t		heap_get_max(Heap *heap);
int32_t		heap_extract_max(Heap *heap);
uint32_t	heap_size(Heap *heap);

#endif