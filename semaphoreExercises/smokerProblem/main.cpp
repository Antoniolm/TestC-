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

  Smoker * smoker1=new Smoker();
  Smoker * smoker2=new Smoker();
  Smoker * smoker3=new Smoker();
  Supplier * supplier=new Supplier();

  smoker1->initParameters();
  smoker2->initParameters();
  smoker3->initParameters();
  supplier->initParameters();

  smoker1->start();
  smoker2->start();
  smoker3->start();
  supplier->start();

  delete smoker1;
  delete smoker2;
  delete smoker3;
  delete supplier;

	return 0;
}
