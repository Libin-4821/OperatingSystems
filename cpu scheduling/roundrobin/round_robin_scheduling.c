#include <stdio.h>
#define MAX 50

struct process {
    int pro;
    int brt;
    int tt;
    int wt;
    int remtime;
} pr[MAX];

void main() {
    int i, n, totwt = 0, tottt = 0;
    float avgwt, avgtt;
    int ts;
    int totbrt;

    printf("\n Enter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter the time slice: ");
    scanf("%d", &ts);

    // Getting Process number and Burst Time
    totbrt = 0;
    for(i = 1; i <= n; i++) {
        printf("\nEnter process no: %d\n", i);
        pr[i].pro = i;
        printf("\nEnter burst time: ");
        scanf("%d", &pr[i].brt);
        pr[i].remtime = pr[i].brt;
        totbrt += pr[i].brt;
    }

    // Calculating Waiting time and Turn Around Time
    tottt = 0;
    while (1) {
        if(tottt == totbrt) {
            break;
        }
        for(i = 1; i <= n; i++) {
            if(pr[i].remtime == 0) {
                continue;
            }
            if(pr[i].remtime > ts) {
                tottt += ts;
                pr[i].remtime -= ts;
            } else {
                tottt += pr[i].remtime;
                pr[i].remtime = 0;
            }
            pr[i].wt = tottt - pr[i].brt;
            pr[i].tt = tottt;
        }
    }

    // Displaying Process details
    printf("\n PROCESS NO \t BURST TIME \t WAITING TIME \t TURN AROUND TIME");
    for(i = 1; i <= n; i++) {
        printf("\n\t%d\t\t%d\t\t%d\t\t%d", pr[i].pro, pr[i].brt, pr[i].wt, pr[i].tt);
        totwt += pr[i].wt;
        tottt += pr[i].tt;
    }

    // Calculating and displaying average Waiting time and Turn Around Time
    avgwt = (float)totwt / n;
    avgtt = (float)tottt / n;
    printf("\n\n Average Waiting time: %6.2f", avgwt);
    printf("\n Average Turnaround Time: %6.2f", avgtt);
    printf("\n");
    }
