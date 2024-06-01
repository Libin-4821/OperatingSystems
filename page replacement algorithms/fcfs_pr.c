#include<stdio.h> 
//#include<conio.h> 

int nf, ne, hit, miss, ref[50], fr[15];

void getdata() {
    int i;
    printf("\nEnter the number of frames:");
    scanf("%d", &nf);
    printf("\nEnter the number of elements in the reference string:\n");
    scanf("%d", &ne);
    printf("\nEnter the reference string:\n");
    for(i = 0; i < ne; i++) {
        scanf("%d", &ref[i]);
    }
}

int search(int item) {
    int i;
    for(i = 0; i < nf; i++) {
        if(fr[i] == item) {
            return(1);
        }
    }
    return 0;
}

void fifo() {
    int i, j, found = 0, rear = -1;
    miss = hit = 0;
    for(i = 0; i < nf; i++) {
        fr[i] = -1;
    }
    for(i = 0; i < ne; i++) {
        printf("\nThe no to be inserted: %d", ref[i]);
        found = search(ref[i]);
        if(found == 0) {
            miss++;
            if(rear == nf - 1) {
                rear = -1;
            }
            rear++;
            fr[rear] = ref[i];
        } else {
            hit++;
        }
        printf("\n");
        for(j = 0; j < nf; j++) {
            printf("%d ", fr[j]);
        }
    }
    printf("\n\nNo. of page faults = %d\n", miss);
    printf("\nNo. of Hits = %d", hit);
}

int main() {
    printf("\n\t\t\tFIFO PAGE REPLACEMENT");
    getdata();
    printf("\n\t\t\tFIFO PAGE REPLACEMENT");
    fifo();
    //getch();
    return 0;
}
