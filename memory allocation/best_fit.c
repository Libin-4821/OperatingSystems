#include<stdio.h>
//#include<conio.h>

#define max 25

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp, lowest = 10000;
    static int bf[max], ff[max];
    
    //clrscr();
    
    printf("\n\tMemory Management Scheme - Best Fit");
    
    // Input the number of blocks
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    
    // Input the number of files
    printf("Enter the number of files: ");
    scanf("%d", &nf);
    
    // Input the size of each block
    printf("\nEnter the size of the blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }
    
    // Input the size of each file
    printf("Enter the size of the files:\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }
    
    // Allocation process using Best Fit
    for (i = 1; i <= nf; i++) {
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1) { // If block is not allocated
                temp = b[j] - f[i];
                if (temp >= 0) {
                    if (lowest > temp) {
                        ff[i] = j;
                        lowest = temp;
                    }
                }
            }
        }
        frag[i] = lowest;
        bf[ff[i]] = 1;
        lowest = 10000;
    }
    
    // Print the allocation result
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for (i = 1; i <= nf && ff[i] != 0; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
    }
    
    //getch();
}
