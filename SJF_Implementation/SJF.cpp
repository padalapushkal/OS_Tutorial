#include <stdio.h>
int main()
{
    int at[30], bt[30], btemp[30];
    int i, lowest, count = 0, time, limit;
    double wait_time = 0, turnaround_time = 0, end, ct[10];
    float avg_wt, avg_tat;
    float wt[30], tat[30];
    printf("Enter the Total Number of Processes:\t");
    scanf("%d", &limit);
    printf("\nEnter Details of %d Processes\n", limit);
    for (i = 0; i < limit; i++)
    {
        printf("\nDetails of process %d \n", i + 1);
        printf("Enter Arrival Time:\t");
        scanf("%d", &at[i]);
        printf("Enter Burst Time:\t");
        scanf("%d", &bt[i]);
        btemp[i] = bt[i];
    }
    bt[29] = 9999;
    for (time = 0; count != limit; time++)
    {
        lowest = 29;
        for (i = 0; i < limit; i++)
        {
            if (at[i] <= time && bt[i] < bt[lowest] && bt[i] > 0)
            {
                lowest = i;
            }
        }
        bt[lowest]--;
        if (bt[lowest] == 0)
        {
            count++;
            end = time + 1;
            ct[lowest] = end;
            wait_time = wait_time + end - at[lowest] - btemp[lowest];

            turnaround_time = turnaround_time + end - at[lowest];
        }
    }
    avg_wt = wait_time / limit;
    avg_tat = turnaround_time / limit;
    printf("p\tat\tbt\tct      \twt      \ttat\n");
    for (i = 0; i < limit; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - btemp[i];
        printf("%d\t%d\t%d\t%f\t%f\t%f\n", i + 1, at[i], btemp[i], ct[i], wt[i], tat[i]);
    }

    printf("\navg wt Time:\t %lf \n", avg_wt);
    printf("avg Turnaround Time:\t %lf \n", avg_tat);
    return 0;
}