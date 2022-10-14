//============================================================================
// Name        : KaluPA6.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "classes.hpp"

/*
positions 0 – 9  employee ID -- 9 characters:  three alpha followed by six numeric 
 positions 10-19 employee first name 
 positions 20-34 employee last name 
 */

int main()
{

	EmployeeHash hashTable[160]; //create hash table

	EmployeeData filler;
	filler.ID = "0";
	filler.name = "";

	for(int i = 0; i < 160; i++)
	{
		EmployeeData temp;
		temp.ID = "0";
		temp.name = "";
		hashTable[i].data = temp;

	}

	fstream file;
	file.open("/Users/chiemekakalu/Downloads/a6data.txt"); //open file
	string line = "";


	if(file.is_open())
	{
		getline(file, line);
		while(!file.eof())
		{
			EmployeeData data;
			data.ID = line.substr(0,9);
			data.name = line.substr(9,30);

			if(hashTable[hashFunction(data.ID)].data.ID == "0")
			{
				hashTable[hashFunction(data.ID)].data = data;
				hashTable[hashFunction(data.ID)].counter += 1;
			}
			else
			{
				hashTable[hashFunction(data.ID)].collisions.push_back(data);
				hashTable[hashFunction(data.ID)].counter += 1;
			}

			getline(file, line);
		}
	}

	float average = 0;
	float sum = 0;
	float chainCounter = 0;

	for(int i = 0; i < 160; i++)
	{
		if(hashTable[i].counter > 1)
		{
			sum += hashTable[i].counter;
			chainCounter++;
		}

	}
	average = sum / chainCounter;


	cout << "Display of Employees" << endl;

	for(int i = 0; i < 160; i++){

		cout << "For Hash Table Entry " << i << endl;
		if(hashTable[i].data.ID == "0")
		{
			cout << "No Data for entry" << i << endl;
		}
		if(hashTable[i].collisions.is_empty())
		{
			cout << "No chain for this entry " << endl;
		}
		else if(hashTable[i].data.ID != "0")
		{
			cout << hashTable[i].data.name << " ";
			cout << hashTable[i].data.ID << endl;
			if(!hashTable[i].collisions.is_empty())
			{
				cout << "---Chain Entries--- " << "for " << i<< endl;
				hashTable[i].collisions.display_list();
				cout << endl;
			}
		}
	}

	int totalEmployees = 0;
	for(int i = 0; i < 160; i++)
	{
		totalEmployees += hashTable[i].counter;
	}

	cout << endl;

	int zeroes = 0;
	int ones = 0;
	int onePlus = 0;

	for(int i = 0; i < 160; i++){

		if(hashTable[i].counter == 0)
		{
			zeroes++;
		}
		if(hashTable[i].counter == 1)
		{
			ones++;
		}
		if(hashTable[i].counter > 1)
		{
			onePlus++;
		}

	}
	cout << "*************** HASH STATS ***************" << endl;
	cout << "Entries with zero items " << zeroes << endl;
	cout << "Entries with one item " << ones << endl;
	cout << "Entries with more than one item " << onePlus << endl;
	cout << "Average chain length " << average << endl;
	cout << "There are " << totalEmployees << " total employees" << endl;
	cout << "*************** ENTERING SEARCH ***************" << endl;
	cout << endl;


	string search = "";
	cout << "Enter a key to search for enter 0 to stop" << endl;
	getline(cin, search);


	while(search != "0")
	{
		if(hashTable[hashFunction(search)].data.ID == search)
		{
			cout << "Entry is found" << endl;
			cout << hashTable[hashFunction(search)].data.name << " ";
			cout << hashTable[hashFunction(search)].data.ID << endl;
			cout << "Enter a key to search for enter 0 to stop" << endl;
			getline(cin, search);
		}
		else if(hashTable[hashFunction(search)].data.ID != search && hashTable[hashFunction(search)].counter > 1)
		{
			EmployeeData searchDummy = hashTable[hashFunction(search)].collisions.search_list(search);

			if(searchDummy.ID == "-0")
			{
				cout << "Not found" << endl;
			}
			else
			{
				cout << "Found in chain" << endl;
				cout << searchDummy.ID << " ";
				cout << searchDummy.name << endl;
				cout << "Enter a key to search for enter 0 to stop" << endl;
				getline(cin, search);

			}
		}
		else
		{
			cout << "NOT FOUND" << endl;
			cout << "Enter a key to search for enter 0 to stop" << endl;
			getline(cin, search);
		}

	}


	for(int i = 0; i < 160; i++)
	{

		hashTable[i].collisions.destroy_list();
	}


	cout << "MEMORY CLEARED. GOODBYE." << endl;


	return 0;

}
