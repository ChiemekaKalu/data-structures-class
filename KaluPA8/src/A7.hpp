/*
 * A7.hpp
 *
 *  Created on: Nov 3, 2022
 *      Author: chiemekakalu
 */

#ifndef A7_HPP_
#define A7_HPP_

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
string emptree = "Error - Tree is empty";

template <class T> 
struct Tnode 
{ 
 int balance;
 T nodeValue; 
 Tnode <T> * Lchild; 
 Tnode <T> * Rchild; 
}; 

template <class T>
class BSTree
{
private:
    Tnode <T> * root;

public: 

BSTree ()
{
    root = nullptr;
}


bool searchR(T & key){
	if (root == nullptr)
	{
		throw(emptree);
	}
	else
	{
		return searchRInternal(root, key);
	}
}

bool searchRInternal(Tnode<T> * p, T & key){
	if(p == nullptr)
	{
		return false;
	}
	if(p->nodeValue == key)
	{
		return true;
	}
	else
	{
		if(p->nodeValue < key)
		{
			return searchRInternal(p->Rchild, key);
		}
		else
		{
			return searchRInternal(p->Lchild, key);
		}
	}
}

void insertR(T  insertkey)
{
	if(root == nullptr)
	{
		Tnode<T> * newNode = new Tnode<T>;
		newNode->nodeValue = insertkey;
		newNode->Lchild = nullptr;
		newNode->Rchild = nullptr;
		root = newNode;
	}
	else
	{
		root = insertRInternal(root, insertkey);
	}

}

Tnode <T> * insertRInternal(Tnode <T> * & p, T & insertkey)
{
	if(p->nodeValue > insertkey)
	{
		if(p->Lchild == nullptr)
		{
			Tnode<T> * newNode = new Tnode<T>;
			newNode->nodeValue = insertkey;
			p->Lchild = newNode;
			newNode->Lchild = nullptr;
			newNode->Rchild = nullptr;
		}
		else
		{
			p->Lchild = insertRInternal(p->Lchild, insertkey);
		}
	}
	else
	{
		if(p->nodeValue < insertkey)
		{
			if(p->Rchild == nullptr)
			{
				Tnode<T> * newNode = new Tnode<T>;
				newNode->nodeValue = insertkey;
				p->Rchild = newNode;
				newNode->Lchild = nullptr;
				newNode->Rchild = nullptr;
			}
			else
			{
				p->Rchild = insertRInternal(p->Rchild, insertkey);
			}
		}
		else
		{
			string duplicate = "Error - Duplicate";
			throw(duplicate);
		}
	}

	return p;
}


void udelete (const T & delkey)   // Calls udeleteInternal with pointer to node to be deleted
{
	string error2 = "You tried to delete an empty tree";
   bool found = false;
   if(root == nullptr)
   {
	   throw(error2);
   }
   else
   {
	   Tnode<T> * current = root;
	   Tnode<T> * parent = root;
	   while(current != nullptr and !found)
	   {
		   if(current->nodeValue == delkey)
		   {
			   found = true;
		   }
		   else
		   {
			   parent = current;
			   if(current->nodeValue > delkey)
			   {
				   current = current->Lchild;
			   }
			   else
			   {
				   current = current->Rchild;
			   }
		   }
	   }
	   if(current == nullptr)
	   {
		   cout << "Not found" << endl;
		   return;
	   }
	   else
	   {
		   if(current == root)
		   {
			   udeleteInternal(root);
		   }
		   else if(parent->nodeValue > delkey)
		   {
			   udeleteInternal(parent->Lchild);
		   }
		   else
		   {
			   udeleteInternal(parent->Rchild);
		   }
	   }

   }

}


	void printRohitWithBF(){		// pjh orig width=3 gap=5
	const int WIDTH = 7;		//must be greater than the max characters printed per node; for example, if printing 2 digit numbers, WIDTH should be >= 3
	const int GAP = 4;			//gap between each node
	int height = this->height();
	string lines[height+1];

	//generates a string for each level of the tree
	for(int i=1; i<=height+1; i++){
		string line;
		printRohitWithBFLevel(root, i, i, height, line, WIDTH);
		lines[i-1] = line;
	}

	//removes the unnecessary spaces from the lines
	int space = 0;
	bool allSpace;
	for(unsigned int i=0; i<lines[0].length()-1; i++){	// pjh mod goes until length()-1 from length()
		allSpace = true;
		for(string line: lines){
			if(line.at(i) != ' '){
				allSpace = false;
			}
		}
		if(allSpace){		//every line has a space at this index
			space += 1;
		}
		else{
			if(space > GAP){		//the space is too long and must be reduced to GAP
				for(string& line: lines){
					line.erase(i-space, space-GAP);
				}
				i-= (space-GAP);
			}
			else if(space < GAP && space>0){		//the space is too small and must be expanded to GAP
				string spaces;
				for(int j=0; j< (GAP-space); j++){
					spaces += " ";
				}
				for(string& line: lines){
					line.insert(i-space, spaces);
				}
				i += (GAP-space);
			}
			space = 0;
		}
	}

	//prints out each line
	for(string line: lines){
		cout << line << endl << endl << endl;
	}
}  


void inOrderTraversal ()
{
    inOrderTraversalRecursive(root);
    cout << endl;
}

void preOrderTraversal ()
{
    preOrderTraversalRecursive(root);
    cout << endl;
}

void postOrderTraversal () 
{
    postOrderTraversalRecursive(root);
    cout << endl;
}

int height ()
{
    return heightInternal(root);  
}

void setallBF()
{
	setallBFInternal(root);
}


void setallBFInternal(Tnode<T> * p)
{	
	if(p != nullptr)
	{
		int left = heightInternal(p->Lchild);
		int right = heightInternal(p->Rchild);
		p->balance = right - left;
		setallBFInternal(p->Lchild);
		setallBFInternal(p->Rchild);
		return;
	}
	else
	{
		return;
	}
}

int getLargestBF()
{
	return getLargestBFInternal(root);
}

int getLargestBFInternal(Tnode<T> * p)
{
	if(p != nullptr)
	{
		int left = getLargestBFInternal(p->Lchild);
		int right = getLargestBFInternal(p->Rchild);

		if(abs(p->balance) > abs(left))
		{
			left = p->balance;
		}
		else if(abs(p->balance) > abs(right))
		{
			right = p->balance;
		}

		if(abs(left) > abs(right))
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		return 0;
	}
}



private:   

int heightInternal (Tnode<T> * node)
{
    if (node != nullptr)
    {
        int leftHeight = heightInternal(node->Lchild);
        int rightHeight = heightInternal(node->Rchild);
        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
        	return rightHeight + 1;
        }

    }
    else
    {
        return -1;
    }
}

