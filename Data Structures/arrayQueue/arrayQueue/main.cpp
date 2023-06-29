#include <iostream>
#include <iomanip>
#include "myQueue.h"

using namespace std;

void linkedMenu(myQueue);

int main()
{
    myQueue haloLobby;
    haloLobby.initializeQueue();
    haloLobby.setList();
    linkedMenu(haloLobby);

    return 0;
}

void linkedMenu(myQueue haloLobby)
{
    int menuIn;
    char option;
    int num;

    cout << " Welcome. From the following enter the corresponding number for that option." << endl
        << " 1) Print Queue" << endl
        << " 2) Look at Front and Back of Queue" << endl
        << " 3) Add to Queue" << endl
        << " 4) Delete from Queue" << endl
        << " 5) Quit" << endl << endl
        << " User: ";
    cin >> menuIn;
    cout << endl;

    switch (menuIn)
    {
    case 1:
        haloLobby.printQueue();
        cout << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(haloLobby);
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
        cout << " Front Element: " << haloLobby.front() << endl << endl;
        cout << " Rear Element: " << haloLobby.back() << endl << endl;
        cout << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(haloLobby);
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
        cout << " Enter linked value: ";
        cin >> num;
        cout << endl;
        haloLobby.addQueue(num);
        haloLobby.printQueue();
        cout << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(haloLobby);
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
        haloLobby.deleteQueue();
        haloLobby.printQueue();
        cout << " Do you wish to continue? Enter Y or N: ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            system("CLS");
            linkedMenu(haloLobby);
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
        linkedMenu(haloLobby);
        break;
    }
}

