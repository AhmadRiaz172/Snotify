/* Program:  cSmartArray.h
*  Authour:  Victoria Kress
*  Date:     11-07-2020
*  Version:  1.0.0
*  Purpose:
*/


#ifndef _cSmartArray_H_
#define _cSmartArray_H_

// NOTE: This smart array only handles cPerson objects
#include "cPerson.h"


class cSmartArray
{
public:
	cSmartArray();
	~cSmartArray();


	void Push(cPerson data);	// push_back
	cPerson Pop(void); 	// Gets data at end of array (tail or back)
	cPerson operator[] (unsigned int index);
	cPerson getAt(unsigned int index);
	void addAtEnd(cPerson data);
	unsigned int getSize(void);
	unsigned int getCapacity(void);
	void clear(void);
	bool isEmpty(void);


private:

	// This will resize the array
	void m_Resize(void);
	// The location of the next item to be added
	unsigned int m_NextItemIndex;	// = 0

	static const unsigned int INITIALARRAYSIZE = 10;
	unsigned int m_currentArraySize = INITIALARRAYSIZE;

	//Actual data
	cPerson* Array;		// Is a pointer (to an array)
};
#endif
