// C program to illustrate the
// sizeof operator
#include <stdio.h>

// Driver code
int main()
{
	// Print the sizeof integer
	printf("Size of (int) = %lu"
		" bytes\n",
		sizeof(int));

	// Print the size of (int*)
	printf("Size of (int*) = %lu"
		" bytes\n",
		sizeof(int*));

	return 0;
}
