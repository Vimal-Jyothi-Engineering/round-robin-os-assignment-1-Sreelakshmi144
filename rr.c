#include <stdio.h>

int main()
{
    int n, tq;
    int at[20], bt[20], rt[20];
    int wt[20], tat[20], ct[20];
    int time = 0, remain;
    float avg_wt = 0, avg_tat = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    scanf("%d", &tq);

    remain = n;

    while(remain > 0)
    {
        for(int i = 0; i < n; i++)
        {
            if(rt[i] > 0 && at[i] <= time)
            {
                if(rt[i] > tq)
                {
                    time += tq;
                    rt[i] -= tq;
                }
                else
                {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;

                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];

                    avg_wt += wt[i];
                    avg_tat += tat[i];

                    remain--;
                }
            }
        }
        time++;
    }

    for(int i = 0; i < n; i++)
        printf("%d %d\n", wt[i], tat[i]);

    printf("%.2f\n", avg_wt/n);
    printf("%.2f\n", avg_tat/n);

    return 0;
}
