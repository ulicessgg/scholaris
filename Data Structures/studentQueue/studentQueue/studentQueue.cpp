#include <iostream>
#include <iomanip>
#include <string>
#include "studentQueue.h"
#include "students.h"

using namespace std;

void studentQueue::initializeQueue()
{
    queueFront = queueRear = nullptr;
    queueElements = 0;
}

void studentQueue::setList()
{
    char opt;
    bool adding = true;
    string name;
    int iD;

    while (adding == true)
    {
        cout << " Enter Student Name: ";
        cin >> name;
        cout << endl;

        cout << " Enter Student ID: ";
        cin >> iD;
        cout << endl;

        addQueue(name, iD);

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

void studentQueue::printQueue()
{
    Node* current = queueFront;
    for (int i = 0; i < queueElements; i++)
    {
        cout << " Student " << i + 1 << endl;
        cout << " Name: " << current->compSci.getName();
        cout << " ID: " << current->compSci.getId() << endl << endl;
        current = current->next;
    }
}

bool studentQueue::isEmptyQueue()
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

string studentQueue::frontName()
{
    return queueFront->compSci.getName();
}

int studentQueue::frontId()
{
    return queueFront->compSci.getId();
}

string studentQueue::backName()
{
    return queueRear->compSci.getName();
}

int studentQueue::backId()
{
    return queueRear->compSci.getId();
}

void studentQueue::addQueue(string name, int iD)
{
    Node* studentQueue = nullptr;
    studentQueue = new Node;
    studentQueue->compSci.setName(name);
    studentQueue->compSci.setId(iD);
    studentQueue->next = nullptr;
    if (queueRear == nullptr)
    {
        queueFront = queueRear = studentQueue;
        queueElements++;
    }
    else
    {
        queueRear = queueRear->next = studentQueue;
        queueElements++;
    }
}

void studentQueue::deleteQueue()
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
        delete temp;
        queueElements--;
    }
}
