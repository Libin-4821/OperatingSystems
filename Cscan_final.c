#include <stdio.h>
#include <stdlib.h>  // For abs() function

int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of head: ");
    scanf("%d", &h);

    t[0] = 0;
    t[1] = h;

    printf("Enter total number of tracks: ");
    scanf("%d", &tot);

    t[2] = tot - 1;

    printf("Enter the tracks:\n");
    for (i = 3; i <= n + 2; i++) {
        scanf("%d", &t[i]);
    }

    // Sorting the track positions
    for (i = 0; i <= n + 2; i++) {
        for (j = 0; j <= (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find the position of the head in the sorted array
    for (i = 0; i <= n + 2; i++) {
        if (t[i] == h) {
            j = i;
            break;
        }
    }

    // Moving towards the end and then wrapping around
    p = 0;
    while (j <= n + 2) {
        atr[p] = t[j];
        j++;
        p++;
    }

    for (i = 0; i < j; i++) {
        atr[p] = t[i];
        p++;
    }

    printf("Tracks traversed:\n");
    for (j = 0; j < n + 3; j++) {
        printf("%d ", atr[j]);
    }
    printf("\n");

    printf("Difference between tracks:\n");
    for (j = 0; j < n + 2; j++) {
        d[j] = abs(atr[j + 1] - atr[j]);
        sum += d[j];
        printf("%d %d\n", atr[j], d[j]);
    }
    printf("%d\n", atr[n + 2]);

    printf("Total header movements: %d\n", sum);
    printf("Average seek time: %f\n", (float)sum / n);

    return 0;
}
