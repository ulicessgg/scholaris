#include <iostream>
#include <iomanip>
#include "queue.h"

using namespace std;

void queue::initializeQueue()
{
    queueFront = queueRear = nullptr;
    queueElements = 0;
}

void queue::setList()
{
    char opt;
    bool adding = true;
    int num;

    while (adding == true)
    {
        cout << " Enter linked value: ";
        cin >> num;
        cout << endl;

        addQueue(num);

        cout << " Do you wish to continue? Enter Y or N: ";
        cin >> opt;
        cout << endl;

        if (opt == 'Y' || opt == 'y')
        {
            adding = true;
        }
        else if (opt == 'N' || opt == 'n')
        {
            adding = false;
        }
        else
        {
            cout << " INPUT ERROR!" << endl;
            cout << endl;
            break;
        }
    }
}

void queue::printQueue()
{
    Node* current = queueFront;
    cout << " Linked Stack Elements: ";
    for (int i = 0; i < queueElements; i++)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl << endl;
}

bool queue::isEmptyQueue()
{
    if (queueElements == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int queue::front()
{
    return queueFront->data;
}

int queue::back()
{
    return queueRear->data;
}

void queue::addQueue(int num)
{
    if (queueRear == nullptr)
    {
        queueFront = queueRear = new Node(num);
    }
    else
    {
        queueRear->next = new Node(num);
        queueRear = queueRear->next;
    }

    queueElements++;
}

void queue::deleteQueue()
{
    if (isEmptyQueue() == true)
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        Node* temp = queueFront;

        queueFront = queueFront->next;
        if (queueFront == nullptr)
        {
            queueRear = nullptr;
        }
        queueElements--;
        delete temp;
    }
}
