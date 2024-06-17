#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Thread is running\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, NULL);
    printf("Main thread\n");
    pthread_join(thread, NULL);
    printf("Child thread has exited, main thread resumes\n");
    return 0;
}

