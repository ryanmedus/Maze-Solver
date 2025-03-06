#pragma once
#include "DoublyLinkedList.h"

using namespace std;

template <class T>
class Queue
{
public:
    Queue();
    void enqueue(const T& elem);
    T dequeue();
    T front();
    int size();
    bool isEmpty();
private:
    DoublyLinkedList<T> list;
};

template <class T>
Queue<T>::Queue()
{

}

template <class T>
void Queue<T>::enqueue(const T& elem)
{
    list.insertAtFront(elem);
}

template <class T>
T Queue<T>::dequeue()
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
T Queue<T>::front()
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
int Queue<T>::size()
{
    return list.size();
}

template <class T>
bool Queue<T>::isEmpty()
{
    return list.isEmpty();
}