#pragma once
#include "DoublyLinkedList.h"

using namespace std;

template <class T>
class Stack
{
public:
    Stack();
    void push(const T& elem);
    T pop();
    T top();
    int size();
    bool isEmpty();
private:
    DoublyLinkedList<T> list;
};

template <class T>
Stack<T>::Stack()
{

}

template <class T>
void Stack<T>::push(const T& elem)
{
    list.insertAtRear(elem);
}

template <class T>
T Stack<T>::pop()
{
    T elem;
    try
    {
        list.removeFromRear(elem);
    }
    catch (DllException)
    {
        cout << "Out of Bounds: Array size 0";
        abort();
    }
    return elem;
}

template <class T>
T Stack<T>::top()
{
    T elem;
    try
    {
        list.last(elem);
    }
    catch (DllException)
    {
        cout << "Out of Bounds: Array size 0";
        abort();
    }
    return elem;
}

template <class T>
int Stack<T>::size()
{
    return list.size();
}

template <class T>
bool Stack<T>::isEmpty()
{
    return list.isEmpty();
}