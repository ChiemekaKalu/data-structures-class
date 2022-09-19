/*
 * llclass2.hpp
 *
 *  Created on: Sep 14, 2022
 *      Author: chiemekakalu
 */

#ifndef LLCLASS2_HPP_
#define LLCLASS2_HPP_

#include "student.hpp"
template<class Object>
struct LLnode
{
	LLnode * fwdptr;
	Object theData;
	LLnode * prevptr;
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

	// Recursive push back
	void push_back(Object obj)
	{
		push_back_helper(obj, header); // Call helper function
	}

	void push_back_helper(Object obj, LLnode<Object> * & temp) 
	{
		if(temp == nullptr) // Base Case
		{
			LLnode<Object> * newNode = new LLnode<Object>;
			newNode->theData.key = obj.key;
			newNode->theData.data = obj.data;
			newNode->fwdptr = nullptr;
			temp = newNode;
		}
		else
		{
			push_back_helper(obj, temp->fwdptr);
		}
	}



	int recursiveList_length(LLnode<Object> * current)
	{
		if(current == nullptr)
		{
			return 0;
		}
		else
		{
			return 1 + recursiveList_length(current->fwdptr);
		}
	}


	int list_length()
	{
		return recursiveList_length(header);
	}

	void recursiveDestroy_List(LLnode<Object> * current)
	{
		if(current != nullptr)
		{
			recursiveDestroy_List(current->fwdptr);
			delete current;
		}
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

	Object search_list(int key)
	{
		LLnode<Object> returnvalue;
		LLnode<Object> * temp = header;
		while(temp != nullptr)
		{							// Traverses the list looking for a matching key
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
		LLnode<Object> * temp = header;
		recursiveDestroy_List(temp);
		header = nullptr;
	}

	bool delete_nodeRecursive(int key, LLnode<Object> * & current) // Helper for delete node
	{
		if(current == nullptr) // Base Case 
		{
			return false;
		}
		else if(current->theData.key == key) // If the key is found
		{
			LLnode<Object> * temp2 = current;
			current = current->fwdptr; // Changing this changes the location of the pointer of the last node
			delete temp2; // Deleting
			return true;
		}
		else
		{
			return delete_nodeRecursive(key, current->fwdptr); // Recursive 
		}
	}


	bool delete_node(int key)
	{ 
		return delete_nodeRecursive(key, header);
	}



};



#endif /* LLCLASS2_HPP_ */
