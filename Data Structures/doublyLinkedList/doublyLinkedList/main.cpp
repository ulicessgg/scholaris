#include <iostream>
#include <stdexcept>
#include <string>
#include "list.h"

using namespace std;

void linkedMenu(list);

int main()
{
    list chains;

    chains.setList();

    system("CLS");

    linkedMenu(chains);

    return 0;
}

void linkedMenu(list chains)
{
    int menuIn;  // string for user input
    char option;

    cout << " Welcome. From the following enter the corresponding number for that option." << endl // Outputs all available options for the player
        << " 1) Print linked list" << endl
        << " 2) Look at Top of Linked List" << endl
        << " 3) Pop from linked list" << endl
        << " 4) Quit" << endl << endl
        << " User: ";

    cin >> menuIn;            // User input for menu options

    cout << endl;

    switch (menuIn)
    {
    case 1:               // Lets the user add values to the linked list
        chains.printList();
        cout << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(chains);
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
    case 2:               // Lets the user load an existing save file
        cout << " Top Element: " << chains.getFirst() << endl << endl;
        cout << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(chains);
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

    case 3:               // Lets the user change the color of the user interface
        chains.removeLast();
        chains.printList();
        cout << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(chains);
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
        break;

    default:
        system("CLS");
        linkedMenu(chains);
        break;
    }
}
