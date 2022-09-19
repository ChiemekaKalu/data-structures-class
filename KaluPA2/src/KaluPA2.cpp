//============================================================================
// Name        : KaluPA2.cpp
// Author      : Chiemeka
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


// Templated class for linked list, every object passed in is going to contain int "key" and string "data"
// Other than that no issue

// For delete keep track of current and previous pointer and put the next pointer in the previous pointer


#include "llclass.hpp"
#include "student.hpp"

int main() {
// A2 main test pgm 3 - use for submission
// cout << "Before making object" << endl;
LL <Student> ll1;
cout << "main: length of empty list - " << ll1.list_length() << endl;
ll1.display_list();
Student temp;
temp.data = "aaaaa";
temp.key = 12345;
// cout << "After making student object, before push" << endl;
ll1.push_front(temp);
temp.data = "bbbbb";
temp.key = 23456;
ll1.push_back(temp);
temp.data = "before aaaaa";
temp.key = 34567;
ll1.push_front(temp);
temp.data = "after bbbbb";
temp.key = 45678;
ll1.push_back(temp);
cout << "main: length of list after 4 pushes - " << ll1.list_length() << endl;
ll1.display_list();
cout << endl;
temp = ll1.search_list (23456);
if (temp.key != 0)
cout << "main: node with key 23456 found" << endl;
else
cout << "main: node with key 23456 not found - that's an error" << endl;
temp = ll1.search_list (23457);
if (temp.key != 0)
cout << "main: node with key 23457 found - that's an error" << endl;
else
cout << "main: node with key 23457 not found" << endl;
bool b;
b = ll1.delete_node (23456);
if (b)
cout << "main: node with key 23456 deleted" << endl;
else
cout << "main: node with key 23456 not deleted - that's an error" << endl;
cout << "main: length of list after delete - " << ll1.list_length() << endl;
cout << "main: display of list after delete" << endl;
ll1.display_list();
ll1.destroy_list();
cout << "main: length of list after destroy - " << ll1.list_length() << endl;
cout << "main: display of list after destroy" << endl;
ll1.display_list();
cout << endl;
return 0;
}
