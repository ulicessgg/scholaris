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

void tree::search(int item)
{
    if (recursiveSearch(root, item) == true)
    {
        cout << " " << item << " is present in tree.";
    }
    else
    {
        cout << " " << item << " is not present in tree.";
    }
}

bool tree::recursiveSearch(tClass* stump, int item)
{
    bool found = false;

    if (stump == nullptr)
    {
        cout << "EMPTY" << endl << endl;
    }
    else
    {
        if (stump->data == item)
        {
            found = true;
        }
        else if (stump->data > item)
        {
            found = recursiveSearch(stump->lNext, item);
        }
        else if (item > stump->data)
        {
            found = recursiveSearch(stump->rNext, item);
        }
        else
        {
            found = false;
        }
    }
    return found;
}

void tree::insert(const int& item)
{
    bool isTaller = false;
    tClass* newNode;

    newNode = new tClass;
    newNode->data = item;
    newNode->balance = 0;
    newNode->lNext = nullptr;
    newNode->rNext = nullptr;

    avlInsert(root, newNode, isTaller);
}

void tree::avlInsert(tClass*& stump, tClass* newNode, bool& isTaller)
{
    if (stump == nullptr)
    {
        stump = newNode;
        isTaller = true;
    }
    else
    {
        if (stump->data == newNode->data)
        {
            cerr << "No duplicates are allowed." << endl;
        }
        else if (stump->data > newNode->data)
        {
            avlInsert(stump->lNext, newNode, isTaller);

            if (isTaller)
            {
                switch (stump->balance)
                {
                case -1:
                    balanceFromLeft(stump);
                    isTaller = false;
                    break;

                case 0:
                    stump->balance = -1;
                    isTaller = true;
                    break;

                case 1:
                    stump->balance = 0;
                    isTaller = false;
                }
            }
        }
        else
        {
            avlInsert(stump->rNext, newNode, isTaller);

            if (isTaller)
            {
                switch (stump->balance)
                {
                case -1:
                    stump->balance = 0;
                    isTaller = false;
                    break;

                case 0:
                    stump->balance = 1;
                    isTaller = true;
                    break;

                case 1:
                    balanceFromRight(stump);
                    isTaller = false;
                }
            }
        }
    }
}

void tree::deleteNode()
{
    root = deleteFromTree(root);
}

tClass* tree::deleteFromTree(tClass* stump)
{
    if (stump == nullptr)
    {
        stump = nullptr;
    }
    else if (stump->lNext == nullptr && stump->rNext == nullptr)
    {
        stump = nullptr;
    }
    else
    {
        stump->lNext = deleteFromTree(stump->lNext);
        stump->rNext = deleteFromTree(stump->rNext);
    }

    return stump;
}

void tree::rotateToLeft(tClass*& stump)
{
    tClass* temp;

    if (stump == nullptr)
    {
        cerr << "Error in the tree" << endl;
    }
    else if (stump->rNext == nullptr)
    {
        cerr << "Error in the tree:"
            << " No right subtree to rotate." << endl;
    }
    else
    {
        temp = stump->rNext;
        stump->rNext = temp->lNext;
        temp->lNext = stump;
        stump = temp;
    }
}

void tree::rotateToRight(tClass*& stump)
{
    tClass* temp;

    if (stump == nullptr)
    {
        cerr << "Error in the tree" << endl;
    }
    else if (stump->lNext == nullptr)
    {
        cerr << "Error in the tree:"
            << " No left subtree to rotate." << endl;
    }
    else
    {
        temp = stump->lNext;
        stump->lNext = temp->rNext;
        temp->rNext = stump;
        stump = temp;
    }
}

void tree::balanceFromLeft(tClass*& stump)
{
    tClass* lTemp;
    tClass* temp;

    lTemp = stump->lNext;

    switch (lTemp->balance)
    {
    case -1:
        stump->balance = 0;
        lTemp->balance = 0;
        rotateToRight(stump);
        break;

    case 0:
        cerr << "Error: Cannot balance from the left." << endl;
        break;

    case 1:
        temp = lTemp->rNext;
        switch (temp->balance)
        {
        case -1:
            stump->balance = 1;
            lTemp->balance = 0;
            break;

        case 0:
            stump->balance = 0;
            lTemp->balance = 0;
            break;

        case 1:
            stump->balance = 0;
            lTemp->balance = -1;
        }

        temp->balance = 0;
        rotateToLeft(lTemp);
        stump->lNext = lTemp;
        rotateToRight(stump);
    }
}

void tree::balanceFromRight(tClass*& stump)
{
    tClass* rTemp;
    tClass* temp;

    rTemp = stump->rNext;

    switch (rTemp->balance)
    {
    case -1:
        temp = rTemp->lNext;
        switch (temp->balance)
        {
        case -1:
            stump->balance = 0;
            rTemp->balance = 1;
            break;

        case 0:
            stump->balance = 0;
            rTemp->balance = 0;
            break;

        case 1:
            stump->balance = -1;
            rTemp->balance = 0;
        }

        temp->balance = 0;
        rotateToRight(rTemp);
        stump->rNext = rTemp;
        rotateToLeft(stump);
        break;

    case 0:
        cerr << "Error: Cannot balance from the left." << endl;
        break;

    case 1:
        stump->balance = 0;
        rTemp->balance = 0;
        rotateToLeft(stump);
    }
}

void tree::printTree()
{
    inOrder(root);
}

void tree::inOrder(tClass* stump)
{
    if (stump != nullptr)
    {
        inOrder(stump->lNext);
        cout << stump->data << " ";
        inOrder(stump->rNext);
    }
    else
    {

    }
}
