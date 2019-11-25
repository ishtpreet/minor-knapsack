#include<stdio.h>
#include<time.h>	
#include<unistd.h>
int iteration=0;
int zone;
//int x[30];
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
    int selected[29];
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

//Zone A4
void zoneA4()
{
    A4.numberOfAds = 27;
    A4.totalTimeAvailable = 1200;
    int i;
    /******************* Putting values in the corresponding arrays *****************/

    //advertnumber/(S.No.)
    for(i=1;i<=27;i++)
    {
        A4.advertNumber[i] = i;
    }      

    //numberOfSpotsRequested
    //A4.numberOfSpotsRequested= {4,1,3,3,3,4,3,2,3,4,2,3,2,5,2,3,1,1,2,2,3,1,4,2,4,2,3,6};
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
//**************************************************
//**************Perfect Subset Sum Algorithm********
//**************************************************
void isSubsetSum(int arr[], int subset[], int N, int subsetSize,
                             int subsetSum, int index ,int sum) 
{
    if(iteration == 0)
    {
    if (subsetSum == sum) 
    {        
        printf("\nS. No.\t Time");
        for (int i = 1; i <= subsetSize; i++)
        {
            //if(x[i]==1)
            //{
            printf("\n%d",i);
            //}

            printf("\t%d ", subset[i]);
        }
        printf("\n");
        iteration++;
        if(zone==1)
        {
        printf("\nTotal time is %d", A1.totalTimeAvailable);
        }
        else if(zone==4)
        {
        printf("\nTotal time is %d", A4.totalTimeAvailable);
        }
    }
    else 
    {
        for (int i = index; i < N; i++) 
        { 
            //x[i] = 1;
            subset[subsetSize] = arr[i];
            isSubsetSum(arr, subset, N, subsetSize + 1, 
                        subsetSum + arr[i], i + 1, sum);
        }
    }
    }    
}

//**************************************************
//****************0-1 Knapsack Algorithm************
//**************************************************

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
            NumberofSpotsUsed[i]=0;
            i--;

        }
        else
        {
            printf("\nAd %d will be displayed", i);
            if(zone==1)
            {
                NumberofSpotsUsed[i]=A1.numberOfSpotsRequested[i];
            }
            else if(zone==4)
            {
                NumberofSpotsUsed[i]=A4.numberOfSpotsRequested[i];
            }
            j = j-Duration[i];
            totalAmount += Amount[i]; 
            i--;
        }
    }
    printf("\n\nAdv No.\tSpot Requested\tSpots Used\tDuration per Spot\tAdverts Charges per Spot\tTotal Duration\tAmount\n");
    if(zone == 1)
    {
    for(i=1;i<=28;i++)
    {
        if(NumberofSpotsUsed[i]!=0)
        printf("%d\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t\t%d\t\t%d\n",A1.advertNumber[i],A1.numberOfSpotsRequested[i],NumberofSpotsUsed[i],
                                                                A1.durationPerSpot[i],A1.advertChargesPerSpot[i],A1.totalDuration[i],A1.amount[i]);
    }
    }
    else if(zone == 4)
    {
    for(i=1;i<=27;i++)
    {
        if(NumberofSpotsUsed[i]!=0)
        printf("%d\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t\t%d\t\t%d\n",A4.advertNumber[i],A4.numberOfSpotsRequested[i],NumberofSpotsUsed[i],
                                                                A4.durationPerSpot[i],A4.advertChargesPerSpot[i],A4.totalDuration[i],A4.amount[i]);
    }
    }
    printf("\nTotal Amount is: %d",totalAmount);
    
}
int main()
{
    printf("\nPlease select the ZONE");
    printf("\n1. Zone A1 (19:00 - 20:30 )");
    printf("\n4. Zone A4 (20:30 - 21:30 )");
    scanf("\n%d",&zone);
    printf("\n*********************************************");
    printf("\n*******Taking Zone as ZONE A%d***************",zone);
    printf("\n*********************************************");

    switch(zone)
    {
        case 1:
            printf("\n\t***************************************************");
            printf("\n\t**********Printing the Data of Zone A1*************");
            printf("\n\t***************************************************");
            
            zoneA1();
            break;

            case 4:
            printf("\n\t***************************************************");
            printf("\n\t**********Printing the Data of Zone A4*************");
            printf("\n\t***************************************************");
            zoneA4();
            break;
        default:
            break;
    }  

    printf("\nOptimise The selected Zone With Respect to :");
    printf("\n\t1 Amount (Using Knapsack)");
    printf("\n\t2 Time (Perfect Sum Problem)");


    int choice;
    scanf("\n\t%d",&choice);
    switch (choice)
    {
    case 1:
        printf("\n*********************************************");
        printf("\n******Optimising With Respect to Amount******");
        printf("\n*********************************************");
        if(zone==1)
        {
            knapsack(A1.numberOfAds, A1.totalTimeAvailable, A1.amount, A1.totalDuration);
        }
        else if(zone ==4)
        {
            knapsack(A4.numberOfAds, A4.totalTimeAvailable, A4.amount, A4.totalDuration);
        }
        break;
    case 2:
        printf("\n*********************************************");
        printf("\n******Optimising With Respect to Time********");
        printf("\n*********************************************\n");    
        if(zone==1)
        {
            int A1subset[A1.numberOfAds];
            isSubsetSum(A1.totalDuration, A1subset, A1.numberOfAds, 0, 0, 0, A1.totalTimeAvailable);
        }
        
        else if(zone==4)
        {    
            int A4subset[A4.numberOfAds];
            isSubsetSum(A4.totalDuration, A4subset, A4.numberOfAds, 0, 0, 0, A4.totalTimeAvailable);
        }
        break;
    default:
        printf("Please Enter correct Choice and run the code again!");
        break;
    }
    printf("\n");

    return 1;
}