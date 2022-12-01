#include <stdio.h>
#include <stdlib.h>
#include <main.h>

// https://www.geeksforgeeks.org/binary-search/
// Not all conditions work though

int array[10] = { 2, 5, 8, 12, 16, 23, 38, 56, 72, 91 };

int binarySearch(int lowIndex, int highIndex, int element)
{

	printf ("binary Search called with %d %d %d\n", lowIndex, highIndex, element);

	if ( highIndex >= lowIndex )
	{
		if ( highIndex == lowIndex && array[lowIndex] != element)
			return -1 ;

		int midPoint = ( lowIndex + highIndex + 1  ) / 2 ;
		if ( element == array[midPoint])
			return midPoint; // Return index of found

		if ( element < array[midPoint])
			return binarySearch(lowIndex, midPoint - 1, element);

		else if ( element > array[midPoint])
			return binarySearch(midPoint , highIndex , element);
	}
	return -1 ;

}

int main(int argc, char** argv)
{
	int searchItem = atoi(argv[1]);

	int searchedIndex = binarySearch(0, 9, searchItem);
	if ( searchedIndex == -1 )
		printf("Item not found in array\n");
	else
		printf("Searched item found at %d location \n", searchedIndex);
	
	return EXIT_SUCCESS;
}
