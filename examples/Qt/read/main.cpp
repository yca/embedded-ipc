/*
 * main.cpp
 *
 *  Created on: Nov 9, 2009
 *      Author: celal
 */

#include <QtCore/QCoreApplication>
#include "SharedMemory.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SharedMemory shared;
    shared.read();

    return a.exec();
}
