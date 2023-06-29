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

void tree::insert(int item)
{
    root = recursiveInsert(root, item);
}

tClass* tree::recursiveInsert(tClass* stump, int item)
{
    if (stump == nullptr)
    {
        stump = new tClass(item);
    }
    else
    {
        if (stump->data == item)
        {
            int bug;

            cout << endl << "ERROR! TWO NODES OF SAME VALUE ARE NOT PERMITTED ENTER NEW VALUE" << endl <<
                endl << "Enter leaf: ";
            cin >> bug;
            cout << endl;

            recursiveInsert(stump, bug);
        }
        else if (stump->data > item)
        {
            stump->lNext = recursiveInsert(stump->lNext, item);
        }
        else
        {
            stump->rNext = recursiveInsert(stump->rNext, item);
        }
    }
    return stump;
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
