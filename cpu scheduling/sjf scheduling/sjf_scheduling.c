#include <stdio.h>
#include <stdlib.h> // For system("cls") instead of clrscr()

#define MAX 50

struct process {
    int pro;
    int brt;
    int tt;
    int wt;
} pr[MAX];

int main() {
    int i, j, n, t, totwt = 0, tottt = 0;
    float avgwt, avgtt;
    int prevtt = 0;

    system("cls"); // Clear the screen
    printf("\n\t\t\t SHORTEST JOB FIRST");
    printf("\n\n Enter the number of processes: ");
    scanf("%d", &n);

    // Getting Process number and Burst Time
    for(i = 1; i <= n; i++) {
        pr[i].pro = i;
        printf("\nProcess number: %d ", pr[i].pro);
        printf("\nEnter burst time: ");
        scanf("%d", &pr[i].brt);
    }

    // Sorting the Burst Time in Ascending order
    for(i = 1; i <= n; i++) {
        for(j = i + 1; j <= n; j++) {
            if(pr[i].brt > pr[j].brt) {
                t = pr[j].pro;
                pr[j].pro = pr[i].pro;
                pr[i].pro = t;

                t = pr[j].brt;
                pr[j].brt = pr[i].brt;
                pr[i].brt = t;
            }
        }
    }

    // Calculating Waiting time and Turn Around Time
    for(i = 1; i <= n; i++) {
        pr[i].wt = prevtt;
        pr[i].tt = pr[i].wt + pr[i].brt;
        prevtt = pr[i].tt;
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
    printf("\n Average Turnaround Time: %6.2f\n", avgtt);

    // Gantt Chart
    printf("\n");
    for(i = 1; i <= pr[n].tt; i++) {
        printf("-");
    }
    printf("\n");

    for(i = 1; i <= n; i++) {
        printf("%*d", pr[i].brt, pr[i].tt);
    }
    printf("\n");

    for(i = 1; i <= pr[n].tt; i++) {
        printf("-");
    }
    printf("\n");

    return 0;
}
