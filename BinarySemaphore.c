#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;
int shared = 0;

void* process(void* arg) {
    sem_wait(&mutex);  
    int id = *((int*)arg);

    shared++;
    printf("Shared = %d\n", shared);
    
    printf("Process Entered : %d\n",id);

    sem_post(&mutex);  
    return NULL;
}

int main() {
    pthread_t t1, t2 , t3,t4,t5,t6;
    int id1 = 1 , id2 = 2 , id3=3,id4 = 4,id5 = 5,id6 = 6;

    sem_init(&mutex, 0, 1);

    pthread_create(&t6, NULL, process, &id6);
    pthread_create(&t1, NULL, process, &id1);
    pthread_create(&t2, NULL, process, &id2);
    pthread_create(&t3, NULL, process, &id3);
    pthread_create(&t4, NULL, process, &id4);
    pthread_create(&t5, NULL, process, &id5);

    pthread_join(t6, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    
    sem_destroy(&mutex);
    return 0;
}
