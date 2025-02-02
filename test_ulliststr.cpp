#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"


//Use this file to test your ulliststr implementation before running the test suite

void printList(ULListStr& list) {
  for (size_t i = 0; i < list.size(); i++) {
    std::cout <<list.get(i) << " ";
  }
  std::cout << std::endl;
}


int main(int argc, char* argv[]) {
  ULListStr list;

  // Test push_back
  std::cout << "Testing push_back:" << std::endl;
  list.push_back("one");
  list.push_back("two");
  list.push_back("three");
  printList(list);

  // Test push_front
  std::cout << "Testing push_front:" << std::endl;
  list.push_front("zero");
  list.push_front("minus_one");
  printList(list);  

  // Test pop_back
  std::cout << "Testing pop_back:" << std::endl;
  list.pop_back();
  printList(list);  

  // Test pop_front
  std::cout << "Testing pop_front:" << std::endl;
  list.pop_front();
  printList(list);  

  // Test front() and back()
  std::cout << "Front element: " << list.front() << std::endl;  
  std::cout << "Back element: " << list.back() << std::endl;  

  // Test clearing the list
  std::cout << "Clearing the list:" << std::endl;
  list.pop_back();
  list.pop_back();
  list.pop_back();
  std::cout << "List size after clearing: " << list.size() << std::endl;

  // Test pushing after clearing
  std::cout << "Pushing new values after clearing:" << std::endl;
  list.push_back("new_one");
  list.push_front("new_zero");
  printList(list);

  return 0;
}
