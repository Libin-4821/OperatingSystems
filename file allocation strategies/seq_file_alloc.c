#include <stdio.h>
#include <stdlib.h>  // for exit function
#include <conio.h>   // for clrscr and getch functions

int main() {
    int f[50], i, st, j, len, c;

    //clrscr();   Clear the screen (specific to Turbo C)
    
    for (i = 0; i < 50; i++) {
        f[i] = 0;  // Initialize all blocks to 0 (unallocated)
    }
    
    while (1) {
        printf("\nEnter the starting block & length of file: ");
        scanf("%d %d", &st, &len);
        
        for (j = st; j < (st + len); j++) {
            if (f[j] == 0) {
                f[j] = 1;  // Allocate the block
                printf("\n%d->%d", j, f[j]);
            } else {
                printf("\nBlock already allocated");
                break;
            }
        }
        
        if (j == (st + len)) {
            printf("\nThe file is allocated to disk");
        }
        
        printf("\nIf you want to enter more files? (y-1/n-0): ");
        scanf("%d", &c);
        
        if (c != 1) {
            break;
        }
    }
    
    //getch();   Wait for user input before closing (specific to Turbo C)
    return 0;
}
