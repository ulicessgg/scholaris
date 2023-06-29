#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* previous;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class list
{
public:
    // Contructor
    list();

    // Accessors
    int getFirst() const;
    int getLast() const;
    int getAt(int index) const;
    int getSize() const;
    bool isEmpty() const;
    void printList();

    // Mutators
    void setList(); // Additional Function
    void add(int value);
    void addFirst(int value);
    void addLast(int value);
    void addAt(int index, int value);
    void removeVal(int value);
    int removeFirst();
    int removeLast();
    int removeAt(int index);
    void reverseList();
    void clearList();

    // Destructor
    //~list();

private:
    Node* head;
    Node* tail;
    int size;
};
#endif // LIST_H
