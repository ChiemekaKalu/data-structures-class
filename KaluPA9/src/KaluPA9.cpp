//============================================================================
// Name        : KaluPA9.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "A9.hpp"


/*
Don't know if I'll have a chance to leave a note on the final but seeing as this is the last assignment i'll put something here
this was an extremely fun two semesters with you and i'm glad i picked you as a professor because i learned a lot and had a
great time while doing so. If only you taught cs21 I would have taken it with you aswell.

This semester of cs20 was probably my favorite class I've taken at las positas while being one of the most challenging because
the material is hard to conceptually understand but your lectures made it a lot easier. I've never been taught anything 
by somebody who had a more personal and relatable approach to the mateiral than you. 

I'm glad we got to exchange some jokes and slang of different times and I hope our row didnt annoy you too much.

- Chiemeka 
*/

// Adjacency Matrix Print Function
// Tons of warnings from the use of auto because I was too lazy to make an iterator even though auto just literally creates an iterator

void printMatrix(int** matrix, int size)
{
	for(int i = 0; i < size; i++)
	{

		for(int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

// DFT Function
void dftInternal(vector<Vertex> graph, int vertex, bool visited[])
{
	cout << vertex << " ";
	visited[vertex] = true;
	for(auto i = graph[vertex].neighbor.begin(); i != graph[vertex].neighbor.end(); i++)
	{
		if(!visited[*i]) // *i is a vertex from auto because i was too lazy to make an interator and it has to be dereferenced because im making an iterator with auto anyway
		{
			dftInternal(graph, *i, visited); // travel down the neighbor list basically, and if the vertex hasnt been visited, visit it by putting it into the internal function
		}
	}
}

void dft(vector<Vertex> graph)
{
	bool visited[graph.size()];
	for(int i = 0; i < graph.size(); i++)
	{
		visited[i] = false;
	}
	int current = 0;
	while(current < graph.size())
	{
		if(visited[current] == false) 
		{
			dftInternal(graph, current, visited);
		}
		current++;
	}

}





// BFT Function
void BreadthFirstTraversal(vector<Vertex> graph) // Function that does BFT and prints each vertex
{
	int size = graph.size();

	bool visited[size];
	for(int i = 0; i < size; i++)
	{
		visited[i] = false; // Initialize all vertices to not visited
	}
	queue<int> q;
	
	for(int i = 0; i < size; i++)
	{
		if(visited[i] == false)
		{
			visited[i] = true;
			q.push(i);
			while(!q.empty())
			{
				int vertex = q.front(); // vertex to print is the front of the queue
				q.pop(); // pop the front 
				cout << vertex << " "; 
				for(auto it = graph[vertex].neighbor.begin(); it != graph[vertex].neighbor.end(); it++) // iterate through the neighborhood
				{
					if(visited[*it] == false) // if the vertex in the neighbors list has not been visited
					{
						visited[*it] = true; 
						q.push(*it); 
						// Mark it as visited and push it into the q
					}
				}
			}
		}
	}  



}







int main() {

	fstream inFile;
	fstream numFile;
	int numVertexs;
	vector<Vertex> adjList;
	string neighbor;
	Vertex temp;
	int vertexValue;
	string unable = "Unable to open file";

	numFile.open("/Users/chiemekakalu/Downloads/A9F2022.ini");

	if(!numFile)
	{
		throw(unable);
	}

	numFile >> numVertexs;

	inFile.open("/Users/chiemekakalu/Downloads/A9data.txt");

	if (!inFile)
	{
		throw(unable);
	}


	while(inFile >> vertexValue) // Grabs first number and puts it as the vertex
	{
		temp.vertexValue = vertexValue;
		inFile >> neighbor;
		while(neighbor != "-1") // Grabs next numbers until it is -1;
		{
			temp.neighbor.push_back(stoi(neighbor)); // Convert and pushes it into the list in the temp object
			inFile >> neighbor; // Grabs next number
		}

		adjList.push_back(temp); // Pushes temp vertex into the vector
		temp.neighbor.clear(); // Clears the temp's list of neighbors
	}


	// Display of Adjacency list
	for(auto i = adjList.begin(); i != adjList.end(); i++)
	{
		cout << "Vertex " << i->vertexValue << " ";
		cout << "neighbors: ";
		for(auto j = i->neighbor.begin(); j != i->neighbor.end(); j++)
		{
			cout << *j << " ";
		}
		cout << endl;
	}

	// Adj Matrix Creation
	int ** matrix;
	int ROWS = numVertexs;
	int COLS = numVertexs;
	matrix = new int * [ROWS];

	for(int i = 0; i < ROWS; i++)
	{
		matrix[i] = new int[COLS];
	}


	cout << endl;
	
	
	cout << "Adjacency Matrix" << endl;
	// Populate Adjacency Matrix
	for(int i = 0; i < numVertexs; i++)
	{
		for(int j = 0; j < numVertexs; j++)
		{
			for(auto k = adjList[i].neighbor.begin(); k != adjList[i].neighbor.end(); k++)
			{
				if(*k == j)
				{
					matrix[i][j] = 1;
				}
			}
		}
	}

	// Print Adjacency Matrix
	printMatrix(matrix, numVertexs);

	cout << endl; cout << endl;

	// Breadth First Traversal
	cout << "Breadth First Traversal: ";
	BreadthFirstTraversal(adjList);

	// Depth First Traversal
	cout << endl << "Depth First Traversal: ";
	dft(adjList);


// Closing files.
	numFile.close();
	inFile.close();

// Clean up Matrix
	for(int i =0; i < ROWS; i++)
	{
		delete [] matrix[i];
	}


	return 0;
}
