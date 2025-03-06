#pragma once
#include "DllException.h"

template <class T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& original);
	~DoublyLinkedList();
	void insertAtFront(const T& elem);
	void insertAtRear(const T& elem);
	bool removeFromFront(T& elem); //true if an item is removed, elem holds that value
	bool removeFromRear(T& elem); //true if an item is removed, elem holds that value
	bool remove(); //remove the element that the current pointer points to
	bool remove(const T& elem); //remove all occurrences of the element that is passed in.
	int size();
	bool first(T& elem);
	bool last(T& elem);
	bool next(T& elem);
	bool previous(T& elem);
	bool isEmpty();
	bool find(const T& elem); //returns a true/false value indicating if an element is present in the list
	T& at(int pos); //a method that simulates accessing the list like an array. Throw any exception type if out of bounds. 
	T& operator[](int pos); //call at(pos)
private:
	struct Node
	{
		T data;
		Node* p_previous;
		Node* p_next;
	};
	Node* p_head;
	Node* p_tail;
	Node* p_current;
	int numElems;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	p_head = 0;
	p_tail = 0;
	p_current = 0;
	numElems = 0;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& original)
{
	p_head = 0;
	p_tail = 0;
	numElems = 0;
	Node* p_firstNode = original.p_head;
	p_current = p_firstNode;
	while (p_current != 0)
	{
		Node* p_copyNode = new Node;
		p_copyNode->data = p_current->data;
		p_copyNode->p_next = 0;
		p_copyNode->p_previous = p_tail;
		if (p_tail != 0)
		{
			p_tail->p_next = p_copyNode;
		}
		else
		{
			p_head = p_copyNode;
		}
		p_tail = p_copyNode;
		p_current = p_current->p_next;
		numElems++;
	}
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	Node* p_delete;
	while (!isEmpty())
	{
		p_delete = p_head;
		p_head = p_head->p_next;
		delete p_delete;
		numElems--;
	}
}

template <class T>
void DoublyLinkedList<T>::insertAtFront(const T& elem)
{
	Node* p_newNode = new Node;
	p_newNode->data = elem;
	p_newNode->p_next = 0;
	p_newNode->p_previous = 0;
	if (isEmpty())
	{
		//p_newNode->p_next = p_head;
		p_head = p_newNode;
		p_tail = p_newNode;
	}
	else
	{
		p_head->p_previous = p_newNode;
		p_newNode->p_next = p_head;
		p_head = p_newNode;
	}
	numElems++;
}

template <class T>
void DoublyLinkedList<T>::insertAtRear(const T& elem)
{
	Node* p_newNode = new Node;
	p_newNode->data = elem;
	p_newNode->p_next = 0;
	p_newNode->p_previous = 0;
	if (isEmpty())
	{
		p_tail = p_newNode;
		p_head = p_newNode;
	}
	else
	{
		p_tail->p_next = p_newNode;
		p_newNode->p_previous = p_tail;
		p_tail = p_newNode;
	}
	numElems++;
}

template <class T>
bool DoublyLinkedList<T>::removeFromFront(T& elem)
{
	Node* p_temp = p_head;
	if (size() > 1)
	{
		p_head = p_head->p_next;
		p_head->p_previous = 0;
		elem = p_temp->data;
		delete p_temp;
		numElems--;
		return true;
	}
	else if (size() == 1)
	{
		p_head = 0;
		p_tail = 0;
		elem = p_temp->data;
		delete p_temp;
		numElems--;
		return true;
	}
	delete p_temp;
	return false;
}

template <class T>
bool DoublyLinkedList<T>::removeFromRear(T& elem)
{
	Node* p_temp = p_tail;
	if (size() > 1)
	{
		p_tail = p_tail->p_previous;
		p_tail->p_next = 0;
		elem = p_temp->data;
		delete p_temp;
		numElems--;
		return true;
	}
	else if (size() == 1)
	{
		p_head = 0;
		p_tail = 0;
		elem = p_temp->data;
		delete p_temp;
		numElems--;
		return true;
	}
	if (size() == 0)
	{
		throw DllException("Out of Bounds");
	}
	delete p_temp;
	return false;
}

template <class T>
int DoublyLinkedList<T>::size()
{
	return numElems;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
	return size() == 0;
}

template <class T>
bool DoublyLinkedList<T>::next(T& elem)
{
	if (isEmpty() || p_current->p_next == 0)
	{
		return false;
	}
	else
	{
		p_current = p_current->p_next;
		elem = p_current->data;
		return true;
	}
}

template <class T>
bool DoublyLinkedList<T>::previous(T& elem)
{
	if (isEmpty() || p_current->p_previous == 0)
	{
		return false;
	}
	else
	{
		p_current = p_current->p_previous;
		elem = p_current->data;
		return true;
	}
}
template <class T>
T& DoublyLinkedList<T>::at(int pos)
{
	p_current = p_head;
	if (p_current == 0)
	{
		throw DllException("Out of Bounds");
	}
	for (int i = 0; i < pos; i++)
	{
		if (p_current == 0)
		{
			throw DllException("Out of Bounds");
		}
		else if (p_current->p_next != 0)
		{
			p_current = p_current->p_next;
		}
		else
		{
			throw DllException("Out of Bounds");
		}
	}

	return p_current->data;
}

template <class T>
T& DoublyLinkedList<T>::operator[](int pos)
{
	return at(pos);
}

template <class T>
bool DoublyLinkedList<T>::first(T& elem)
{
	if (!isEmpty())
	{
		p_current = p_head;
		elem = p_current->data;
		return true;
	}

	return false;
}

template <class T>
bool DoublyLinkedList<T>::last(T& elem)
{
	if (!isEmpty())
	{
		p_current = p_tail;
		elem = p_current->data;
		return true;
	}

	return false;
}

template <class T>
bool DoublyLinkedList<T>::remove()
{
	Node* p_temp = p_current;
	if (size() == 0)
	{
		return false;
	}
	else if (size() == 1)
	{
		p_head = 0;
		p_tail = 0;
		delete p_temp;
		numElems--;
		return true;
	}
	else if (p_current == p_tail)
	{
		p_current = p_current->p_previous;
		p_current->p_next = 0;
		p_tail = p_current;
		delete p_temp;
		numElems--;
		return true;
	}
	else if (p_current == p_head)
	{
		p_current = p_current->p_next;
		p_current->p_previous = 0;
		p_head = p_current;
		delete p_temp;
		numElems--;
		return true;
	}
	else
	{
		p_current = p_current->p_next;
		p_current->p_previous = p_temp->p_previous;
		p_current = p_current->p_previous;
		p_current->p_next = p_temp->p_next;
		delete p_temp;
		numElems--;
		return true;
	}
}

template <class T>
bool DoublyLinkedList<T>::remove(const T& elem)
{
	bool retVal = false;
	T data;
	first(data);
	if (data == elem)
	{
		remove();
		retVal = true;
	}
	while (next(data))
	{
		if (data == elem)
		{
			remove();
			retVal = true;
		}
	}

	return retVal;
}

template <class T>
bool DoublyLinkedList<T>::find(const T& elem)
{
	T data;
	first(data);
	if (data == elem)
	{
		return true;
	}
	while (next(data))
	{
		if (data == elem)
		{
			return true;
		}
	}

	return false;
}