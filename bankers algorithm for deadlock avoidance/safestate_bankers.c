#include <stdio.h>
#include <stdlib.h>

void matrix_get(int[5][5], int, int);

int main() {
    int max[5][5], all[5][5];
    int total[5];
    int avail[5], f[5], need[5][5], state[5];
    int s, i, j, p, r, c, ch, ch1, k = 0;

    printf("\t\t DEADLOCK - BANKER'S ALGORITHM \n");
    printf("ENTER THE NUMBER OF PROCESS:");
    scanf("%d", &p);
    ch = p;
    printf("ENTER THE NUMBER OF RESOURCE TYPE:");
    scanf("%d", &r);
    printf("ENTER THE MAX MATRIX:\n");
    matrix_get(max, p, r);
    printf("\nENTER THE ALLOCATED MATRIX:\n");
    matrix_get(all, p, r);
    printf("ENTER THE TOTAL RESOURCES PRESENT:\n");

    for (i = 0; i < r; i++) {
        printf("Resource %d: ", i + 1);
        scanf("%d", &total[i]);
    }

    for (i = 0; i < r; i++) {
        s = total[i];
        for (j = 0; j < p; j++) {
            if (max[j][i] > total[i] || all[j][i] > total[i]) {
                printf("\nINPUT IS > TOTAL RESOURCE PRESENT\n");
                exit(0);
            }
            s = s - all[j][i];
        }
        avail[i] = s;
    }

    printf("\n\n AVAILABLE MATRIX \n\n");
    for (i = 0; i < r; i++) {
        printf("%d\t", avail[i]);
    }

    printf("\n\n NEED MATRIX:\n\n");
    for (i = 0; i < p; i++) {
        f[i] = 0;
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - all[i][j];
            if (need[i][j] < 0) {
                need[i][j] = 0;
            }
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }

    while (ch > 0) {
        ch1 = ch;
        for (i = 0; i < p; i++) {
            if (f[i] == 0) {
                c = 0;
                for (j = 0; j < r; j++) {
                    if (need[i][j] <= avail[j]) {
                        c++;
                    }
                }
                if (c == r) {
                    f[i] = 1;
                    state[k++] = i;
                    ch--;
                    for (j = 0; j < r; j++) {
                        avail[j] = avail[j] + all[i][j];
                        need[i][j] = 0;
                    }
                }
            }
        }
        if (ch == p) {
            printf("\n ALREADY DEADLOCK OCCURRED");
            exit(0);
        }
        if (ch1 == ch) {
            printf("\n ALLOCATION LEADS TO DEADLOCK");
            exit(0);
        }
    }

    printf("\n\n SAFE STATE S:{ ");
    for (i = 0; i < k; i++) {
        printf("P%d ", state[i]);
    }
    printf("}\n");

    return 0;
}

void matrix_get(int a[5][5], int p, int r) {
    int i, j;
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}
