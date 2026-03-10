#include <stdio.h>

int main() {

    int n, q;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    char pid[n][10];
    int at[n], bt[n], rt[n];
    int ct[n], wt[n], tat[n];

    for(int i = 0; i < n; i++) {
        printf("Enter PID, Arrival Time and Burst Time: ");
        scanf("%s %d %d", pid[i], &at[i], &bt[i]);
        rt[i] = bt[i];   // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &q);

    int time = 0;
    int completed = 0;

    while(completed < n) {

        int done = 1;

        for(int i = 0; i < n; i++) {

            if(at[i] <= time && rt[i] > 0) {

                done = 0;

                if(rt[i] > q) {
                    time += q;
                    rt[i] -= q;
                }
                else {
                    time += rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    completed++;
                }

            }

        }

        if(done == 1)
            time++;
    }

    float total_wt = 0, total_tat = 0;

    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nWaiting Time:\n");
    for(int i = 0; i < n; i++)
        printf("%s %d\n", pid[i], wt[i]);

    printf("\nTurnaround Time:\n");
    for(int i = 0; i < n; i++)
        printf("%s %d\n", pid[i], tat[i]);

    printf("\nAverage Waiting Time: %.2f\n", total_wt/n);
    printf("Average Turnaround Time: %.2f\n", total_tat/n);

    return 0;
}
