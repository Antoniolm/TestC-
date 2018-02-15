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
#include <thread>
#include <semaphore.h>
#include "threadPackage/consumer.h"
#include "threadPackage/producer.h"

using namespace std;

int main(){

  int * vector;
  const int tam_vec=10;
  int firstEmptyCell=0;
  const unsigned long num_items = 50;
  sem_t producerSem,consumerSem,mutex;

  Consumer * consumer=new Consumer();
  Producer * producer=new Producer();
  vector = (int*) malloc(tam_vec * sizeof(int));

	sem_init(&producerSem,0,tam_vec);
	sem_init(&consumerSem,0,0);
  sem_init(&mutex,0,1);

  consumer->initParameters(vector,&firstEmptyCell,num_items,&producerSem,&consumerSem,&mutex);
  producer->initParameters(vector,&firstEmptyCell,num_items,&producerSem,&consumerSem,&mutex);

  consumer->start();
  producer->start();

  delete consumer;
  delete producer;


	sem_destroy(&producerSem);
	sem_destroy(&consumerSem);
  sem_destroy(&mutex);
  free(vector);

	return 0;
}
