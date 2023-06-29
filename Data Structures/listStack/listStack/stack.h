#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class stack
{
public:
    stack();
    void printList();
    bool isEmpty();
    int top();
    void push(int);
    void setList();
    void pop();
    void bubbleSort();
    void selectionSort();

private:
    Node* head;
    Node* tail;
    int size;
};

#endif // STACK_H
