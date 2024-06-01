#include <stdio.h>
#include <stdlib.h>  // For malloc and free functions

// Structure to represent a data block
struct Block {
    int data;          // Data stored in the block (for demonstration purposes)
    struct Block *next;  // Pointer to the next block in the file
};

// Structure to represent a file entry
struct File {
    struct Block *head;  // Pointer to the first block in the file
};

// Function to create a new block
struct Block* createBlock(int data) {
    struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
    if (newBlock == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newBlock->data = data;
    newBlock->next = NULL;
    return newBlock;
}

// Function to add a block to the end of a file
void addBlock(struct File *file, int data) {
    struct Block *newBlock = createBlock(data);
    if (file->head == NULL) {
        file->head = newBlock;
    } else {
        struct Block *current = file->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBlock;
    }
}

// Function to display blocks of a file
void displayFile(struct File *file) {
    struct Block *current = file->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct File files[50];  // Array of file entries
    int num_files, num_blocks, i, j;

    printf("Enter the number of files: ");
    scanf("%d", &num_files);

    printf("Enter the number of blocks per file: ");
    scanf("%d", &num_blocks);

    // Initialize file entries
    for (i = 0; i < num_files; i++) {
        files[i].head = NULL;  // Initialize head pointers to NULL
    }

    // Add blocks to files
    for (i = 0; i < num_files; i++) {
        printf("Enter data blocks for file %d:\n", i + 1);
        for (j = 0; j < num_blocks; j++) {
            int data;
            printf("Block %d: ", j + 1);
            scanf("%d", &data);
            addBlock(&files[i], data);
        }
    }

    // Display files
    printf("\nFiles:\n");
    for (i = 0; i < num_files; i++) {
        printf("File %d: ", i + 1);
        displayFile(&files[i]);
    }

    return 0;
}
