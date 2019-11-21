#include <stdio.h>

// Naive method to find a pair in an array with given sum
void findPair(int arr[], int n, int sum)
{
	// consider each element except last element
	for (int i = 0; i < n - 1; i++)
	{
		// start from i'th element till last element
		for (int j = i + 1; j < n; j++)
		{
			// if desired sum is found, print it and return
			if (arr[i] + arr[j] == sum)
			{
				printf("Pair found at index %d and %d", i, j);
				return;
			}
		}
	}
 
	// No pair with given sum exists in the array
	printf("Pair not found");
}
 
// Find pair with given sum in the array
int main()
{
	int arr[] = { 120, 15, 180, 135, 60, 120, 135, 90, 60, 240, 90, 180, 40, 75, 30, 45, 60, 20, 60, 30, 135, 15, 120, 90, 60, 30, 135, 90};
	int sum = 200;
    int ss=0,i;
    for(i=0;i<28;i++)
    {
        ss += arr[i]; 
    }
    printf("%d\n", ss);
 
	int n = sizeof(arr)/sizeof(arr[0]);
 
	findPair(arr, n, sum);
 
	return 0;
}