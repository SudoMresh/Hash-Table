

#include "stdafx.h"
#include <iostream>
#include <string>
#include "HashTable_BL.h"


using namespace std;



int main()
{
	string key, value;
	char exit = 'l';
	int answer;

	cout << "\t\t\t HASH TABLE\n\n";
	cout << "Please, enter amount of hash table array.\n";

	cin >> answer;

	if (answer < 0)
	{
		cout << "Please, enter the right value.\n";
		cin >> answer;
	}

	HashTable_BL hash(answer);

	system("cls");
	
	while (exit != 'q')
	{
		cout << "1. Add element to hash table." << endl;
		cout << "2. Search element(s) by key." << endl;
		cout << "3. Delete element by key." << endl;
		cout << "4. Show the percentage fill in table." << endl;
		cout << "5. Clear table." << endl;
		cout << "6. Show table." << endl;
		cout << "If you want to exit, please enter q." << endl;

		cin >> exit;

		switch (exit)
		{
		case '1':
			cout << "Enter key: \n";
			cin >> key;
			cout << "Enter value: \n";
			cin >> value;

			hash.Insert(key, value);
			break;
		case '2':
			cout << "Enter key: \n";
			cin >> key;

			hash.GetElement(key);
			system("pause");
			break;
		case '3':
			cout << "Enter key: \n";
			cin >> key;

			hash.DeleteElement(key);
			break;
		case '4':
			cout << hash.PersentOfTableFill() << endl;
			system("pause");
			break;
		case '5':
			cout << "Clearing the table....\n";
			hash.ClearTable();
			break;
		case '6':
			hash.ShowTable();
			system("pause");
			break;
		default:
			break;
		}

		system("cls");
	}
    return 0;
}

