#include <iostream>
#include <stdexcept>
#include <string>
#include "tree.h"

using namespace std;

void linkedMenu(tree);

int main()
{
    tree groot;

    groot.setList();
    linkedMenu(groot);

    return 0;
}

void linkedMenu(tree groot)
{
    int menuIn;
    char option;
    int item;

    cout << " Welcome. From the following enter the corresponding number for that option." << endl
        << " 1) Insert to Tree" << endl
        << " 2) Delete from Tree" << endl
        << " 3) Search for Leaf" << endl
        << " 4) Print Tree" << endl
        << " 5) Quit" << endl << endl
        << " User: ";
    cin >> menuIn;
    cout << endl;

    switch (menuIn)
    {
    case 1:
        cout << " Enter linked value: ";
        cin >> item;
        cout << endl;
        groot.insert(item);
        cout << " ";
        groot.printTree();
        cout << endl << endl << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(groot);
            break;
        }
        else if (option == 'N' || option == 'n')
        {
            break;
        }
        else
        {
            cout << " INPUT ERROR!" << endl;
            cout << endl;
            system("CLS");
            break;
        }

    case 2:
        groot.deleteNode();
        cout << " ";
        groot.printTree();
        cout << endl << endl << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(groot);
            break;
        }
        else if (option == 'N' || option == 'n')
        {
            break;
        }
        else
        {
            cout << " INPUT ERROR!" << endl;
            cout << endl;
            system("CLS");
            break;
        }

    case 3:
        cout << " Enter search value: ";
        cin >> item;
        cout << endl;
        groot.search(item);
        cout << endl << endl << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(groot);
            break;
        }
        else if (option == 'N' || option == 'n')
        {
            break;
        }
        else
        {
            cout << " INPUT ERROR!" << endl;
            cout << endl;
            system("CLS");
            break;
        }

    case 4:
        cout << " ";
        groot.printTree();
        cout << endl << endl << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(groot);
            break;
        }
        else if (option == 'N' || option == 'n')
        {
            break;
        }
        else
        {
            cout << " INPUT ERROR!" << endl;
            cout << endl;
            system("CLS");
            break;
        }

    case 5:
        break;

    default:
        system("CLS");
        linkedMenu(groot);
        break;
    }
}
