#include <stdio.h>
#include <string.h>

struct process {
    char pid[10];
    int at, bt, rt;
    int ct, wt, tat;
};

int main() {
    int n;
    scanf("%d", &n);

    struct process p[20];

    for(int i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].pid, &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    int tq = 2;   // Time Quantum
    int time = 0, remain = n;
    float avg_wt = 0, avg_tat = 0;

    while(remain != 0) {

        int done = 1;

        for(int i = 0; i < n; i++) {

            if(p[i].rt > 0 && p[i].at <= time) {

                done = 0;

                if(p[i].rt > tq) {
                    time += tq;
                    p[i].rt -= tq;
                }
                else {
                    time += p[i].rt;
                    p[i].ct = time;
                    p[i].rt = 0;

                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;

                    avg_wt += p[i].wt;
                    avg_tat += p[i].tat;

                    remain--;
                }
            }
        }

        if(done)
            time++;
    }

    printf("\nWaiting Time:\n");
    for(int i = 0; i < n; i++)
        printf("%s %d\n", p[i].pid, p[i].wt);

    printf("\nTurnaround Time:\n");
    for(int i = 0; i < n; i++)
        printf("%s %d\n", p[i].pid, p[i].tat);

    printf("\nAverage Waiting Time: %.2f\n", avg_wt/n);
    printf("Average Turnaround Time: %.2f\n", avg_tat/n);

    return 0;
}
