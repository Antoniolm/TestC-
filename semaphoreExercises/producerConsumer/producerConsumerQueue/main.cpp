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
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "threadPackage/thread.h"

using namespace std;

//************************************************//

void * producer( void * args ){
  thread_args *elements = (struct thread_args *)args;
  int currentValue=0;

  for(unsigned i=0;i<elements->num_items;i++){

    sem_wait(elements->producerSem);

      sem_wait(elements->mutex);
        elements->vector[(*elements->firstEmptyCell)]=currentValue++;
        (*elements->firstEmptyCell)++;
      sem_post(elements->mutex);

    sem_post(elements->consumerSem);
  }
  return NULL;
}

//************************************************//

void * consumer( void * args){
  thread_args *elements = (struct thread_args *)args;

  for(unsigned i=0;i<elements->num_items;i++){

    sem_wait(elements->consumerSem);

      sem_wait(elements->mutex);
        --(*elements->firstEmptyCell);
        cout<< "Consuming - "<<elements->vector[(*elements->firstEmptyCell)]<<endl;
      sem_post(elements->mutex);

    sem_post(elements->producerSem);
  }
  return NULL;

}

//************************************************//

int main(){

  const int tam_vec=10;
  int * vector;
  int firstEmptyCell=0;
  const unsigned long num_items = 50;
  sem_t producerSem,consumerSem,mutex;
	pthread_t producerThread, consumerThread ;
  thread_args args;

	sem_init(&producerSem,0,10);
	sem_init(&consumerSem,0,0);
  sem_init(&mutex,0,1);

  //Load args
  vector = (int*) malloc(tam_vec * sizeof(int));
  args.vector=vector;
  args.num_items=num_items;
  args.firstEmptyCell=&firstEmptyCell;
  args.producerSem=&producerSem;
  args.consumerSem=&consumerSem;
  args.mutex=&mutex;

	pthread_create(&producerThread,NULL,producer,&args);
	pthread_create(&consumerThread,NULL,consumer,&args);

	pthread_join(producerThread,NULL);
	pthread_join(consumerThread,NULL);

	sem_destroy(&producerSem);
	sem_destroy(&consumerSem);
  sem_destroy(&mutex);
  free(vector);

	return 0;
}
