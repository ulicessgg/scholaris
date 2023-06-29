#include <iostream>
#include <iomanip>
#include "myQueue.h"

using namespace std;

void myQueue::initializeQueue()
{
    cout << " Enter Max Queue Size: ";
    cin >> maxQueueSize;
    cout << endl;

    queueFront = 0;
    queueRear = -1;
    queueElements = 0;

    myIntQueue = new int[maxQueueSize];

    for (int i = 0; i < maxQueueSize; i++)
    {
        myIntQueue[i] = 0;
    }
}

void myQueue::setList()
{
    bool adding = true;
    int num;

    for (int i = 0; i < maxQueueSize; i++)
    {
        cout << " Enter linked value: ";
        cin >> num;
        cout << endl;

        addQueue(num);
    }
}

bool myQueue::isEmptyQueue()
{
    if (queueElements = 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool myQueue::isFullQueue()
{
    if (queueElements == maxQueueSize)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int myQueue::front()
{
    return myIntQueue[queueFront];
}

int myQueue::back()
{
    return myIntQueue[queueRear];
}

void myQueue::addQueue(int num)
{
    if (isFullQueue() == true)
    {
        maxQueueSize = maxQueueSize * 2;
        int* temp = new int[maxQueueSize];

        for (int i = 0; i < maxQueueSize / 2; i++)
        {
            temp[i] = myIntQueue[i];
        }

        delete myIntQueue;

        for (int i = (maxQueueSize / 2); i < maxQueueSize; i++)
        {
            temp[i] = 0;
        }

        myIntQueue = temp;
        queueRear++;
        myIntQueue[queueRear] = num;
        queueElements++;
    }
    else if (0 < queueFront)
    {
        if (isFullQueue() == true)
        {
            cout << "Fix Me" << queueElements << endl;
        }
        else
        {
            queueRear = queueFront - 1;
            myIntQueue[queueRear] = num;
            queueElements++;
        }

    }
    else
    {
        queueRear++;
        myIntQueue[queueRear] = num;
        queueElements++;
    }
}

void myQueue::deleteQueue()
{
    if (isEmptyQueue() == true)
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        myIntQueue[queueFront] = 0;
        queueFront++;
        queueElements--;
    }
}

int myQueue::getSize()
{
    return maxQueueSize;
}

void myQueue::printQueue()
{
    cout << " Queue Elements: ";
    for (int i = 0; i < maxQueueSize; i++)
    {
        if (myIntQueue[i] == 0)
        {

        }
        else
        {
            cout << myIntQueue[i] << " ";
        }
    }
    cout << endl << endl;
}

