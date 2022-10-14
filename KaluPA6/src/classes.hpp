/*
 * classes.hpp
 *
 *  Created on: Oct 10, 2022
 *      Author: chiemekakalu
 */

#ifndef CLASSES_HPP_
#define CLASSES_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <cmath>
#include <cstdlib>
using namespace std;


struct EmployeeData 
{
	string ID;
	string name;

	EmployeeData()
	{
		ID = "0";
		name = "";
	}
};


template<class Object>
struct LLnode
{
	LLnode * fwdptr;
	Object theData;
};


template<class Object>
class LL
{
private:

	LLnode<Object> * header;

public:
	LL()
	{
		header = nullptr;
	}

	void push_front(Object obj)
	{
		LLnode<Object> * newNode = new LLnode<Object>; // Create new node
		newNode->theData.key = obj.key;
		newNode->theData.data = obj.data;
		newNode->fwdptr = header;
		header = newNode;
	}

	bool is_empty()
	{
		if(header == nullptr)
		{
			return true;
		}
		return false;
	}

	void push_back(Object obj)
	{
		LLnode<Object> * newNode = new LLnode<Object>;
		newNode->theData.ID = obj.ID;
		newNode->theData.name = obj.name;
		newNode->fwdptr = nullptr;
		LLnode<Object> * temp = header;
		if(temp != nullptr) // If the list has anything in it, traverse to the end
		{
			while(temp->fwdptr != nullptr)
			{
				temp = temp->fwdptr;
			}
			temp->fwdptr = newNode; // Last node now points at the new node
		}
		else
		{
			header = newNode; // Nothing is in it then the header just points to the new node
		}
	}

	int list_length()
	{
		LLnode<Object> * temp = header;
		int count = 0;

		while(temp != nullptr)
		{
			count++;
			temp = temp->fwdptr;
		}
		return count;
	}

	Object retrieve_front()
	{
		return header->theData;
	}

	Object retrieve_back()
	{
		LLnode<Object> * temp = header;
		while(temp->fwdptr != nullptr)
		{
			temp = temp->fwdptr;
		}
		return temp->theData;
	}

	void display_list()
	{
		int count = 0;
		LLnode<Object> * temp = header;
		while(temp != nullptr)
		{
			cout << temp->theData.name << " ";
			cout << temp->theData.ID << endl;
			count++;

			temp = temp->fwdptr;
		}
	}

	bool delete_node(int key)
	{
		LLnode<Object> * current = header;
		LLnode<Object> * prev = nullptr;

		// We can only start traversing and deleting stuff if the list isn't empty.

		while(current != nullptr) // While it isn't the end of the linked list
		{
			if(current->theData.key == key)
			{
				if(prev == nullptr) // This handles the case of it being the first node
				{
					header = current->fwdptr;
					delete current;
					return true;
				}
				else if(current->fwdptr == nullptr) // This handles the case of it being the last node
				{
					prev->fwdptr = nullptr;
					delete current;
					return true;
				}
				else // This handles it being in the middle
				{
					prev->fwdptr = current->fwdptr;
					delete current;
					return true;
				}

			}

			prev = current;			// Keeping the previous node pointer accurate
			current = current->fwdptr; // Advances the traversal
		}

		return false; // End of the list (target not found), or the list is empty.

	}

	Object search_list(string ID)
	{
		LLnode<Object> returnvalue;
		LLnode<Object> * temp = header;
		while(temp != nullptr)
		{											// Traverses the list looking for a matching key
			if(temp->theData.ID == ID)
			{
				returnvalue.theData.ID = temp->theData.ID;
				returnvalue.theData.name = temp->theData.name;
				return returnvalue.theData;
			}
			temp = temp->fwdptr;
		}
		if(temp == nullptr) // If it hits the end of the list it should return false
		{
			returnvalue.theData.ID = "-0";
			returnvalue.theData.name = "";
			return returnvalue.theData;
		}
	}

	void destroy_list()
	{
		LLnode<Object> * current = header;
		LLnode<Object> * next = nullptr;
		while(current != nullptr)					// Takes the location of the next from the current, deletes the current, makes the new current the location of the next
		{
			next = current->fwdptr;
			delete current;
			current = next;
		}
		header = nullptr;
	}



};

struct EmployeeHash
{
	EmployeeData data;
	LL<EmployeeData> collisions;
	int counter = 0;
};

int hashFunction(string ID)
{
	int hash = 0;
	for (int i = 0; i < ID.length(); i++)
	{
		hash += ID[i];
	}


	hash = hash + 48 * 3939;

	for(int i = 0; i < ID.length(); i++)
	{
		hash += abs(ID[i] * ID[3] * ID[2] * ID[1]);
	}


	return hash % 160;
}



/*
positions 0 – 9  employee ID -- 9 characters:  three alpha followed by six numeric 
 positions 10-19 employee first name 
 positions 20-34 employee last name 
 */






#endif /* CLASSES_HPP_ */
