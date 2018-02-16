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

#include "supplier.h"

Supplier::Supplier(){

}

//************************************************//

Supplier::~Supplier(){
  if (thread.joinable())
    thread.join();
}

//************************************************//

void Supplier::run(){
  RequiredMaterial material;

  while(true){
    material=(RequiredMaterial)(rand() % 3);
    cout<< "Supplier element : "<< material<<endl;

    switch(material){
      case TOBACCO:
        sem_post(semTobacoo);
      break;
      case PAPER:
        sem_post(semPaper);
      break;
      case MATCH:
        sem_post(semMatch);
      break;
    }
    
    sem_wait(semSupplier);
  }
}
