#include "stdafx.h"
#include "HashTable_BL.h"


HashTable_BL::HashTable_BL(int value)
{
	tableSize = value;
	HashArray = new Item* [tableSize];

	Item* it = new Item;

	it->key = "Empty";
	it->value = "Empty";
	it->pNext = NULL;

	for (int i = 0; i < tableSize; i++)
	{
		HashArray[i] = it;
	}

}



int HashTable_BL::Hash(string value)
{
	int index, hash = 0;

	for (int i = 0; i < value.length(); i++)
	{
		hash += (int)value[i];
	}

	index = hash % tableSize;

	return index;
}

void HashTable_BL::Insert(string key,string value)
{
	int index = Hash(key);

	Item* pIt = new Item;

	pIt->key = key;
	pIt->value = value;
	pIt->pNext = NULL;
	if (count < tableSize)
	{
		if (HashArray[index]->key == "Empty")
		{
			HashArray[index] = pIt;
			++count;
		}
		else
		{
			Item* ptrItem = HashArray[index];
			Item* newItem = new Item;

			newItem->key = key;
			newItem->value = value;
			newItem->pNext = NULL;


			while (ptrItem->pNext != NULL)
			{
				ptrItem = ptrItem->pNext;
			}

			ptrItem->pNext = newItem;
			/*++count;*/
		}
	}
	else
	{
		cout << "Sorry, but you cann't add elements, because you filled free cels.\n";
		system("pause");
	}
}

void HashTable_BL::GetElement(string key)
{
	int index = Hash(key);

	Item* ptr = HashArray[index];

	if (ptr->key == "Empty")
	{
		cout << "Empty index in hashtable." << endl;
	}
	else
	{
		cout << key << " contains: " << endl;

		cout << "----------------------\n";
		while (ptr != NULL)
		{
			cout << ptr->value << " |";;
			ptr = ptr->pNext;
		}
		cout << "\n";
		cout << "----------------------\n";
	}
}

void HashTable_BL::DeleteElement(string key)
{
	int index = Hash(key);

	Item* ptr1;
	Item* ptr2;

	if (HashArray[index]->key == "Empty" && HashArray[index]->value == "Empty")
	{
		cout << key << " was not found in hash table." << endl;
	}
	else if (HashArray[index]->key == key && HashArray[index]->pNext == NULL)
	{
		HashArray[index]->key = "Empty";
		HashArray[index]->value = "Empty";
		count--;

		cout << key << " was removed from hash table\n";
	}
	else if (HashArray[index]->key == key)
	{
		Item* delPtr = HashArray[index];
		HashArray[index] = HashArray[index]->pNext;
		delete delPtr;
		count--;

		cout << key << " was removed from hash table\n";
	}
	else
	{
		ptr1 = HashArray[index]->pNext;
		ptr2 = HashArray[index];

		while (ptr1 != NULL && ptr1->key != key)
		{
			ptr2 = ptr1;
			ptr1 = ptr1->pNext;
		}

		if (ptr1 == NULL)
		{
			cout << key << " was not found in hash table." << endl;
		}
		else
		{
			Item* delPtr = ptr1;
			ptr1 = ptr1->pNext;
			ptr2->pNext = ptr1;

			delete delPtr;

			count--;
			cout << key << " was removed from hash table\n";
		}

	}
}

void HashTable_BL::ShowTable()
{
	for (int i = 0; i < tableSize; i++)
	{
		cout << "Key: " << HashArray[i]->key << endl;
		cout << "Value(s): " << HashArray[i]->value;

		if (HashArray[i]->pNext != NULL)
		{
			Item* pIt = HashArray[i]->pNext;

			while (pIt != NULL)
			{
				cout << "| " + pIt->value + " ";

				pIt = pIt->pNext;
			}
		}
		cout << endl;

	}
}

void HashTable_BL::ClearTable()
{
	for (int i = 0; i < tableSize; i++)
	{
		Item* pIt = new Item;
		pIt->key = "Empty";
		pIt->value = "Empty";
		pIt->pNext = NULL;

		if (HashArray[i]->pNext != NULL)
		{
			Item* pt = HashArray[i]->pNext;
			while (pt != NULL)
			{
				Item* delPtr = pt;
				pt = pt->pNext;

				delete delPtr;
			}
			HashArray[i] = pIt;
		}
		else
		{
			HashArray[i] = pIt;
		}
		
	}
	count = 0;
}

double HashTable_BL::PersentOfTableFill()
{
	return  (double)count / (double)tableSize;
}



HashTable_BL::~HashTable_BL()
{
	ClearTable();

	delete HashArray;
}
