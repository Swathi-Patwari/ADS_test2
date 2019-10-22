#include <stdint.h>
#include <assert.h>
#include "swathi_43.h"
#include<stdio.h>

void test_sort( int32_t time[], uint32_t len) 
{
	uint32_t idx;
	for (idx = 1; idx <= len; ++idx) {
		assert (time[idx] <= time[idx+1]);		
	}
}

void test_heap()
{
	int32_t time[] = { 0, 2300, 1300, 700};
	int32_t plane_no[]={ 12, 23, 25, 56};
	char event[]={'t','l','l','t'};   // t-takeoff, l-landing
	Heap heap = add_new(time, plane_no, 3, event);	
	heap_insert(&heap, 1530);
	heap_test(&heap);
	assert(heap_get_max(&heap) == 2300);
	assert(heap_extract_max(&heap) == 2300);
	heap_test(&heap);
	assert(heap_size(&heap) == 3);

	heap_sort(&heap);
	for(int i=0; i<size;i++)
	{
		printf("sorted elements %d" time[i]);
	}
	
	test_sort(heap.time, 3);

}

int main()
{
	test_heap();
	return 0;
}