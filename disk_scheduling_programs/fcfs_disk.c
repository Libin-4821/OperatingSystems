#include <stdio.h>
#include <stdlib.h>  // For abs() function

int main() {
    int t[20], n, i, tohm[20], tot = 0;
    float avhm;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the tracks to be traversed: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    for (i = 0; i < n - 1; i++) {
        tohm[i] = abs(t[i + 1] - t[i]);
        tot += tohm[i];
    }

    avhm = (float)tot / (n - 1);

    printf("\nTracks traversed\tDifference between tracks\n");
    for (i = 0; i < n - 1; i++) {
        printf("%d\t\t\t%d\n", t[i], tohm[i]);
    }
    printf("%d\n", t[n - 1]); // Print the last track

    printf("\nTotal head movements: %d\n", tot);
    printf("Average head movement: %.2f\n", avhm);

    return 0;
}
