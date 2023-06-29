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
    void search(int);
    bool recursiveSearch(tClass*, int);
    void insert(int);
    tClass* recursiveInsert(tClass*, int);
    void deleteNode();
    tClass* deleteFromTree(tClass*);
    void printTree();
    void inOrder(tClass*);

private:
    tClass* root;

};
#endif // TREE_H
