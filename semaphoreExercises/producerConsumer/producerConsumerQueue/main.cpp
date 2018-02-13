// *********************************************************************
// **
// ** Copyright (C) 2017-2018 Antonio David López Machado
// **
// ** This program is free software: you can redistribute it and/or modify
// ** it under the terms of the GNU General Public License as published by
// ** the Free Software Foundation, either version 3 of the License, or
// ** (at your option) any later version.
// **
// ** This program is distributed in the hope that it will be useful,
// ** but WITHOUT ANY WARRANTY; without even the implied warranty of
// ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// ** GNU General Public License for more details.
// **
// ** You should have received a copy of the GNU General Public License
// ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
// **
// *********************************************************************

#include <iostream>
#include <pthread.h>
#include <semaphore.h>

using namespace std;

const int tam_vec=10;
int vector[tam_vec];
int firstEmptyCell=0;
int currentValue=0;
const unsigned long num_items = 50;
sem_t producerSem,consumerSem,mutex;

//************************************************//

void * producer( void *){
  for(unsigned i=0;i<num_items;i++){

    sem_wait(&producerSem);

      sem_wait(&mutex);
        vector[firstEmptyCell]=currentValue++;
        firstEmptyCell++;
      sem_post(&mutex);

    sem_post(&consumerSem);
  }
  return NULL;
}

//************************************************//

void * consumer( void *){
  for(unsigned i=0;i<num_items;i++){

    sem_wait(&consumerSem);

      sem_wait(&mutex);
        --firstEmptyCell;
        cout<< "Consuming - "<<vector[firstEmptyCell]<<endl;
      sem_post(&mutex);

    sem_post(&producerSem);
  }
  return NULL;

}

//************************************************//

int main(){

	pthread_t producerThread, consumerThread ;

	sem_init(&producerSem,0,10);
	sem_init(&consumerSem,0,0);
  sem_init(&mutex,0,1);

	pthread_create(&producerThread,NULL,producer,NULL);
	pthread_create(&consumerThread,NULL,consumer,NULL);

	pthread_join(producerThread,NULL);
	pthread_join(consumerThread,NULL);

	sem_destroy(&producerSem);
	sem_destroy(&consumerSem);
  sem_destroy(&mutex);

	return 0;
}
