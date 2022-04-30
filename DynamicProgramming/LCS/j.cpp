/* A Naive recursive implementation of LCS problem */
#include<bits/stdc++.h>

int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
	printf("1.) X - %s Y - %s m - %d n - %d x - %c, y - %c \n", X, Y, m, n, *(X+m-1), *(Y+n-1));
if (m == 0 || n == 0){
	printf("2.)X - %s Y - %s m - %d n - %d\n\n", X, Y, m, n);
	return 0;
}
if (X[m-1] == Y[n-1]){
	int i = 1 + lcs(X, Y, m-1, n-1);
	printf("3.) X - %s Y - %s m - %d n - %d, lcs - %d x - %c, y - %c \n\n\n", X, Y, m, n,i,*(X+m-1), *(Y+n-1));
	return i;}
else	{printf("4.) X - %s Y - %s m - %d n - %d x - %c, y - %c\n\n\n\n", X, Y, m, n, *(X+m-1), *(Y+n-1));
	return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Driver program to test above function */
int main()
{
char X[] = "yiown";
char Y[] = "iny";


int m = strlen(X);
int n = strlen(Y);

printf("Length of LCS is %d", lcs( X, Y, m, n ) );

return 0;
}
