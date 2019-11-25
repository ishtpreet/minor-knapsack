#include<stdio.h>
#include<time.h>	
#include<unistd.h>
int iteration=0;
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
    
}A1,A4;

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
    FILE* ptr1 = fopen("A1numberOfSpotsRequested.txt","r");
    for(i=1;i<=28;i++)
    {
        fscanf(ptr1,"%d",&A1.numberOfSpotsRequested[i]); 
    }
    fclose(ptr1);

    //numberofspotsused
    for(i=1;i<=28;i++)
    {
        A1.numberOfSpotsUsed[i]=A1.numberOfSpotsRequested[i];
    }

    //durationPerSpot
    FILE* ptr2 = fopen("A1durationPerSpot.txt","r");
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
    printf("\nAdverts No.\tNo. of Spot Requested\tDuration per Spot\tAdverts Charges per Spot\tTotal Duration\tAmount\n");
    for(i=1;i<=28;i++)
    {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t%d\n",A1.advertNumber[i],A1.numberOfSpotsRequested[i],A1.durationPerSpot[i],A1.advertChargesPerSpot[i],A1.totalDuration[i],A1.amount[i]);
    }
    
    
}


void zoneA4()
{
    A1.numberOfAds = 27;
    A1.totalTimeAvailable = 1200;
    int i;
    /******************* Putting values in the corresponding arrays *****************/

    //advertnumber/(S.No.)
    for(i=1;i<=27;i++)
    {
        A4.advertNumber[i] = i;
    }      

    //numberOfSpotsRequested
    //A1.numberOfSpotsRequested= {4,1,3,3,3,4,3,2,3,4,2,3,2,5,2,3,1,1,2,2,3,1,4,2,4,2,3,6};
    FILE* ptr1 = fopen("A4numberOfSpotsRequested.txt","r");
    for(i=1;i<=27;i++)
    {
        fscanf(ptr1,"%d",&A4.numberOfSpotsRequested[i]); 
    }
    fclose(ptr1);

    //numberofspotsused
    for(i=1;i<=27;i++)
    {
        A4.numberOfSpotsUsed[i]=A4.numberOfSpotsRequested[i];
    }

    //durationPerSpot
    FILE* ptr2 = fopen("A4durationPerSpot.txt","r");
    for(i=1;i<=27;i++)
    {
        fscanf(ptr2,"%d",&A4.durationPerSpot[i]); 
    }
    fclose(ptr2);
    
    //advertChargesPerSpot
    for(i=1;i<=27;i++)
    {
        switch (A4.durationPerSpot[i])
        {
        case 15:
            A4.advertChargesPerSpot[i] = 2580;
            break;
        case 20:
            A4.advertChargesPerSpot[i] = 3500;
            break;
        case 30:
            A4.advertChargesPerSpot[i] = 5025;
            break;
        case 45:
            A4.advertChargesPerSpot[i] = 7420;
            break;
        case 60:
            A4.advertChargesPerSpot[i] = 10305;
            break;
        }
    }

    //totalDuration
    A4.totalDuration[0]=0;              //for implementing 01 Knapsack
    for(i=1;i<=27;i++)
    {
        A4.totalDuration[i] = A4.durationPerSpot[i]*A4.numberOfSpotsRequested[i];
    }

    //amount                            
    A4.amount[0]=0;                     //for implementing 01 Knapsack
    for(i=1;i<=27;i++)
    {
        A4.amount[i] = A4.durationPerSpot[i]*A4.advertChargesPerSpot[i];
    }

    //Printing the zone A1 table
    printf("\nAdverts No.\tNo. of Spot Requested\tDuration per Spot\tAdverts Charges per Spot\tTotal Duration\tAmount\n");
    for(i=1;i<=27;i++)
    {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t%d\n",A4.advertNumber[i],A4.numberOfSpotsRequested[i],A4.durationPerSpot[i],A4.advertChargesPerSpot[i],A4.totalDuration[i],A4.amount[i]);
    }
    
    
}


//max function for computing maximum among two values
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
    int i,j,totalAmount=0;
    int NumberofSpotsUsed[numberOfAds];

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


    i = numberOfAds;
    j = totalTimeAvailable;

}