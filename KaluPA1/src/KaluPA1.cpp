//============================================================================
// Name        : KaluPA1.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct Student
{
	string studentName;
	int studentID;
};


struct LLnode
{
	LLnode * fwdptr;
	Student theData;
};

void push_front(LLnode *& llh, Student s)
{
	LLnode * newNode = new LLnode;
	newNode->theData = s;
	LLnode * temp = llh;
	llh = newNode;
	llh->fwdptr = temp;
}

void push_back(LLnode *& llh, Student s)
{
	LLnode * newNode = new LLnode;
	newNode->theData = s;
	newNode->fwdptr = nullptr;
	LLnode * temp = llh;
	if(temp != nullptr){
		while(temp->fwdptr != nullptr)
		{
			temp = temp->fwdptr;
		}
		temp->fwdptr = newNode;
	}
	else
	{
		llh = newNode;
	}

}

int list_length(LLnode *& llh)
{
	int count = 0;
	LLnode * temp = llh;
	while(temp != nullptr)
	{
		count++;
		temp = temp->fwdptr;
	}
	return count;
}

Student retrieve_front(LLnode *& llh)
{
	string except = "List empty";
	if(llh != nullptr)
	{
		return llh->theData;
	}
	else
	{
		throw except;
	}
}

Student retrieve_back(LLnode * llh)
{
	if(llh != nullptr)
	{
		LLnode * temp = llh;
		while(temp->fwdptr != nullptr)
		{
			temp = temp->fwdptr;
		}

		return temp->theData;
	}
	else
	{
		cout << "List empty" << endl;
	}
}

void display_nodes(LLnode * llh)
{
	LLnode * temp = llh;
	int count = 0;
	while(temp != nullptr)
	{
		cout << "Node " << count << " address: " << temp << " data: " << temp->theData.studentName << " " << temp->theData.studentID << endl;
		count++;
		temp = temp->fwdptr;
	}
}

int main()
{
LLnode * theLLHeader1 = nullptr;
Student temp;
temp.studentName = "student1";
temp.studentID = 11111;
cout << "Main:  number of nodes in empty list " <<
list_length(theLLHeader1) << endl;
cout << "Main:  contents of LL1 nodes" << endl;
display_nodes(theLLHeader1);
push_front (theLLHeader1, temp);
cout << "Main:  number of nodes in list after 1 push - " <<
list_length(theLLHeader1) << endl;
cout << "Main:  contents of list after 1 push " << endl;
display_nodes(theLLHeader1);
temp.studentName = "student2";
temp.studentID = 22222;
push_back (theLLHeader1, temp);
temp.studentName = "student3";
temp.studentID = 33333;
push_front (theLLHeader1, temp);
temp.studentName = "student4";
temp.studentID = 44444;
push_back (theLLHeader1, temp);
cout << "Main:  number of nodes after 4 pushes - " <<
list_length(theLLHeader1) << endl;
cout << "Main:  contents of list after 4 pushes " << endl;
display_nodes (theLLHeader1);
temp = retrieve_front(theLLHeader1);
cout << "Main:  retrieve front: " << temp.studentName << " " <<
temp.studentID << endl;
temp = retrieve_back(theLLHeader1);
cout << "Main:  retrieve back: " << temp.studentName << " " <<
temp.studentID << endl;
cout << endl;
LLnode * theLLHeader2 = nullptr;
temp.studentName = "Adam";
temp.studentID = 15555;
push_front (theLLHeader2, temp);
temp.studentName = "Betty";
temp.studentID = 25555;
push_front (theLLHeader2, temp);
temp.studentName = "Charlie";
temp.studentID = 35555;
push_front (theLLHeader2, temp);
temp.studentName = "Donna";
temp.studentID = 45555;
push_back (theLLHeader2, temp);
temp.studentName = "Earnie";
temp.studentID = 55555;
push_back (theLLHeader2, temp);
temp.studentName = "Felicity";
temp.studentID = 65555;
push_back (theLLHeader2, temp);
cout << "Main:  contents of LL2 nodes" << endl;
display_nodes (theLLHeader2);
return 0;
}
