#ifndef STUDENTQUEUE_H
#define STUDENTQUEUE_H

#include "students.h"

using namespace std;

struct Node
{
    students compSci;
    Node* next;
};

class studentQueue
{
public:
    void initializeQueue();
    void setList();
    void printQueue();
    bool isEmptyQueue();
    string frontName();
    int frontId();
    string backName();
    int backId();
    void addQueue(string, int);
    void deleteQueue();

private:
    int* myIntQueue;
    Node* queueFront;
    Node* queueRear;
    int queueElements;
};

#endif // STUDENTQUEUE_H
