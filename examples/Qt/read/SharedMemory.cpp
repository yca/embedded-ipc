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
void SharedMemory::read()
{
	 if (!sharedMemory.attach()) {
	        qDebug("SharedMemory Alanı yok");
	         return;
	     }

	     QBuffer buffer;
	     QDataStream in(&buffer);
	     QString data;

	     sharedMemory.lock();
	     buffer.setData((char*)sharedMemory.constData(), sharedMemory.size());
	     buffer.open(QBuffer::ReadOnly);
	     in >> data;
	     sharedMemory.unlock();

	     sharedMemory.detach();
	     cout << "Read :" << data.toStdString() << endl;
	     cout << sharedMemory.key().toStdString() << endl;


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
