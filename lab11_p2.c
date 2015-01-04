/*	Author: Parker Mathewson					*
 *	Date: 4/25/12							*
 *	Comments: This program is to sort an array without changing	*
 *			the original array contents			*/

#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10

void sort(int* pointer_array[], int size)
{
	int *min, counter_pointer=0, *temp=0, swapped=1;
	while (swapped)
	{
		swapped = 0;
		for(counter_pointer=0;counter_pointer<size-1; counter_pointer++)
		{
			if(*pointer_array[counter_pointer]>*pointer_array[counter_pointer+1])
			{
				min = pointer_array[counter_pointer];
				pointer_array[counter_pointer] = pointer_array[counter_pointer+1];
				pointer_array[counter_pointer+1] = min;
				swapped = 1;
			}			
		}
	}

}

int main(void)
{
	int *pointer_array[ARRAY_SIZE];
	int original_array[]={9, 4, 7, 1, 3, 6, 12, 46, 2, -5};
	int counter=0;

	for(counter=0; counter<ARRAY_SIZE; counter++)
		pointer_array[counter] = &original_array[counter];

	sort(pointer_array, ARRAY_SIZE);

	for(counter=0; counter<ARRAY_SIZE; counter++)
		printf("%d ", original_array[counter]);

	printf("\nPointer sorted array\n");

	for(counter=0; counter<ARRAY_SIZE; counter++)
		printf("%d ", *pointer_array[counter]);

	
	return 0;
}
