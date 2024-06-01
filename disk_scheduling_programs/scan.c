#include <stdio.h>
#include <stdlib.h>  // For abs() function

int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;

    // Input the number of tracks to be traversed
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    // Input the initial head position
    printf("Enter the position of head: ");
    scanf("%d", &h);

    // Initialize track array with the initial head position and boundary tracks
    t[0] = h;
    printf("Enter the tracks: ");
    for (i = 1; i < n + 1; i++) {
        scanf("%d", &t[i]);
    }

    // Sort the track positions using bubble sort
    for (i = 0; i < n + 1; i++) {
        for (j = 0; j < (n + 1) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find the position of the initial head in the sorted array
    for (i = 0; i < n + 1; i++) {
        if (t[i] == h) {
            j = i;
            break;
        }
    }

    // Create the traversal order array
    p = 0;
    while (j >= 0) {
        atr[p++] = t[j--];
    }
    j = i + 1;
    while (j < n + 1) {
        atr[p++] = t[j++];
    }

    // Print the traversal order
    printf("Tracks traversed:\n");
    for (i = 0; i < n + 1; i++) {
        printf("%d ", atr[i]);
    }
    printf("\n");

    // Calculate the differences between successive tracks and sum them up
    printf("Difference between tracks:\n");
    for (i = 0; i < n; i++) {
        d[i] = abs(atr[i + 1] - atr[i]);
        sum += d[i];
        printf("%d %d\n", atr[i], d[i]);
    }

    // Print the total head movements and average seek time
    printf("Total header movements: %d\n", sum);
    printf("Average seek time: %f\n", (float)sum / n);

    return 0;
}
