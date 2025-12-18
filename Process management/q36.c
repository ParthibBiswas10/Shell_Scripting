/*36. Solve the classical producer consumer problem using semaphore. Consider the buffer is
bounded. Create at least 3 producers and 3 consumers.*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
#define buffersize 10

sem_t bs;
sem_t full;
sem_t empty;
int buffer[buffersize];

int prod=3;
int cons=3;
int in=0;
int out=0;
void* produce(){
    while(1){
        sem_wait(&bs);
        sem_wait(&empty);
        int n=rand()%100;
        buffer[in]=n;
        in=(in+1)%buffersize;
        printf("Produced: %d\n",n);
        sem_post(&bs);
        sem_post(&full);
        sleep(3);
        
    } 
}

void* consume(){
    while(1){
        sem_wait(&bs);
        sem_wait(&full);
        int x=buffer[out];
        out=(out+1)%buffersize;
        printf("consumed: %d\n",x);
        sem_post(&bs);
        sem_post(&empty);
        sleep(2);
        
    } 
}


int main(){
    
    pthread_t producers[prod];
    pthread_t consumers[cons];
    
    sem_init(&full,0,0);
    sem_init(&empty,0,buffersize);
    sem_init(&bs,0,1);
    
     for(int i=0;i<prod;i++){
         pthread_create(&producers[i],NULL,produce,NULL);
     }
    for(int i=0;i<cons;i++){
         pthread_create(&consumers[i],NULL,consume,NULL);
     }
    
    for(int i=0;i<prod;i++){
         pthread_join(producers[i],NULL);
     }
     for(int i=0;i<cons;i++){
         pthread_join(consumers[i],NULL);
     }
}


