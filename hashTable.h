#pragma once
#include"user.h"
#include<cassert>

/*
The hashTableStatus function is a helper function that initializes an
array called indexStatusList to store the status of each index in the hash table (0 for empty, 1 for occupied).
It also initializes a length variable to 0 and takes an integer as input, which represents the size of the hash table.
*/

int* indexStatusList;
int length;

void hashTableStatus(int size)
{
	assert(size > 0);
	length = 0;
	indexStatusList = new int[size];
	for (int i = 0; i < size; i++)
		indexStatusList[i] = 0;
}


/*
The manuelDeleteHashTableStatus function is a helper function that deallocates the memory occupied by indexStatusList.
*/
void manuelDeleteHashTableStatus()
{
	delete[] indexStatusList;
}

/*
The insertUserId function takes an array of user objects, an integer representing the index in the hash table where the user object should be inserted,
the size of the hash table, and a constant reference to an integer as input. It attempts to insert the user object into the hash table at the specified index.
If the index is already occupied by another user object or if the table is full, it displays an error message. If the insertion is successful, it increments the length variable.
*/
void insertUserId(user* arr, int hashIndex, int size, const int& rec)
{
	int pCount;
	int inc;

	pCount = 0;
	inc = 1;

	while (indexStatusList[hashIndex] != 0
		&& arr[hashIndex].getUserId() != rec
		&& pCount < size / 2)
	{
		pCount++;
		hashIndex = (hashIndex + inc) % 35953;
		inc = inc + 2;
	}

	if (indexStatusList[hashIndex] != 1)
	{
		arr[hashIndex].setUserId(rec);
		indexStatusList[hashIndex] = 1;
		length++;
	}
	else if (arr[hashIndex].getUserId() == rec)
		cerr << "Error: No duplicates are allowed" << endl;

	else
		cerr << "Error: The table is full. "
		<< "Unable to resolve the collision" << endl;
}

/*
The searchUserId function takes an array of user objects, a reference to an integer representing the index in the hash table where the user object is being searched for,
the size of the hash table, a constant reference to an integer, and a reference to a boolean as input. It searches the hash table for a user object with a userId value
that matches the input integer. If it finds such an object, it updates
*/

void searchUserId(user arr[], int& hashIndex, int size, const int& rec, bool& found)
{
	int pCount;
	int inc;

	pCount = 0;
	inc = 1;

	while (indexStatusList[hashIndex] != 0
		&& arr[hashIndex].getUserId() != rec
		&& pCount < size / 2)
	{
		pCount++;
		hashIndex = (hashIndex + inc) % 35953;
		inc = inc + 2;
	}

	if (indexStatusList[hashIndex] == 1 && arr[hashIndex].getUserId() == rec)
	{
		hashIndex = hashIndex;
		found = true;
	}
	else
		found = false;
}

