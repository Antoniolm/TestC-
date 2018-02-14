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
#include "thread.h"

using namespace std;

class Producer {
public:

  //////////////////////////////////////////////////////////////////////////
  /** Constructor */
  //////////////////////////////////////////////////////////////////////////
  Producer();

  //////////////////////////////////////////////////////////////////////////
  /** Destructor */
  //////////////////////////////////////////////////////////////////////////
  virtual ~Producer();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will ran in the thread
   *  \return
   */
  //////////////////////////////////////////////////////////////////////////
  void * run( void * args ){
    struct thread_args *elements = (struct thread_args *)args;
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

protected:

private:

};

#endif //PRODUCER_H
