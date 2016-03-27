//****************************************************************************************************
//
//     File: queue.h
//
//     Author: Jennifer Deutschmann
//
//     The class definition for Queue.
//		
//     Other files needed:
//     1. node.h	 
//		
//****************************************************************************************************

#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

//****************************************************************************************************

template <typename TYPE>
class Queue
{
	private:
		Node<TYPE> * front;
		Node<TYPE> * rear;
		int numValues;
	public:
		Queue();
		~Queue();
		bool enqueue ( const TYPE & dataIn );
		bool dequeue ( TYPE & dataOut );
		bool viewFront ( TYPE & dataOut ) const;
		bool viewRear ( TYPE & dataOut ) const;
		int getSize () const;
		bool isFull () const;
		bool isEmpty () const;
};

//****************************************************************************************************

template <typename TYPE>
Queue<TYPE> :: Queue ()
{
	front = NULL;
	rear = NULL;
	numValues = 0;
}

//****************************************************************************************************

template <typename TYPE>
Queue<TYPE> :: ~Queue ()
{
	Node<TYPE> * pTemp;

	while ( front )
	{
		pTemp = front -> next;
		delete front;
		front = pTemp;
	}
}

//****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE> :: enqueue ( const TYPE & dataIn )
{
	bool success = false;
	Node<TYPE> * pNew = new (nothrow) Node<TYPE> (dataIn);

	if ( pNew )
	{
		if ( rear )
			rear -> next = pNew;
		else
			front = pNew;

		rear = pNew;
		numValues++;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE> :: dequeue ( TYPE & dataOut )
{
	bool success = false;
	Node<TYPE> * pDel = front;

	if ( front )
	{
		dataOut = front -> data;
		front = front -> next;
		numValues--;

		if ( !front )
			rear = NULL;

		delete pDel;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE> :: viewFront ( TYPE & dataOut ) const
{
	bool success = false;

	if ( front )
	{
		dataOut = front -> data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE> :: viewRear ( TYPE & dataOut ) const
{
	bool success = false;

	if ( rear )
	{
		dataOut = rear -> data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
int Queue<TYPE> :: getSize () const
{
	return numValues;
}

//****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE> :: isFull () const
{
	bool success = true;
	Node<TYPE> * pTest = new (nothrow) Node<TYPE>;

	if ( pTest )
	{
		success = false;
		delete pTest;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool Queue<TYPE> :: isEmpty () const
{
	return ( front == NULL );
}

//****************************************************************************************************

#endif

//****************************************************************************************************
