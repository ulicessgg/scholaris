#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
#include <map>
#include <set>
using namespace std;
struct card
{
	string suit;
	string face;
};
void cardGuess();
void encryptFile();
void decryptFile();
void uniqueWords();
void runMenu();
int main()
{
	runMenu();
	return 0;
}
void cardGuess()
{
	vector<card> deckOfCards(52);
	string type[4] = { "Clubs", "Diamonds", "Hearts", "Spades" };
	string title[13] = { "Ace", "Two", "Three", "Four", "Five",
	"Six", "Seven", "Eight", "Nine",
	"Ten", "Jack", "Queen", "King", };
	int j = 0;
	int k = 0;
	for (size_t i = 0; i < deckOfCards.size(); i++)
	{
		if (i == 13 || i == 26 || i == 39)
		{
			j++;
			k = 0;
		}
		deckOfCards[i].suit = type[j];
		deckOfCards[i].face = title[k];
		k++;
	}
	srand((unsigned)time(0));
	int randomShuffles = rand() % 12 + 1;
	int randomPick = rand() % 51;
	int randomCard = randomPick;
	string faceGuess;
	string suitGuess;
	string correctFace;
	string correctSuit;
	int menuIn;
	char option;
	cout << " 1) Guess Face" << endl
		<< " 2) Guess Suit" << endl
		<< " 3) Guess Face & Suit" << endl
		<< " 4) Quit" << endl << endl
		<< " User: ";
	cin >> menuIn;
	cout << endl;
	switch (menuIn)
	{
	case 1:
		for (int i = 0; i < randomShuffles; i++)
		{
			random_shuffle(deckOfCards.begin(), deckOfCards.end());
		}
		correctFace = deckOfCards[randomCard].face;
		correctSuit = deckOfCards[randomCard].suit;
		cout << " Enter Guess of Face: ";
		cin >> faceGuess;
		cout << endl;
		if (correctFace == faceGuess)
		{
			cout << " You are correct!" << endl << endl;
		}
		else
		{
			cout << " You are incorrect." << endl << endl;
		}
		cout << " CORRECT CARD: " << correctFace << " of " << correctSuit << endl << endl;
		cout << " Do you wish to continue? Enter Y or N: ";
		cin >> option;
		if (option == 'Y' || option == 'y')
		{
			system("CLS");
			cardGuess();
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
		for (int i = 0; i < randomShuffles; i++)
		{
			random_shuffle(deckOfCards.begin(), deckOfCards.end());
		}
		correctFace = deckOfCards[randomCard].face;
		correctSuit = deckOfCards[randomCard].suit;
		cout << " Enter Guess of Suit: ";
		cin >> suitGuess;
		cout << endl;
		if (correctSuit == suitGuess)
		{
			cout << " You are correct!" << endl << endl;
		}
		else
		{
			cout << " You are incorrect." << endl << endl;
		}
		cout << " CORRECT CARD: " << correctFace << " of " << correctSuit << endl << endl;
		cout << " Do you wish to continue? Enter Y or N: ";
		cin >> option;
		if (option == 'Y' || option == 'y')
		{
			system("CLS");
			cardGuess();
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
		for (int i = 0; i < randomShuffles; i++)
		{
			random_shuffle(deckOfCards.begin(), deckOfCards.end());
		}
		correctFace = deckOfCards[randomCard].face;
		correctSuit = deckOfCards[randomCard].suit;
		cout << " Enter Guess of Face: ";
		cin >> faceGuess;
		cout << " Enter Guess of Suit: ";
		cin >> suitGuess;
		cout << endl;
		if (correctFace == faceGuess && correctSuit == suitGuess)
		{
			cout << " You are correct!" << endl << endl;
		}
		else if (correctFace == faceGuess && correctSuit != suitGuess)
		{
			cout << " Your guess of face is correct! But your guess of suit is incorrect" << endl << endl;
		}
		else if (correctFace != faceGuess && correctSuit == suitGuess)
		{
			cout << " Your guess of face is incorrect. But your guess of suit is correct!" << endl << endl;
		}
		else
		{
			cout << " You are incorrect." << endl << endl;
		}
		cout << " CORRECT CARD: " << correctFace << " of " << correctSuit << endl << endl;
		cout << " Do you wish to continue? Enter Y or N: ";
		cin >> option;
		if (option == 'Y' || option == 'y')
		{
			system("CLS");
			cardGuess();
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
		cardGuess();
		break;
	}
}
void encryptFile()
{
	char x;
	map <char, char> cypher = { {'A', '%'},{'a', '9'}, {'B', '@'}, {'b', '#'},
	{'C', '5'},{'c', '/'}, {'D', '?'}, {'d', '6'},
	{'E', '!'},{'e', '$'}, {'F', '&'}, {'f', '0'},
	{'G', '*'},{'g', '|'}, {'H', ';'}, {'h', ':'},
	{'I', '3'},{'i', '+'}, {'J', '='}, {'j', '-'},
	{'K', '_'},{'k', '2'}, {'L', ')'}, {'l', '('},
	{'M', '^'},{'m', '}'}, {'N', '{'}, {'n', ']'},
	{'O', '['},{'o', '"'}, {'P', ','}, {'p', '>'},
	{'Q', '1'},{'q', '<'}, {'R', '.'}, {'r', 'S'},
	{'S', '`'},{'s', '~'}, {'T', '4'}, {'t', 'J'},
	{'U', 'g'},{'u', 'c'}, {'V', 'G'}, {'v', 's'},
	{'W', 'j'},{'w', '7'}, {'X', 'U'}, {'x', 'C'},
	{'Y', '8'},{'y', 'u'}, {'Z', 'o'}, {'z', '\\'} };
	map <char, char>::iterator i;
	fstream encrypted;
	fstream decrypted;
	decrypted.open("input.txt", ios::in);
	encrypted.open("output.txt", ios::out);
	cout << " Encrypted: ";
	while (decrypted.get(x))
	{
		i = cypher.find(x);
		encrypted << i->second;
		cout << i->second;
	}
	encrypted.close();
	decrypted.close();
}
void decryptFile()
{
	char y;
	map <char, char> key = { {'%', 'A'},{'9', 'a'}, {'@', 'B'}, {'#', 'b'},
	{'5', 'C'},{'/', 'c'}, {'?', 'D'}, {'6', 'd'},
	{'!', 'E'},{'$', 'e'}, {'&', 'F'}, {'0', 'f'},
	{'*', 'G'},{'|', 'g'}, {';', 'H'}, {':', 'h'},
	{'3', 'I'},{'+', 'i'}, {'=', 'J'}, {'-', 'j'},
	{'_', 'K'},{'2', 'k'}, {')', 'L'}, {'(', 'l'},
	{'^', 'M'},{'}', 'm'}, {'{', 'N'}, {']', 'n'},
	{'[', 'O'},{'"', 'o'}, {',', 'P'}, {'S', 'r'},
	{'`', 'S'},{'~', 's'}, {'4', 'T'}, {'J', 't'},
	{'g', 'U'},{'c', 'u'}, {'G', 'V'}, {'s', 'v'},
	{'j', 'W'},{'7', 'w'}, {'U', 'X'}, {'C', 'x'},
	{'8', 'Y'},{'u', 'y'}, {'o', 'Z'}, {'\\', 'z'} };
	map <char, char>::iterator i;
	fstream decrypted;
	fstream encrypted;
	encrypted.open("output.txt", ios::in);
	decrypted.open("output2.txt", ios::out);
	cout << " Decrypted: ";
	while (encrypted.get(y))
	{
		i = key.find(y);
		decrypted << i->second;
		cout << i->second;
	}
	decrypted.close();
	encrypted.close();
}
void uniqueWords()
{
	set<string> uniqueSet;
	set<string>::iterator word;
	fstream vocabulary;
	string temp;
	int i = 0;
	vocabulary.open("input2.txt", ios::in);
	while (getline(vocabulary, temp))
	{
		uniqueSet.insert(temp);
	}
	for (word = uniqueSet.begin(); word != uniqueSet.end(); word++)
	{
		cout << " Unique Word " << i + 1 << ": " << *word << endl;
		i++;
	}
}
void runMenu()
{
	int menuIn;
	char option;
	cout << " 1) Run Card Guess Program" << endl
		<< " 2) Run File Encryption Program" << endl
		<< " 3) Run File Decryption Program" << endl
		<< " 4) Run Unique Word Print Program" << endl
		<< " 5) Quit" << endl << endl
		<< " User: ";
	cin >> menuIn;
	cout << endl;
	switch (menuIn)
	{
	case 1:
		cardGuess();
		cout << endl << endl;
		cout << " Do you wish to continue? Enter Y or N: ";
		cin >> option;
		if (option == 'Y' || option == 'y')
		{
			system("CLS");
			runMenu();
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
		encryptFile();
		cout << endl << endl;
		cout << " Do you wish to continue? Enter Y or N: ";
		cin >> option;
		if (option == 'Y' || option == 'y')
		{
			system("CLS");
			runMenu();
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
		decryptFile();
		cout << endl << endl;
		cout << " Do you wish to continue? Enter Y or N: ";
		cin >> option;
		if (option == 'Y' || option == 'y')
		{
			system("CLS");
			runMenu();
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
		uniqueWords();
		cout << endl;
		cout << " Do you wish to continue? Enter Y or N: ";
		cin >> option;
		if (option == 'Y' || option == 'y')
		{
			system("CLS");
			runMenu();
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
		runMenu();
		break;
	}
}