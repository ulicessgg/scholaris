#include <iostream>
#include <stdexcept>
#include <string>
#include "list.h"

// Contructor
list::list()
{
    head = tail = NULL;
    size = 0;
}

// Accessors
int list::getFirst() const
{
    if (size == 0)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return head->data;
    }
}

int list::getLast() const
{
    if (size == 0)
    {
        throw runtime_error("Index out of range");
    }
    else
    {
        return tail->data;
    }
}

int list::getAt(int index) const
{
    if (index < 0 || index > size - 1)
    {
        throw runtime_error("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}

int list::getSize() const
{
    return size;
}

bool list::isEmpty() const
{
    return head == NULL;
}

void list::printList()
{
    cout << " Linked Stack Elements: ";
    for (int i = 0; i < getSize(); i++)
    {
        cout << getAt(i) << " ";
    }
    cout << endl << endl;
}

// Mutators
void list::setList()
{
    char opt;
    bool adding = true;
    int num;

    while (adding == true)
    {
        cout << " Enter linked value: ";
        cin >> num;
        cout << endl;

        addFirst(num);

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

void list::add(int value)
{
    addLast(value);
}

void list::addFirst(int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    size++;

    if (tail == NULL)
    {
        tail = head;
    }
}

void list::addLast(int value)
{
    if (tail == NULL)
    {
        head = tail = new Node(value);
    }
    else
    {
        tail->next = new Node(value);
        tail = tail->next;
    }

    size++;
}

void list::addAt(int index, int value)
{
    if (value == 0)
    {
        addFirst(value);
    }
    else if (index >= size)
    {
        addLast(value);
    }
    else
    {
        Node* current = head;
        for (int i = 1; i < index; i++)
        {
            current = current->next;
            Node* temp = current->next;
            current->next = new Node(value);
            (current->next)->next = temp;
            size++;
        }
    }
}

void list::removeVal(int data)
{
    for (int i = 0; i < size; i++)
    {
        if (getAt(i) == data)
        {
            if (size == 1)
            {
                removeFirst();
            }
            else
            {

            }

        }
    }
}

int list::removeFirst()
{
    if (size == 0)
    {
        throw runtime_error("No datas in the list");
    }

    else
    {
        Node* temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        size--;
        int data = temp->data;
        delete temp;
        return data;
    }
}

int list::removeLast()
{
    if (size == 0)
    {
        throw runtime_error("No datas in the list");
    }

    else if (size == 1)
    {
        Node* temp = head;
        head = tail = NULL;
        size = 0;
        int data = temp->data;
        delete temp;
        return data;
    }

    else
    {
        Node* current = head;
        for (int i = 0; i < size - 2; i++)
        {
            current = current->next;
        }
        Node* temp = tail;
        tail = current;
        tail->next = NULL;
        int data = temp->data;
        delete temp;
        size--;
        return data;
    }
}

int list::removeAt(int index)
{
    if (index < 0 || index >= size)
    {
        throw runtime_error("Index out of range");
    }

    else if (index == 0)
    {
        return removeFirst();
    }

    else if (index == size - 1)
    {
        return removeFirst();
    }

    else
    {
        Node* previous = head;
        for (int i = 1; i < index; i++)
        {
            previous = previous->next;
        }

        Node* current = previous->next;
        previous->next = current->next;
        size--;
        int data = current->data;
        delete current;
        return data;
    }
}

// LinkedList HW Assignment
void list::reverseList()
{
    Node* current = head;
    Node* previous = NULL;
    Node* next = NULL;

    if (head == NULL)
    {
        cout << "EMPTY" << endl;
    }
    else
    {
        while (current->next != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        current->next = previous;
        head = current;
    }
}

void list::clearList()
{
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
    size = 0;
}

// Destructor
/*list::~list()
{
    clearList();
}
*/
