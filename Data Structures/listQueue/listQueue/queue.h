#ifndef QUEUE_H
#define QUEUE_H

struct Node
{
    int data;
    Node* next;
    Node* previous;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class queue
{
public:
    void initializeQueue();
    void setList();
    void printQueue();
    bool isEmptyQueue();
    int front();
    int back();
    void addQueue(int);
    void deleteQueue();

private:
    int* myIntQueue;
    Node* queueFront;
    Node* queueRear;
    int queueElements;
};

#endif // QUEUE_H
