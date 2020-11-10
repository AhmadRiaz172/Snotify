/* Program:  cSmartArray.cpp
*  Authour:  Victoria Kress
*  Date:     11-07-2020
*  Version:  1.0.0
*  Purpose:
*/

#include<iostream>
#include "cSmartArray.h"


cSmartArray::cSmartArray()
{
	this->m_NextItemIndex = 0;
	// Create initial array
	this->m_Resize();

}

cSmartArray::~cSmartArray()
{
	delete[] Array;
}


void cSmartArray::Push(cPerson data)
{
	//Do I have enough space on the stack
	if (this->m_NextItemIndex == this->m_currentArraySize)
	{
		// Oh no, it's not enough space
		this->m_Resize();
	}

	// Put the person at the current "top" of stack...
	this->Array[this->m_NextItemIndex] = data;

	// Move the stack index to the next location
	this->m_NextItemIndex++;

	return;
}


cPerson cSmartArray::Pop(void)
{
	//TODO: What happens if there's nothing in the array???
	if (this->isEmpty()) {
		cout << "Array is empty " << endl;
	}


	// Move the stack index back...{
	this->m_NextItemIndex--;

	// Return the data that it's referencing
	// (Making a copy here so that I can see the value
	//  in the debug - like for educational value, yo)
	cPerson toReturn = this->Array[this->m_NextItemIndex];

	return toReturn;
}


void cSmartArray::addAtEnd(cPerson data) {
	this->Push(data);
}


cPerson cSmartArray::operator[] (unsigned int index) {
	return Array[index];
}


cPerson cSmartArray::getAt(unsigned int index) {
	return Array[index];
}


unsigned int cSmartArray::getSize(void)
{
	return this->m_NextItemIndex;
}


bool cSmartArray::isEmpty(void)
{
	if (this->m_NextItemIndex <= 0) {
		return true;
	}
	return false;

}

void cSmartArray::clear(void)
{
	while (!this->isEmpty()) {
		delete[] this->Array;
		this->m_NextItemIndex = 0;
		this->m_Resize();
	}

}

// Added to my fancier array

unsigned int cSmartArray::getCapacity(void)
{

	return this->m_currentArraySize;
}

void cSmartArray::m_Resize(void)
{
	// 1. Make a new array (that's bigger)
	// For stl::vector, growth is by 2x each "grow"
	if (this->m_NextItemIndex == 0) {
		this->Array = new cPerson[this->m_currentArraySize];
		return;
	}

	cPerson* pNewArray = new cPerson[this->m_currentArraySize];

	// 2. Copy the old data to the new array
	for (unsigned int index = 0; index < this->m_NextItemIndex; index++)
	{
		pNewArray[index] = this->Array[index];
	}
	this->m_currentArraySize *= 2;
	delete[] this->Array;
	this->Array = new cPerson[this->m_currentArraySize];
	// 3. Point the pointer to the new array
	for (unsigned int index = 0; index < this->m_NextItemIndex; index++)
	{
		this->Array[index] = pNewArray[index];
	}

	// 4. Delete the old array
	delete[] pNewArray;

	return;
}
