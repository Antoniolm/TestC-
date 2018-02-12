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

#include "semaphore.h"

Semaphore::Semaphore(int nCount){
  count=nCount;
}

//************************************************//

Semaphore::~Semaphore(){

}

//************************************************//

void Semaphore::signal(){
  unique_lock<decltype(mutexVar)> lock(mutexVar);
  ++count;
  condition.notify_one();
}

//************************************************//

void Semaphore::wait(){
  unique_lock<decltype(mutexVar)> lock(mutexVar);
  while(!count) // Handle spurious wake-ups.
      condition.wait(lock);
  --count;
}
