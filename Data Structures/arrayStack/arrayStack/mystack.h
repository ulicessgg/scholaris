#ifndef MYSTACK_H
#define MYSTACK_H

class mystack
{
public:
    void initializeStack();
    void setStack();
    bool isEmptyStack();
    bool isFullStack();
    void push(int);
    int top();
    void pop();
    void bubbleSort();
    void selectionSort();
    void print();
    int getSize();

private:
    int mySize;
    int* myIntStack;
    int topElement;
};

#endif // MYSTACK_H
