/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using namespace std;

// Helper function to print a linked list
void printList(Node* head) {
  while (head) {
    cout << head->value << " -> ";
    head = head->next;
  }
  cout << "NULL" << endl;
}

// Helper function to create a linked list from an initializer list
Node* createList(const initializer_list<int>& values) {
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int val : values) {
      Node* newNode = new Node(val, nullptr);
      if (!head) {
        head = newNode;
      } 
      else {
        tail->next = newNode;
      }
      tail = newNode;
    }
    return head;
}

// Helper function to delete a linked list (free memory)
void deleteList(Node*& head) {
  while (head) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}


int main(int argc, char* argv[])
{
  // Test Case 1: Empty List
  Node* in1 = nullptr;
  Node* odds1 = nullptr;
  Node* evens1 = nullptr;
  split(in1, odds1, evens1);
  cout << "Test 1 - Empty List" << endl;
  printList(odds1);
  printList(evens1);

  // Test Case 2: All Even Numbers
  Node* in2 = createList({2, 4, 6, 8});
  Node* odds2 = nullptr;
  Node* evens2 = nullptr;
  split(in2, odds2, evens2);
  cout << "Test 2 - All Even Numbers" << endl;
  printList(odds2);
  printList(evens2);
  deleteList(odds2);
  deleteList(evens2);

  // Test Case 3: All Odd Numbers
  Node* in3 = createList({1, 3, 5, 7});
  Node* odds3 = nullptr;
  Node* evens3 = nullptr;
  split(in3, odds3, evens3);
  cout << "Test 3 - All Odd Numbers" << endl;
  printList(odds3);
  printList(evens3);
  deleteList(odds3);
  deleteList(evens3);

  // Test Case 4: Mixed Numbers
  Node* in4 = createList({1, 2, 3, 4, 5, 6});
  Node* odds4 = nullptr;
  Node* evens4 = nullptr;
  split(in4, odds4, evens4);
  cout << "Test 4 - Mixed Numbers" << endl;
  printList(odds4);
  printList(evens4);
  deleteList(odds4);
  deleteList(evens4);

  // Test Case 5: Single Even Number
  Node* in5 = createList({8});
  Node* odds5 = nullptr;
  Node* evens5 = nullptr;
  split(in5, odds5, evens5);
  cout << "Test 5 - Single Even Number" << endl;
  printList(odds5);
  printList(evens5);
  deleteList(odds5);
  deleteList(evens5);

  // Test Case 6: Single Odd Number
  Node* in6 = createList({9});
  Node* odds6 = nullptr;
  Node* evens6 = nullptr;
  split(in6, odds6, evens6);
  cout << "Test 6 - Single Odd Number" << endl;
  printList(odds6);
  printList(evens6);
  deleteList(odds6);
  deleteList(evens6);

  // Test Case 7: Duplicate Numbers
  Node* in7 = createList({2, 2, 2, 3, 3, 3});
  Node* odds7 = nullptr;
  Node* evens7 = nullptr;
  split(in7, odds7, evens7);
  cout << "Test 7 - Duplicate Numbers" << endl;
  printList(odds7);
  printList(evens7);
  deleteList(odds7);
  deleteList(evens7);

  return 0;

}
