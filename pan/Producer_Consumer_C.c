#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5 // Size of the shared buffer
#define NUM_PRODUCERS 5 // Number of producer threads
#define NUM_CONSUMERS 5 // Number of consumer threads

int buffer[BUFFER_SIZE]; // Shared buffer
sem_t empty, full; // Semaphores for empty and full slots in the buffer
pthread_mutex_t mutex; // Mutex for buffer access

int in = 0; // Index for adding data to the buffer
int out = 0; // Index for removing data from the buffer

void *producer(void *arg) 
{
    int item;
    for (int i = 0; i < 10; i++) 
	{ // Produce 10 items
        item = rand() % 100; // Generate a random item
        sem_wait(&empty); // Wait for an empty slot in the buffer
        pthread_mutex_lock(&mutex); // Lock the buffer
        buffer[in] = item; // Add item to the buffer
        printf("Producer %d produced item %d\n", *((int *)arg), item);
        in = (in + 1) % BUFFER_SIZE; // Update the index
        pthread_mutex_unlock(&mutex); // Unlock the buffer
        sem_post(&full); // Signal that a slot is full
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) 
{
    int item;
    for (int i = 0; i < 10; i++) 
	{ // Consume 10 items
        sem_wait(&full); // Wait for a full slot in the buffer
        pthread_mutex_lock(&mutex); // Lock the buffer
        item = buffer[out]; // Remove item from the buffer
        printf("Consumer %d consumed item %d\n", *((int *)arg), item);
        out = (out + 1) % BUFFER_SIZE; // Update the index
        pthread_mutex_unlock(&mutex); // Unlock the buffer
        sem_post(&empty); // Signal that a slot is empty
    }
    pthread_exit(NULL);
}

int main() 
{
    pthread_t producer_threads[NUM_PRODUCERS], consumer_threads[NUM_CONSUMERS];

    sem_init(&empty, 0, BUFFER_SIZE); // Initialize the empty semaphore
    sem_init(&full, 0, 0); // Initialize the full semaphore
    pthread_mutex_init(&mutex, NULL); // Initialize the mutex

    int producer_ids[NUM_PRODUCERS];
    int consumer_ids[NUM_CONSUMERS];

    for (int i = 0; i < NUM_PRODUCERS; i++) 
	{
        producer_ids[i] = i;
        pthread_create(&producer_threads[i], NULL, producer, &producer_ids[i]);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++) 
	{
        consumer_ids[i] = i;
        pthread_create(&consumer_threads[i], NULL, consumer, &consumer_ids[i]);
    }

    for (int i = 0; i < NUM_PRODUCERS; i++) 
	{
        pthread_join(producer_threads[i], NULL);
    }//The pthread_join function suspends execution of the calling thread until the target thread terminates.

    for (int i = 0; i < NUM_CONSUMERS; i++) 
	{
        pthread_join(consumer_threads[i], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}

/* 
gedit producer_consumer.c
gcc producer_consumer.c -o produccer_consumer -lpthread
./producer_consumer
*/
