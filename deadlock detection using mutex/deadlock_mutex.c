#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void* thread1(void* arg) {
    printf("Thread 1 started\n");

    // Locking both mutexes in the same order as thread 2 to avoid deadlock
    pthread_mutex_lock(&mutex1);
    printf("Thread 1 acquired mutex1\n");
    sleep(1);
    pthread_mutex_lock(&mutex2);
    printf("Thread 1 acquired mutex2\n");

    pthread_mutex_unlock(&mutex2);
    printf("Thread 1 released mutex2\n");
    pthread_mutex_unlock(&mutex1);
    printf("Thread 1 released mutex1\n");

    pthread_exit(NULL);
}

void* thread2(void* arg) {
    printf("Thread 2 started\n");

    // Locking both mutexes in the same order as thread 1 to avoid deadlock
    pthread_mutex_lock(&mutex1);
    printf("Thread 2 acquired mutex1\n");
    sleep(1);
    pthread_mutex_lock(&mutex2);
    printf("Thread 2 acquired mutex2\n");

    pthread_mutex_unlock(&mutex2);
    printf("Thread 2 released mutex2\n");
    pthread_mutex_unlock(&mutex1);
    printf("Thread 2 released mutex1\n");

    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
