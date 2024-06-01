#include <stdio.h>

int main() {
    int nb, sb, nj, i, j;
    int js[10];

    // Input number of blocks in memory
    printf("Number of blocks in memory: ");
    scanf("%d", &nb);

    // Input size of each block
    printf("Size of Each block: ");
    scanf("%d", &sb);

    // Input number of jobs
    printf("Number of jobs: ");
    scanf("%d", &nj);

    // Input size of each job
    for (j = 1; j <= nj; j++) {
        printf("Size of job %d: ", j);
        scanf("%d", &js[j]);
    }

    // Paging simulation
    j = 1;
    for (i = 1; i <= nb; i++) {
        if (j > nj) {
            break;
        }

        printf("Job %d stored in memory block %d\n", j, i);
        js[j] -= sb;
        if (js[j] <= 0) {
            j++;
        }
    }

    // Check for out of memory condition
    if (j <= nj) {
        printf("Out of memory\n");
    }

    return 0;
}
