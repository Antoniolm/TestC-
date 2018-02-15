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

#ifndef PRODUCER_H
#define PRODUCER_H

#include <string>
#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;

class Producer{
public:

  //////////////////////////////////////////////////////////////////////////
  /** Constructor */
  //////////////////////////////////////////////////////////////////////////
  Producer();

  //////////////////////////////////////////////////////////////////////////
  /** Destructor */
  //////////////////////////////////////////////////////////////////////////
  virtual ~Producer();

  void initParameters(int * aVector,int * aFirstCell, int numItems, sem_t * prodSem, sem_t * consSem, sem_t * mutex_sem);

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will ran in the thread
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void run();

  void start();

protected:

private:
  std::thread thread;
  int * vector;
  int *firstEmptyCell;
  long num_items;
  sem_t * producerSem, * consumerSem, * mutex;

};

#endif //PRODUCER_H
