#pragma once
#include <iostream>
#include <string>

using namespace std;


struct Item
{
	string key;
	string value;
	Item* pNext;
};

class HashTable_BL
{
public:
	HashTable_BL(int value);

	int Hash(string value);
	void Insert(string key,string value);
	void GetElement(string key);
	void DeleteElement(string key);
	void ShowTable();
	void ClearTable();
	double PersentOfTableFill();

	~HashTable_BL();
private:
	int tableSize;
	int count = 0;
	Item** HashArray;
};

