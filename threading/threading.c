#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 3

int je, jo, evensum = 0, sumn = 0, oddsum = 0, evenarr[50], oddarr[50];

void *Even(void *threadarg) {
    int i, n;
    int *threadid = (int *)threadarg; // Correctly cast to int pointer
    n = *threadid; // Dereference to get the value

    je = 0;
    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            evenarr[je] = i;
            evensum = evensum + i;
            je++;
        }
    }
    pthread_exit(NULL);
}

void *Odd(void *threadarg) {
    int i, n;
    int *threadid = (int *)threadarg; // Correctly cast to int pointer
    n = *threadid; // Dereference to get the value

    jo = 0;
    for (i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            oddarr[jo] = i;
            oddsum = oddsum + i;
            jo++;
        }
    }
    pthread_exit(NULL);
}

void *SumN(void *threadarg) {
    int i, n;
    int *threadid = (int *)threadarg; // Correctly cast to int pointer
    n = *threadid; // Dereference to get the value

    for (i = 1; i <= n; i++) {
        sumn = sumn + i;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, t;
    int *arg;

    printf("Enter a number: ");
    scanf("%d", &t);

    arg = malloc(sizeof(*arg)); // Allocate memory for the argument
    *arg = t;

    pthread_create(&threads[0], NULL, Even, arg);
    pthread_create(&threads[1], NULL, Odd, arg);
    pthread_create(&threads[2], NULL, SumN, arg);

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("The sum of first %d natural numbers is %d\n", t, sumn);
    printf("The sum of first %d even natural numbers is %d\n", t, evensum);
    printf("The sum of first %d odd natural numbers is %d\n", t, oddsum);

    printf("The first %d even natural numbers are: \n", t);
    for (i = 0; i < je; i++) {
        printf("%d\n", evenarr[i]);
    }

    printf("The first %d odd natural numbers are: \n", t);
    for (i = 0; i < jo; i++) {
        printf("%d\n", oddarr[i]);
    }

    free(arg); // Free the allocated memory
    pthread_exit(NULL);
    return 0;
}
