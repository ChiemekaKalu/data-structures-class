//============================================================================
// Name        : KaluPA3.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int fibb(int n){
	
	// cout << "N is " << n << endl;

	if(n==1)
	{
		return 0;
	}
	else if(n==2)
	{
		return 1;
	}

	else
	{
		return fibb(n-1)+fibb(n-2);
	}
}

int pow(int x, int y)
{
	if(y==0)
	{
		return 1;
	}
	else
	{
		return x*pow(x,y-1); 
	}
}

int sum(int array[], int size)
{

	if(size==0)
	{
		return 0;
	}
	else
	{
		return array[size-1]+sum(array,size-1); // Returns and calls the function again and adds the last element to the sum
	}
}

int countOccurrences(string s)
{
	if(s.length()==0)
	{
		return 0;
	}
	else
	{
		if(s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u' || s[0]=='y') // Checks a Vowel
		{
			return countOccurrences(s.substr(1)) + 1;
		}
		else
		{
			return countOccurrences(s.substr(1)); // Returns the rest of the string without the first character
		}
	}
	
}

string reverseString(string s)
{
	if(s.length()==0)
	{
		return ""; // return empty string
	}
	else
	{
		return s[s.length()-1] + reverseString(s.substr(0,s.length()-1)); // return last character + reverseString of the rest of the string
	}


}  


int main() {
cout << "********** first 10 fibonacci numbers **********" << endl;
for (int i=1; i<=10; i++)
{
	cout << setw (6) << fibb(i);
}
cout << endl << "********** end of fibonacci test **********" << 
endl;
cout << endl << endl;
cout << "3 to the 4th is " << pow (3, 4) << endl;
cout << "5 to the 1st is " << pow (5, 1) << endl;
cout << endl << endl;
int array[5] = {5,4,3,2,1};
cout << "sum of entire array is " << sum (array, 5) << endl;
cout << "sum of first element only is " << sum (array, 1) << endl;
cout << "sum of first three elements is " << sum (array, 3) << endl;
cout << endl << endl;
string s = "now is the time for each good person";
cout << "number of vowels is " << countOccurrences (s) << endl;
s = "aeiouy";
cout << "number of vowels is " << countOccurrences (s) << endl;
s = "bcd";
cout << "number of vowels is " << countOccurrences (s) << endl;
cout << endl << endl;
cout << "reverse of " << s << " is " << reverseString (s) << endl;
s = "abcd";
cout << "reverse of " << s << " is " << reverseString (s) << endl;



return 0;
}
