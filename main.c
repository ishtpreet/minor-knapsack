#include<stdio.h>
#include<time.h>	
#include <unistd.h>
// Total time slot assigned for Advertisement (in seconds)
int totalTimeSlot = 8;


//to display the advertisement running
void playad(int duration)
{
    clock_t begin, end;
    double time_spent;

    begin = clock();
    time_spent = (double)begin / CLOCKS_PER_SEC;

    for(time_spent=0.0; time_spent < duration; time_spent = time_spent + .5)
    {
        printf("#");
        sleep(1);
    }
    
    end = clock();
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


void main()
{
    int numberOfAds, i, j, profitKnapsack=0, profit=0;
    printf("\nEnter number of Ads to be displayed");
    scanf("%d",&numberOfAds);
    int AdLength[numberOfAds+1];
    AdLength[0] = 0;
    int AdProfit[numberOfAds+1];
    AdProfit[0] = 0;
    for(i=1;i<=numberOfAds;i++)
    {
        printf("\nEnter duration of AD %d : ",i);
        scanf("%d",&AdLength[i]);
        printf("\nEnter Profit of Ad %d : ",i);
        scanf("%d",&AdProfit[i]);
    }
    // Declaring the Knapsack 2D Matrix
    int Knapsack[numberOfAds+1][totalTimeSlot+1];

    for (i=0; i<=numberOfAds;i++)
    {
        for(j=0;j<=totalTimeSlot;j++)
        {
            if(i==0 || j==0)
            {
                Knapsack[i][j]=0;
            }
            else if(AdLength[i]<=j)
            {
                Knapsack[i][j] = max(AdProfit[i] + Knapsack[i-1][j-AdLength[i]], Knapsack[i-1][j]);
            }
            else
            {
                Knapsack[i][j] = Knapsack[i-1][j];
            }
            
        }
    }

    // for (i=0; i<=numberOfAds;i++)
    // {
    //     for(j=0;j<=totalTimeSlot;j++)
    //     {
    //         printf("%d",Knapsack[i][j]);
    //         printf("\n");            
    //     }
    // }    
    printf("%d\n",Knapsack[numberOfAds][totalTimeSlot]);
    i = numberOfAds;
    j = totalTimeSlot;
    while(i>0 && j>=0)
    {
        
            if(Knapsack[i][j] == Knapsack[i-1][j])
        {
            printf("\nAd %d will not be displayed",i);
            i--;
            //printf("/n Time Left: %d ",j);
        }
        else
        {
            printf("\nAd %d will be displayed",i);
            j = j - AdLength[i];
            profitKnapsack += AdProfit[i];
            i--;
            //printf("/n Time Left: %d ",j);  

        }
    }
    printf("\nProfit using Knapsack Technique is %d ",profitKnapsack);

    // *********** Using normal Technique ***********
    printf("\n\n***************************\n");
    i =totalTimeSlot;
        for(j=1;j<=numberOfAds;j++)
        {
            if(i>=AdLength[j])
            {
                printf("\nAd %d will be displayed ",j);
                i -= AdLength[j];
                profit += AdProfit[j];
            }
            else
            {
                printf("\nAd %d will not be displayed ",j);
            }
            
        }
        printf("\nProfit using FCFS Technique is %d \n",profit);
}
