#include<stdio.h>
//#include<conio.h>

#define max 25

void main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    static int bf[max], ff[max];

    //clrscr();

    printf("\n\tMemory Management Scheme - First Fit");

    // Input the number of blocks
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);

    // Input the number of files
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    // Input the size of each block
    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
    }

    // Input the size of each file
    printf("Enter the size of the files:-\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }

    // Allocation process using First Fit
    for (i = 1; i <= nf; i++) {
        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1) { // If block is not allocated
                temp = b[j] - f[i];
                if (temp >= 0) {
                    frag[i] = temp;
                    bf[j] = 1;
                    ff[i] = j;
                    break;
                }
            }
        }
    }

    // Print the allocation result
    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment");
    for (i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);

    //getch();
}
