#include <iostream>
#include <iomanip>
#include "mystack.h"

using namespace std;

void mystack::initializeStack()
{
    cout << " Enter array size: ";
    cin >> mySize;
    topElement = -1;

    myIntStack = new int[mySize];
    for (int i = 0; i < mySize; i++)
    {
        myIntStack[i] = 0;
    }
}

void mystack::setStack()
{
    int val;
    for (int i = 0; i < mySize; i++)
    {
        cout << " Enter Value " << i + 1 << ": ";
        cin >> val;
        push(val);
        system("CLS");
    }
}

bool mystack::isEmptyStack()
{
    if (topElement == -1)
    {
        return true;
    }
    else
    {
        topElement--;
        return false;
    }
}

bool mystack::isFullStack()
{
    if (topElement == mySize - 1)
    {
        return true;
    }
    else
    {
        topElement++;
        return false;
    }
}

void mystack::push(int num)
{
    if (isFullStack() == true)
    {
        mySize = mySize * 2;

        int* temp = new int[mySize];

        for (int i = 0; i < mySize / 2; i++)
        {
            temp[i] = myIntStack[i];
        }

        delete myIntStack;

        for (int i = (mySize / 2); i < mySize; i++)
        {
            temp[i] = 0;
        }

        myIntStack = temp;
        topElement++;
        myIntStack[topElement] = num;
    }
    else
    {
        myIntStack[topElement] = num;
    }
}

int mystack::top()
{
    return myIntStack[topElement];
}

void mystack::pop()
{
    if (isEmptyStack() == true)
    {
        cout << "Stack is Full." << endl;
    }
    else
    {
        myIntStack[mySize - 1] = 0;
    }
}

void mystack::bubbleSort()
{
    int temp;

    for (int i = 0; i < mySize - 1; i++)
    {
        for (int j = 0; j < mySize - i - 1; j++)
        {
            if (myIntStack[j] > myIntStack[j + 1])
            {
                temp = myIntStack[j];
                myIntStack[j] = myIntStack[j + 1];
                myIntStack[j + 1] = temp;
            }
        }
    }
}

void mystack::selectionSort()
{
    int temp;
    int min;

    for (int i = 0; i < mySize - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < mySize; j++)
        {
            if (myIntStack[j] < myIntStack[min])
            {
                min = j;
            }
        }
        temp = myIntStack[min];
        myIntStack[min] = myIntStack[i];
        myIntStack[i] = temp;
    }
}

/*
void mystack::print()//stack
{
    for(int i=mySize-1; -1<i; i--)
    {
        cout << " Element " << i+1 << ": " << myIntStack[i] << endl;
    }
    cout << endl;
}
*/

void mystack::print()
{
    for (int i = 0; i < mySize; i++)
    {
        cout << " Element " << i + 1 << ": " << myIntStack[i] << endl;
    }
    cout << endl;
}

int mystack::getSize()
{
    return mySize;
}

