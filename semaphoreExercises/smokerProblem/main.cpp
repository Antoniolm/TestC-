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
#include "threadPackage/smoker.h"
#include "threadPackage/supplier.h"

using namespace std;

int main(){

  sem_t semPaper,semTobacoo,semMatch,semSupplier;

  sem_init(&semPaper,0,0);
	sem_init(&semTobacoo,0,0);
  sem_init(&semMatch,0,0);
  sem_init(&semSupplier,0,0);

  Smoker * smoker1=new Smoker(TOBACCO);
  Smoker * smoker2=new Smoker(PAPER);
  Smoker * smoker3=new Smoker(MATCH);
  Supplier * supplier=new Supplier();

  smoker1->initParameters(&semPaper,&semTobacoo,&semMatch,&semSupplier);
  smoker2->initParameters(&semPaper,&semTobacoo,&semMatch,&semSupplier);
  smoker3->initParameters(&semPaper,&semTobacoo,&semMatch,&semSupplier);
  supplier->initParameters(&semPaper,&semTobacoo,&semMatch,&semSupplier);

  smoker1->start();
  smoker2->start();
  smoker3->start();
  supplier->start();

  delete smoker1;
  delete smoker2;
  delete smoker3;
  delete supplier;

  sem_destroy(&semPaper);
	sem_destroy(&semTobacoo);
  sem_destroy(&semMatch);
  sem_destroy(&semSupplier);

	return 0;
}
