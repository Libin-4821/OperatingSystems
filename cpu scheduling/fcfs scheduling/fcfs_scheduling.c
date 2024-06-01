#include<stdio.h>
#include<stdlib.h> // For system("cls") instead of clrscr()

#define MAX 10

struct process {
    int pro;
    int brt;
    int tt;
    int wt;
} pr[MAX];

int main() {
    int i, n, totwt = 0, tottt = 0;
    float avgwt, avgtt;
    int prevtt = 0;

    system("cls"); // Clear the screen
    printf("\n\t\t First Come First Serve \n");
    printf("\t\t ~~~~~ ~~~~ ~~~~~ ~~~~~ \n");
    printf("\n\t Enter the no of processes: ");
    scanf("%d", &n);

    // Getting Process no. and Burst Time
    for(i = 1; i <= n; i++) {
        pr[i].pro = i;
        printf("\nProcess no: %d ", pr[i].pro);
        printf("\tEnter burst time: ");
        scanf("%d", &pr[i].brt);
    }

    // Calculating Waiting time and Turn Around Time
    for(i = 1; i <= n; i++) {
        pr[i].wt = prevtt;
        pr[i].tt = pr[i].wt + pr[i].brt;
        prevtt = pr[i].tt;
    }

    printf("\n PROCESS NO \t BURST TIME \t WAITING TIME \t TURN AROUND TIME");
    printf("\n ~~~~~~~~~~ \t ~~~~~~~~~~ \t ~~~~~~~~~~~~ \t ~~~~~~~~~~~~~~~~");

    // Sum of Waiting time and Turn Around Time
    for(i = 1; i <= n; i++) {
        printf("\n\t%d\t\t%d\t\t%d\t\t%d", pr[i].pro, pr[i].brt, pr[i].wt, pr[i].tt);
        totwt += pr[i].wt;
        tottt += pr[i].tt;
    }

    // Average of Waiting time and Turn Around Time
    avgwt = (float)totwt / n;
    avgtt = (float)tottt / n;
    printf("\n\n Average Waiting time: %6.2f", avgwt);
    printf("\n\n Average Turnaround Time: %6.2f", avgtt);
    printf("\n\n");

    // Gantt Chart
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