void udeleteInternal (Tnode<T> * & toBeDeleted)
{
    // Case 1: Node to be deleted is a leaf
    if (toBeDeleted->Lchild == nullptr && toBeDeleted->Rchild == nullptr)
    {
    	delete toBeDeleted;
    	toBeDeleted = nullptr;
        return;
    }
    // Case 2: Node to be deleted has only a left subtree
    else if (toBeDeleted->Lchild != nullptr && toBeDeleted->Rchild == nullptr)
    {
        Tnode<T> * temp = toBeDeleted;
        toBeDeleted = toBeDeleted->Lchild;
        delete temp;
        return;
    }
    // Case 3: Node to be deleted has only a right subtree
    else if (toBeDeleted->Lchild == nullptr && toBeDeleted->Rchild != nullptr)
    {
        Tnode<T> * temp = toBeDeleted;
        toBeDeleted = toBeDeleted->Rchild;
        delete temp;
        return;
    }
    // Case 4: Node to be deleted has both a left and right subtree
    else
    {
        // Adjust key - find node with highest key that's not greater than the key of the node to be deleted
        Tnode<T> * temp = toBeDeleted->Lchild;
        while (temp->Rchild != nullptr)
        {
            temp = temp->Rchild;
        }
        toBeDeleted->nodeValue = temp->nodeValue;

        // Adjust subtree
        // if the left child was already the rightmost
        if (temp == toBeDeleted->Lchild)
        {
            toBeDeleted->Lchild = temp->Lchild;
            delete temp;
            return;
        }
        // if the left child was not the rightmost
        else
        {
            Tnode<T> * temp2 = toBeDeleted->Lchild;
            while (temp2->Rchild != temp)
            {
                temp2 = temp2->Rchild;
            }
            temp2->Rchild = temp->Lchild;
            delete temp;
            return;
        }

    }

}
void inOrderTraversalRecursive (Tnode<T> * root)
{
    if (root != nullptr)
    {
        inOrderTraversalRecursive(root->Lchild);
        cout << root->nodeValue << " ";
        inOrderTraversalRecursive(root->Rchild);
    }

}

void preOrderTraversalRecursive (Tnode<T> * root)
{
    if (root != nullptr)
    {
        cout << root->nodeValue << " ";
        preOrderTraversalRecursive(root->Lchild);
        preOrderTraversalRecursive(root->Rchild);
    }
}

void postOrderTraversalRecursive (Tnode<T> * root)
{
    if (root != nullptr)
    {
        postOrderTraversalRecursive(root->Lchild);
        postOrderTraversalRecursive(root->Rchild);
        cout << root->nodeValue << " ";
    }
}

void printRohitWithBFLevel(Tnode<T>* node, int x, int level, int height, string& print, const int WIDTH)
{

	if(node == nullptr){		//this node is empty so generates enough spaces based on which level the node is located on in relation to the level that must be printed and the height of the tree
		for(int i=0; i< WIDTH*pow(2,height+1-level+x); i++)
			print+= " ";
	}
	else if(x == 1){		//the node is on the right level
		for(int i=0; i< WIDTH*(pow(2,height+1-level)); i++)		//space to print before node
			print+= " ";
		int val = node->nodeValue;
		string value = to_string(val);
		print+= value;
		int bal = node->balance;				// start pjh mods
		string baln = to_string (bal);
		print+= "(";
		print+= baln;
		print+= ")";							// end pjh mods
		for(unsigned int i=0; i< (WIDTH-value.length()); i++)		//if the width of the node is less than WIDTH, prints spaces
			print+= " ";
		for(int i=0; i< WIDTH*(pow(2,height+1-level)-1); i++)		//space to print after node
			print+= " ";
	}
	else
	{
		printRohitWithBFLevel(node->Lchild, x-1, level, height, print, WIDTH);
		printRohitWithBFLevel(node->Rchild, x-1, level, height, print, WIDTH);

	}
}
};







#endif /* A7_HPP_ */

