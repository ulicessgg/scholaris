#include "stack.h"

stack::stack()
{
    head = tail = nullptr;
    size = 0;
}

void stack::printList()
{
    Node* current = head;
    cout << " Linked Stack Elements: ";
    for (int i = 0; i < size; i++)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl << endl;
}

bool stack::isEmpty()
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int stack::top()
{
    return head->data;
}

void stack::push(int num)
{
    Node* newNode = new Node(num);
    newNode->next = head;
    head = newNode;
    size++;
}

void stack::setList()
{
    char opt;
    bool adding = true;
    int num;

    while (adding == true)
    {
        cout << " Enter linked value: ";
        cin >> num;
        cout << endl;

        push(num);

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

void stack::pop()
{
    if (isEmpty() == true)
    {
        cout << "Stack is Empty." << endl;
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
        tail->next = nullptr;
        delete temp;
        size--;
    }
}

void stack::bubbleSort()
{
    Node* temp;
    bool bubbling = true;
    int num;

    while (bubbling == true)
    {
        bubbling = false;
        temp = head;
        while (temp->next != nullptr)
        {
            if (temp->data > temp->next->data)
            {
                bubbling = true;
                num = temp->data;
                temp->data = temp->next->data;
                temp->next->data = num;
            }
            temp = temp->next;
        }
    }
}

void stack::selectionSort()
{
    Node* temp = head;
    Node* min;
    Node* selection;
    int num;

    while (temp != nullptr)
    {
        min = temp;
        selection = temp->next;

        while (selection != nullptr)
        {
            if (min->data > selection->data)
            {
                min = selection;
            }
            selection = selection->next;
        }
        num = temp->data;
        temp->data = min->data;
        min->data = num;
        temp = temp->next;
    }
}
