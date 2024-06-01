#include <stdio.h>
#include <stdlib.h>  // For malloc and free functions

#define MAX_BLOCKS 100
#define MAX_FILES 50

// Structure to represent a file entry
struct File {
    int index_table[MAX_BLOCKS];  // Index table to store pointers to data blocks
    int num_blocks;               // Number of data blocks allocated to the file
};

int main() {
    struct File files[MAX_FILES];  // Array of file entries
    int i, j, num_files, num_blocks;

    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    printf("Enter the number of blocks per file: ");
    scanf("%d", &num_blocks);

    // Initialize index tables for all files
    for (i = 0; i < num_files; i++) {
        files[i].num_blocks = num_blocks;
        for (j = 0; j < num_blocks; j++) {
            files[i].index_table[j] = -1;  // Initialize index table entries to -1 (unallocated)
        }
    }

    // Allocate data blocks and update index tables
    for (i = 0; i < num_files; i++) {
        printf("Enter data block pointers for file %d:\n", i + 1);
        for (j = 0; j < num_blocks; j++) {
            printf("Block %d: ", j + 1);
            scanf("%d", &files[i].index_table[j]);
        }
    }

    // Display index tables for all files
    printf("\nIndex tables for files:\n");
    for (i = 0; i < num_files; i++) {
        printf("File %d:\n", i + 1);
        for (j = 0; j < num_blocks; j++) {
            printf("%d ", files[i].index_table[j]);
        }
        printf("\n");
    }

    return 0;
}
