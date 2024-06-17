#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Thread is running\n");
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, NULL);
    printf("Main thread is waiting for the child thread to finish...\n");
    pthread_join(thread, NULL);
    printf("Child thread has finished, main thread resumes\n");
    return 0;
}

