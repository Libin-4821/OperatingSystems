#include<stdio.h>
#include<stdlib.h>

void matrix_get(int a[5][5], int p, int r) {
    int i, j;
    for(i = 0; i < p; i++) {
        for(j = 0; j < r; j++) {
            printf("Enter value for process %d and resource %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void detect_deadlock(int Allocation[][5], int Request[][5], int Available[5], int n, int m) {
    int Work[5], Finish[5], i, j, k, deadlock = 0;

    for(i = 0; i < m; i++)
        Work[i] = Available[i];

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(Allocation[i][j] != 0) {
                Finish[i] = 0;
                break;
            }
            Finish[i] = 1;
        }
    }

    while(1) {
        int flag = 1;
        for(i = 0; i < n; i++) {
            if(Finish[i] == 0) {
                for(j = 0; j < m; j++) {
                    if(Request[i][j] > Work[j])
                        break;
                }
                if(j == m) {
                    for(k = 0; k < m; k++)
                        Work[k] += Allocation[i][k];
                    Finish[i] = 1;
                    flag = 0;
                }
            }
        }
        if(flag) {
            break;
        }
    }

    for(i = 0; i < n; i++) {
        if(Finish[i] == 0) {
            printf("Process P%d is deadlocked.\n", i);
            deadlock = 1;
        }
    }

    if(!deadlock)
        printf("No deadlock detected.\n");
}


int main() {
    int Allocation[5][5], Request[5][5], Available[5];
    int n, m, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the Allocation matrix:\n");
    matrix_get(Allocation, n, m);

    printf("Enter the Request matrix:\n");
    matrix_get(Request, n, m);

    printf("Enter the Available vector:\n");
    for(i = 0; i < m; i++) {
        printf("Enter available resource %d: ", i);
        scanf("%d", &Available[i]);
    }

    detect_deadlock(Allocation, Request, Available, n, m);

    return 0;
}
