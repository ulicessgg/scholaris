#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

struct tClass
{
    int data;
    tClass* lNext;
    tClass* rNext;
    tClass(int data)
    {
        this->data = data;
        lNext = rNext = NULL;
    }
};

class tree
{
public:
    tree();
    void setList();
    void search(const int&);
    bool searchTree(const int&);
    void insert(const int&);
    tClass* insertLeaf(const int&);
    void deleteNode(const int&);
    void deleteFromTree(const int&);
    void printTree();
    void inOrder();

private:
    tClass* root;

};

#endif // TREE_H
