/*
 * SharedMemory.cpp
 *
 *  Created on: Nov 9, 2009
 *      Author: celal
 */

#include "SharedMemory.h"
#include <QBuffer>
#include <QVariant>
#include <QtCore/QDebug>
#include <iostream>
using namespace std;


SharedMemory::SharedMemory() : sharedMemory("sharedAlan")
{
	qDebug("constructor...");
}
void SharedMemory::load()
{
	if (sharedMemory.isAttached())
	         detach();

		// load into shared memory
	     QBuffer buffer;
	     QString  data = "*Data Data Data*";
	     cout <<" load :" << data.toStdString() << endl;

	     buffer.open(QBuffer::ReadWrite);
	     QDataStream out(&buffer);
	     out << data;
	     int size = buffer.size();

	     if (!sharedMemory.create(size)) {
	         qDebug("Shared memory alanı oluşturulumadı.. \n Zaten var");
	         return;
	     }
	     sharedMemory.lock();
	     char *to = (char*)sharedMemory.data();
	     const char *from = buffer.data().data();
	     memcpy(to, from, qMin(sharedMemory.size(), size));
	     sharedMemory.unlock();

	     cout << " size :" << sharedMemory.size() << endl;


}
void SharedMemory::detach()
{
	  if (!sharedMemory.detach())
	         qDebug("sharde memory yok edilemiyor");
}
SharedMemory::~SharedMemory()
{
	if (!sharedMemory.detach())
		         qDebug("sharde memory yok edilemiyor");
}
