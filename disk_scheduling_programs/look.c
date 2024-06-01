#include <stdio.h>
#include <stdlib.h>  // For abs() function

int main() {
    int t[20], n, i, j, h, tot = 0, temp, pos;
    int atr[20], p = 0;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of head: ");
    scanf("%d", &h);

    t[0] = h;

    printf("Enter the tracks to be traversed: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }

    // Sort the tracks
    for (i = 0; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (t[i] > t[j]) {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }

    // Find the position of the head in the sorted array
    for (i = 0; i <= n; i++) {
        if (t[i] == h) {
            pos = i;
            break;
        }
    }

    // Traverse towards the end of the list and then reverse direction
    for (i = pos; i <= n; i++) {
        atr[p++] = t[i];
    }
    for (i = pos - 1; i >= 0; i--) {
        atr[p++] = t[i];
    }

    printf("Tracks traversed:\n");
    for (i = 0; i < p; i++) {
        printf("%d ", atr[i]);
    }
    printf("\n");

    printf("Difference between tracks:\n");
    for (i = 0; i < p - 1; i++) {
        tot += abs(atr[i + 1] - atr[i]);
        printf("%d %d\n", atr[i], abs(atr[i + 1] - atr[i]));
    }

    printf("Total header movements: %d\n", tot);
    printf("Average seek time: %f\n", (float)tot / n);

    return 0;
}
