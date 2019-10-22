#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "swathi_43.h"
/*
Heap new()
{
	Heap heap={NULL,NULL,0};                    
}

static Event* make_new_event(char n_event)
{
	Event *events=(Event*)malloc(sizeof(Event));
	events->eve=n_event;
	return events;
}
*/
static void _swap_(int32_t *data1, int32_t *data2) {
	int32_t temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

static void _heapify_ (int32_t time[], uint32_t len, uint32_t parent) 
{
	assert (len > 0 && len < HEAP_MAX_SIZE && parent > 0 );

	uint32_t child = 2 * parent;

	while (child <= len) {
		if (child + 1 <= len) {
			if (time[child+1] > time[child]){
				++child;
			}
		}
		if (time[parent] >= time[child]) {
			break;
		}
		_swap_(&time[parent], &time[child]);
		parent = child;
		child = 2 * parent;
	}
}

static void _test_heap_(int32_t time[], uint32_t len) {

	for (uint32_t child = len; child > 1; --child) {
		assert(time[child] <= time[child/2]);
	}

}

Heap*	heap_test(Heap *heap)
{
	_test_heap_(heap->time, heap->size);
}

Heap 	add_new(int32_t time[], int32_t plane_no[], uint32_t len, char event[]) 
{
	assert (len > 0 && len < HEAP_MAX_SIZE);

	Heap heap;
	uint32_t idx = len/2;
	for (idx = len/2; idx > 0; --idx) {
		_heapify_(time, len, idx);
	}
	heap.size = len;
	memcpy(heap.time, time, (len+1) * sizeof(int32_t));
	_test_heap_(heap.time, heap.size);

	return heap;
}

Heap*	heap_sort(Heap *heap) 
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);

	uint32_t idx = heap->size;

	for (idx = heap->size; idx > 1; idx--) 
	{
		_swap_(&heap->time[idx], &heap->time[1]);
		_heapify_(heap->time, idx-1, 1);
	}

	return heap;
}


Heap*	heap_insert(Heap *heap, int32_t key)
{
	assert (heap->size > 0 && heap->size+1 < HEAP_MAX_SIZE);

	++heap->size;
	uint32_t parent = heap->size/2;
	uint32_t loc = heap->size;

	while ( loc > 1 && heap->time[parent] < key) {
		heap->time[loc] = heap->time[parent];
		loc = parent;
		parent = parent/2;
	}
	heap->time[loc] = key;
	return heap;

}

int32_t		heap_get_max(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->time[1];

}

int32_t		heap_extract_max(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);

	int32_t max = heap->time[1];	
	_swap_(&heap->time[1], &heap->time[heap->size]);
	--heap->size;
	_heapify_(heap->time, heap->size, 1);

	return max;
}

uint32_t	heap_size(Heap *heap)
{
	assert (heap->size > 0 && heap->size < HEAP_MAX_SIZE);
	return heap->size;
}