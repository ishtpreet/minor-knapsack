/* A simple program to print subarray with sum as given sum */
#include<stdio.h> 
  
/* Returns true if the there is a subarray of arr[] with a sum equal to 'sum' 
   otherwise returns false.  Also, prints the result */
int subArraySum(int arr[], int n, int sum, int* start, int* end) 
{ 
    int curr_sum, i, j; 
  
    // Pick a starting point 
    for (i = 0; i < n; i++) 
    { 
        curr_sum = arr[i]; 
  
        // try all subarrays starting with 'i' 
        for (j = i+1; j <= n; j++) 
        { 
            if (curr_sum == sum) 
            { 
                printf ("Sum found between indexes %d and %d\n", i, j-1); 
                *start = i;
                *end = j-1;
                return 1; 
            } 
            if (curr_sum > sum || j == n) 
                break; 
           curr_sum = curr_sum + arr[j]; 
        } 
    } 
  
    printf("No subarray found"); 
    return 0; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = {120,15,180,135,60,120,130,90,60,240,90,180,40,75,30,45,60,20,60,30,135,15,120,90,60,30,135,90}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int sum = 1200;
    int start, end; // staring and ending index of the Array
    subArraySum(arr, n, sum, &start, &end); 
    int i;
    for(i=start; i<=end; i++)
    {
        printf("\n%d",arr[i]);
    }
    printf("\n");
    return 0; 
} 