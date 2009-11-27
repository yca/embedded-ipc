/*
 * SharedMemory.h
 *
 *  Created on: Nov 9, 2009
 *      Author: celal
 */

#ifndef SHAREDMEMORY_H_
#define SHAREDMEMORY_H_

#include <QSharedMemory>

class SharedMemory
{
public:
	SharedMemory();
	virtual ~SharedMemory();
	void load(); // sharedMemory alanına Data girişi için


private:
	void detach(); // var olan yok etmek serbest bırakmak için


private:
	QSharedMemory sharedMemory; // shared memory alanım
};

#endif /* SHAREDMEMORY_H_ */
