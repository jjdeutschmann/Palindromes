//****************************************************************************************************
//
//     File: stack.h
//     Author: Jennifer Deutschmann
//
//     Class definition for the Stack class.
//
//****************************************************************************************************

#ifndef STACK_H
#define STACK_H

//****************************************************************************************************

template <typename TYPE>
class Stack
{
	private:
		TYPE * stkData;
		int top;
		int capacity;
	public:
		Stack ( int c = 50 );
		~Stack ();
		bool push (const TYPE & dataIn);
		bool pop (TYPE & dataOut);
		bool peek (TYPE & dataOut) const;
		int getSize () const;
		bool isFull () const;
		bool isEmpty () const;
};

//****************************************************************************************************

template <typename TYPE>
Stack<TYPE> :: Stack ( int c )
{
	capacity = c;
	stkData = new TYPE[capacity];
	top = -1;
}

//****************************************************************************************************

template <typename TYPE>
Stack<TYPE> :: ~Stack ()
{
	delete [] stkData;

	stkData = NULL;
	top = -1;
	capacity = 0;
}

//****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE> :: push ( const TYPE & dataIn )
{
	bool success = false;

	if ( (top + 1) < capacity )
	{
		top++;
		stkData[top] = dataIn;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE> :: pop ( TYPE & dataOut )
{
	bool success = false;

	if ( top > -1 )
	{
		dataOut = stkData[top];
		top--;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE> :: peek ( TYPE & dataOut ) const
{
	bool success = false;

	if ( top > -1 )
	{
		dataOut = stkData[top];
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
int Stack<TYPE> :: getSize () const
{
	return ( top + 1 );
}

//****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE> :: isFull () const
{
	return ( ( top + 1 ) == capacity );
}

//****************************************************************************************************

template <typename TYPE>
bool Stack<TYPE> :: isEmpty () const
{
	return ( top == -1 );
}

//****************************************************************************************************

#endif

//****************************************************************************************************
