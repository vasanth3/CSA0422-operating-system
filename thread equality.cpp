#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Thread is running\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    if (pthread_equal(thread1, thread2))
        printf("Threads are equal\n");
    else
        printf("Threads are not equal\n");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}

