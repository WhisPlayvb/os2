#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX_CUSTOMERS 25
void *customer(void *num);
void *barber(void *);
void randwait(int secs);
sem_t waitingRoom;
sem_t barberChair;
sem_t barberPillow;
sem_t seatBelt;
int allDone = 0;
int main()
{
	pthread_t btid;
	pthread_t tid[MAX_CUSTOMERS];
	long RandSeed;
	int i, numCustomers, numChairs;
	int Number[MAX_CUSTOMERS];
	printf("\n\t----- Sleeping Barber Problem-----\n");
	printf("\nEnter the number of Customers : ");
	scanf("%d",&numCustomers) ;
	printf("\nEnter the number of Chairs : ");
	scanf("%d",&numChairs);
	if (numCustomers > MAX_CUSTOMERS)
	{
		printf("\nThe maximum number of Customers are %d.\n",
		MAX_CUSTOMERS);
		exit(-1);
	}
	for (i=0; i<MAX_CUSTOMERS; i++)
	{
		Number[i] = i;
	}
	sem_init(&waitingRoom, 0, numChairs);
	sem_init(&barberChair, 0, 1);
	sem_init(&barberPillow, 0, 0);
	sem_init(&seatBelt, 0, 0);
	pthread_create(&btid, NULL, barber, NULL);
	for (i=0; i<numCustomers; i++)
	{
		pthread_create(&tid[i], NULL, customer, (void *)&Number[i]);
		sleep(1);
	}
	for (i=0; i<numCustomers; i++)
	{
		pthread_join(tid[i],NULL);
		sleep(1);
	}allDone = 1;
	sem_post(&barberPillow);
	pthread_join(btid,NULL);
}
void *customer(void *number)
{
	int num = *(int *)number;
	printf("\nCustomer %d going to barber shop.\n", num);
	randwait(2);
	printf("\nCustomer %d arrived at barber shop.\n", num);
	sem_wait(&waitingRoom);
	printf("\nCustomer %d entering waiting room.\n", num);
	sem_wait(&barberChair);
	sem_post(&waitingRoom);
	printf("\nCustomer %d waking to the barber.\n", num);
	sem_post(&barberPillow);
	sem_wait(&seatBelt);
	sem_post(&barberChair);
	printf("\nCustomer %d going back from barber shop.\n", num);
}
void *barber(void *junk)
{
	while (!allDone)
	{
		printf("\nThe barber is sleeping\n");
		sem_wait(&barberPillow);
		if (!allDone)
		{
			printf("\nThe barber is cutting hair\n");
			randwait(2);
			printf("\nThe barber has finished cutting hair.\n");
			sem_post(&seatBelt);
		}
		else 
		{
			printf("\nThe barber is calling end of a day.\n");
		}
	}
}

void randwait(int secs) 
{
	int len;
	len = (int) ((1 * secs) + 1);
	sleep(len);
}
