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

class Object{

private:
  int* dataList;
  int size;
protected:

public:
  //////////////////////////////////////////////////////////////////////////
  /** Constructor */
  //////////////////////////////////////////////////////////////////////////
  Object(int sz);

  //////////////////////////////////////////////////////////////////////////
  /** Destructor */
  //////////////////////////////////////////////////////////////////////////
  virtual ~Object();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will obtain the element in the I position
   *    \param i -> The position of the element that the user will obtain
   *    \return int
   */
  //////////////////////////////////////////////////////////////////////////
  int getData(int i);

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will obtain the list of elements
   *    \return int*
   */
  //////////////////////////////////////////////////////////////////////////
  int* getDataList();

  //////////////////////////////////////////////////////////////////////////
  /**
   *  It will obtain the size of the list
   *    \return int*
   */
  //////////////////////////////////////////////////////////////////////////
  int getSize();
};
