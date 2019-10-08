#include<stdio.h>
#include<time.h>	
#include <unistd.h>
void knapsack(int numberOfAds, int totalTimeAvailable, int Amount[], int Duration[]);

//Zone
struct zone
{
    int numberOfAds;
    int totalTimeAvailable;
    int advertNumber[29];
    int numberOfSpotsRequested[29];
    int numberOfSpotsUsed[29];
    int durationPerSpot[29];
    int advertChargesPerSpot[29];
    int totalDuration[29];
    int amount[29];
    
}A1;

//Zone A1
void zoneA1()
{
    A1.numberOfAds = 28;
    A1.totalTimeAvailable = 1200;
    int i;
    /******************* Putting values in the corresponding arrays *****************/

    //advertnumber/(S.No.)
    for(i=1;i<=28;i++)
    {
        A1.advertNumber[i] = i;
    }      

    //numberOfSpotsRequested
    //A1.numberOfSpotsRequested= {4,1,3,3,3,4,3,2,3,4,2,3,2,5,2,3,1,1,2,2,3,1,4,2,4,2,3,6};
    FILE* ptr1 = fopen("numberOfSpotsRequested.txt","r");
    for(i=1;i<=28;i++)
    {
        fscanf(ptr1,"%d",&A1.numberOfSpotsRequested[i]); 
    }
    fclose(ptr1);

    //durationPerSpot
    FILE* ptr2 = fopen("durationPerSpot.txt","r");
    for(i=1;i<=28;i++)
    {
        fscanf(ptr2,"%d",&A1.durationPerSpot[i]); 
    }
    fclose(ptr2);
    
    //advertChargesPerSpot
    for(i=1;i<=28;i++)
    {
        switch (A1.durationPerSpot[i])
        {
        case 15:
            A1.advertChargesPerSpot[i] = 4905;
            break;
        case 20:
            A1.advertChargesPerSpot[i] = 6375;
            break;
        case 30:
            A1.advertChargesPerSpot[i] = 9485;
            break;
        case 45:
            A1.advertChargesPerSpot[i] = 14150;
            break;
        case 60:
            A1.advertChargesPerSpot[i] = 19645;
            break;
        }
    }

    //totalDuration
    A1.totalDuration[0]=0;              //for implementing 01 Knapsack
    for(i=1;i<=28;i++)
    {
        A1.totalDuration[i] = A1.durationPerSpot[i]*A1.numberOfSpotsRequested[i];
    }

    //amount                            
    A1.amount[0]=0;                     //for implementing 01 Knapsack
    for(i=1;i<=28;i++)
    {
        A1.amount[i] = A1.durationPerSpot[i]*A1.advertChargesPerSpot[i];
    }

    //Printing the zone A1 table
    // printf("\nAdverts No.\tNo. of Spot Requested\tDuration per Spot\tAdverts Charges per Spot\tTotal Duration\tAmount\n");
    // for(i=1;i<=28;i++)
    // {
    //     printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t%d\n",A1.advertNumber[i],A1.numberOfSpotsRequested[i],A1.durationPerSpot[i],A1.advertChargesPerSpot[i],A1.totalDuration[i],A1.amount[i]);
    // }
    knapsack(A1.numberOfAds, A1.totalTimeAvailable, A1.amount, A1.totalDuration);
}

//max function
int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}

void knapsack(int numberOfAds, int totalTimeAvailable, int Amount[], int Duration[])
{
    int i,j;
    // declaring 2D matrix for 01 Knapsack computation
    int Knapsack[numberOfAds+1][totalTimeAvailable+1];
    for(i=0;i<=numberOfAds;i++)
    {
        for(j=0;j<=totalTimeAvailable;j++)
        {
            if(i==0 || j==0)
            {
                Knapsack[i][j]=0;
            }
            else if(Duration[i]<=j)
            {
                Knapsack[i][j]=max(Amount[i] + Knapsack[i-1][j-Duration[i]], Knapsack[i-1][j]);
            }
            else
            {
                Knapsack[i][j] = Knapsack[i-1][j];
            }            
        }
    }
    //printing Knapsack Computational Matrix
    // for(i=0;i<=numberOfAds;i++)
    // {
    //     for(j=0;j<=totalTimeAvailable;j++)
    //     {
    //         printf("\t%d",Knapsack[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("\n%d",Knapsack[numberOfAds][totalTimeAvailable]);
    i = numberOfAds;
    j = totalTimeAvailable;
    while (i>0 && j>=0)
    {
        if(Knapsack[i][j] == Knapsack[i-1][j])
        {
            printf("\nAd %d will not be displayed",i);
            i--;
        }
        else
        {
            printf("\nAd %d will be displayed", i);
            j = j-Duration[i];
            //TotalAmount += Amount[i]; 
            i--;
        }
        
    }
    
}

void main()
{
    zoneA1();
}
