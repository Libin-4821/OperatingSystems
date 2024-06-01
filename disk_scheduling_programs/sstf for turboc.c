#include <stdio.h>
#include <stdlib.h>  // For abs() function

#define INT_MAX 32767  // Define INT_MAX for Turbo C

int main() {
    int t[20], n, i, current, min, min_index, tot = 0;
    float avhm;
    int visited[20] = {0};  // Track visited status
    
    clrscr();  // Clear the screen

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the initial head position: ");
    scanf("%d", &current);

    t[0] = current;

    printf("Enter the tracks to be traversed: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }

    for (i = 0; i < n; i++) {
        min = INT_MAX;

        // Find the nearest unvisited track
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && abs(current - t[j]) < min) {
                min = abs(current - t[j]);
                min_index = j;
            }
        }

        visited[min_index] = 1;  // Mark the track as visited
        tot += min;              // Add the seek time
        current = t[min_index];  // Move the head to the new position
    }

    avhm = (float)tot / n;

    printf("\nTotal head movements: %d\n", tot);
    printf("Average seek time: %.2f\n", avhm);

    getch();  // Wait for user input before closing
    return 0;
}
