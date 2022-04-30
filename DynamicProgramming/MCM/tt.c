/* A naive recursive implementation that simply
follows the above optimal substructure property */
#include <limits.h>
#include <stdio.h>

// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int i, int j)
{
	// printf("1.) i - %d...j - %d...p - %d\n", i, j, p[0]);
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	// place parenthesis at different places between first
	// and last matrix, recursively calculate count of
	// multiplications for each parenthesis placement and
	// return the minimum count
	for (k = i; k < j; k++)
	{	
		// printf("2.) i - %d... j - %d...p - %d\n", i, j, p[0]);
		count = MatrixChainOrder(p, i, k)
				+ MatrixChainOrder(p, k + 1, j)
				+ p[i - 1] * p[k] * p[j];
printf("%d x %d x %d\n",  p[i - 1] , p[k] , p[j]);
		if (count < min)
			min = count;
			// printf("3.) %d\n", count);
	}
// printf("4.) i - %d... j - %d...p - %d\n", i, j, p[0]);
	// Return minimum count
	return min;
}

// Driver code
int main()
{
int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Minimum number of multiplications is %d ",
		MatrixChainOrder(arr, 1, n - 1));

	getchar();
	return 0;
}
