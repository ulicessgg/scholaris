#include <iostream>
#include <stdexcept>
#include <string>
#include "tree.h"

tree::tree()
{
    root = nullptr;
}

void tree::setList()
{
    char opt;
    bool adding = true;
    int num;

    while (adding == true)
    {
        cout << " Enter tree value: ";
        cin >> num;
        cout << endl;

        insert(num);

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

void tree::search(const int& item)
{
    if (searchTree(item) == true)
    {
        cout << " " << item << " is present in tree.";
    }
    else
    {
        cout << " " << item << " is not present in tree.";
    }
}

bool tree::searchTree(const int& item)
{
    bool found = false;

    if (root == nullptr)
    {
        cout << "EMPTY" << endl << endl;
    }
    else
    {
        tClass* current = root;

        while (current != nullptr && !found)
        {
            if (current->data == item)
            {
                found = true;
            }
            else if (current->data > item)
            {
                current = current->rNext;
            }
            else
            {
                current = current->lNext;
            }
        }
    }
    return found;
}

void tree::insert(const int& item)
{
    insertLeaf(item);
}

tClass* tree::insertLeaf(const int& item)
{
    tClass* current = root;
    tClass* trailCurrent = nullptr;

    if (root == nullptr)
    {
        root = new tClass(item);
    }
    else
    {
        while (current != nullptr)
        {
            trailCurrent = current;

            if (current->data == item)
            {
                cout << endl << "ERROR! TWO NODES OF SAME VALUE ARE NOT PERMITTED ENTER NEW VALUE" << endl;
            }
            else if (current->data > item)
            {
                current = current->lNext;
            }
            else
            {
                current = current->rNext;
            }
        }
        if (trailCurrent->data > item)
        {
            trailCurrent->lNext = new tClass(item);
        }
        else
        {
            trailCurrent->rNext = new tClass(item);
        }
    }
    return root;
}

void tree::deleteNode(const int& item)
{
    deleteFromTree(item);
}

void tree::deleteFromTree(const int& item)
{
    tClass* current = root;
    tClass* trailCurrent = nullptr;

    while (current != nullptr)
    {
        if (current->data > item)
        {
            trailCurrent = current;
            current = current->lNext;
        }
        else if (current->data < item)
        {
            trailCurrent = current;
            current = current->rNext;
        }
        else if (current->lNext == nullptr && current->rNext == nullptr)
        {
            trailCurrent->lNext = nullptr;
            trailCurrent->rNext = nullptr;
            free(current);
            current = nullptr;
            break;
        }
        else if (current->lNext == nullptr || current->rNext == nullptr)
        {
            if (current->lNext != nullptr)
            {
                trailCurrent->lNext = current->lNext;
            }
            else
            {
                trailCurrent->rNext = current->rNext;
            }
            free(current);
        }
        else
        {
            tClass* temp = current->rNext;
            while (temp->lNext != nullptr)
            {
                trailCurrent = temp;
                temp = temp->lNext;
            }
            current->data = temp->data;
            trailCurrent->lNext = nullptr;
            delete temp;
        }
    }
}

void tree::printTree()
{
    inOrder();
}

void tree::inOrder()
{
    tClass* current = root;
    tClass* trailCurrent = nullptr;

    if (root == nullptr)
    {
        root = nullptr;
    }
    else
    {
        while (current != nullptr)
        {
            if (current->lNext == nullptr)
            {
                cout << current->data << " ";
                current = current->rNext;
            }
            else
            {
                trailCurrent = current->lNext;

                while (trailCurrent->rNext != nullptr && trailCurrent->rNext != current)
                {
                    trailCurrent = trailCurrent->rNext;
                }
                if (trailCurrent->rNext == nullptr)
                {
                    trailCurrent->rNext = current;
                    current = current->lNext;
                }
                else
                {
                    trailCurrent->rNext = nullptr;
                    cout << current->data << " ";
                    current = current->rNext;
                }
            }
        }
    }
}
