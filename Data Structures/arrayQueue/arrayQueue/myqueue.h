#ifndef MYQUEUE_H
#define MYQUEUE_H

class myQueue
{
public:
    void initializeQueue();
    void setList();
    bool isEmptyQueue();
    bool isFullQueue();
    int front();
    int back();
    void addQueue(int);
    void deleteQueue();
    int getSize();
    void printQueue();

private:
    int* myIntQueue;
    int queueFront;
    int queueRear;
    int maxQueueSize;
    int queueElements;
};

#endif // MYQUEUE_H
