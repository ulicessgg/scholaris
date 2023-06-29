#include <iostream>
#include <iomanip>
#include "mystack.h"

using namespace std;

void linkedMenu(mystack);

int main()
{
    mystack pancakes;

    pancakes.initializeStack();
    system("CLS");
    pancakes.setStack();
    system("CLS");
    linkedMenu(pancakes);

    return 0;
}

void linkedMenu(mystack pancakes)
{
    int menuIn;
    char option;

    cout << " Welcome. From the following enter the corresponding number for that option." << endl
        << " 1) Print linked list" << endl
        << " 2) Look at Top of Linked List" << endl
        << " 3) Pop from linked list" << endl
        << " 4) Bubble Sort linked list" << endl
        << " 5) Selection Sort linked list" << endl
        << " 6) Quit" << endl << endl
        << " User: ";

    cin >> menuIn;

    cout << endl;

    switch (menuIn)
    {
    case 1:
        pancakes.print();
        cout << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(pancakes);
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
        cout << " Top Element: " << pancakes.top() << endl << endl;
        cout << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(pancakes);
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
        pancakes.pop();
        pancakes.print();
        cout << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(pancakes);
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
        pancakes.bubbleSort();
        pancakes.print();
        cout << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(pancakes);
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
        pancakes.selectionSort();
        pancakes.print();
        cout << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(pancakes);
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

    case 6:
        break;

    default:
        system("CLS");
        linkedMenu(pancakes);
        break;
    }
}

