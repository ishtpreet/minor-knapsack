#include<stdio.h>

int flag = 0;
int iteration = 0;

struct sub
{
    int size;
    int subset[];
}S1;


void isSubsetSum(int arr[], int subset[], int N, int subsetSize,
                             int subsetSum, int index ,int sum) 
{
    if(iteration == 0)
    {
    if (subsetSum == sum) 
    {
        flag = 1;
        S1.size = subsetSize;
        
        for (int i = 0; i < subsetSize; i++)
        {
            S1.subset[i] = subset[i];
            printf("%d ", S1.subset[i]);
        }
        printf("\n");
        iteration++;
        // if(subsetSize == 1)
        // {

        // }
    }
    else 
    {
        for (int i = index; i < N; i++) 
        { 
            subset[subsetSize] = arr[i];
            isSubsetSum(arr, subset, N, subsetSize + 1, 
                        subsetSum + arr[i], i + 1, sum);
        }
    }
    }
}

int main()
{ 
    //printf("Enter size of array");
    int N=28;
    //scanf("%d", &N);
    //printf("Enter elements of array");
    int arr[28] = {120,15,180,135,60,120,130,90,60,240,90,180,40,75,30,45,60,20,60,30,135,15,120,90,60,30,135,90};
    //for (int i = 0; i < N; i++)
    //    scanf("%d", &arr[i]);
    //printf("Enter sum");
    int sum=1200;
    //scanf("%d", &sum);
    int subset[N];
    isSubsetSum(arr, subset, N, 0, 0, 0, sum);
    if (flag == 0) {
        printf("No such subset present");
    }
    return 0;    
}