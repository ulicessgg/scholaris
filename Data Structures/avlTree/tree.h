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
    int balance;
};

class tree
{
public:
    tree();
    void setList();
    void search(int);
    bool recursiveSearch(tClass*, int);
    void insert(const int&);
    void avlInsert(tClass*&, tClass*, bool&);
    void deleteNode();
    tClass* deleteFromTree(tClass*);
    void rotateToLeft(tClass*&);
    void rotateToRight(tClass*&);
    void balanceFromLeft(tClass*&);
    void balanceFromRight(tClass*&);
    void printTree();
    void inOrder(tClass*);

private:
    tClass* root;

};
#endif // TREE_H
