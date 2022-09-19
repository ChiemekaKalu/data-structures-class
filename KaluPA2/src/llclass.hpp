/*
 * llclass.hpp
 *
 *  Created on: Aug 31, 2022
 *      Author: chiemekakalu
 */

#ifndef LLCLASS_HPP_
#define LLCLASS_HPP_

#include "student.hpp"
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

	void push_back(Object obj)
	{
	LLnode<Object> * newNode = new LLnode<Object>;
	newNode->theData.key = obj.key;
	newNode->theData.data = obj.data;
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
			cout << "Node " << count << " data: " << temp->theData.data << " key " << temp->theData.key << endl;
			count++;
			temp = temp->fwdptr;
		}
	}

	bool delete_node(int key)
	{
		LLnode<Object> * current = header;
		LLnode<Object> * prev = nullptr;
		
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

		return false; // If we hit the end of the list it should return false
	}

	Object search_list(int key)
	{
		LLnode<Object> returnvalue;
		LLnode<Object> * temp = header;
		while(temp != nullptr)
		{											// Traverses the list looking for a matching key
			if(temp->theData.key == key)
			{
				returnvalue.theData.key = temp->theData.key;
				returnvalue.theData.data = temp->theData.data;
				return returnvalue.theData;
			}
			temp = temp->fwdptr;
		}
		if(temp == nullptr) // If it hits the end of the list it should return false
		{
			returnvalue.theData.key = -0;
			returnvalue.theData.data = "";
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



#endif /* LLCLASS_HPP_ */
