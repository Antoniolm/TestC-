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

#include "smoker.h"

Smoker::Smoker(RequiredMaterial aMat){
  material=aMat;
}

//************************************************//

Smoker::~Smoker(){
  if (thread.joinable())
    thread.join();
}

//************************************************//

void Smoker::run(){
  while(true){

    switch(material){
      case TOBACCO:
        sem_wait(semTobacoo);
      break;
      case PAPER:
        sem_wait(semPaper);
      break;
      case MATCH:
        sem_wait(semMatch);
      break;
    }

    cout<< "Preparing cigarette"<<endl;
    sem_post(semSupplier);
    cout<< "Smoking... -Smoker:"<< material <<endl;
    smoke();
    cout<< "Stop smoking :"<< material<<endl;

  }

}

//************************************************//

void Smoker::smoke(){
  usleep( 100 + (rand() % 1900) );
}
