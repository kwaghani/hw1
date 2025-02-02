#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val) {
    if (!tail_) { // If list is empty, create first node
        tail_ = new Item();
        head_ = tail_;
    }
    
    if (tail_->last < ARRSIZE) { // Space available in current tail node
        tail_->val[tail_->last] = val;
        tail_->last++;
    } else { // No space, create a new node
        Item* newNode = new Item();
        newNode->val[0] = val;
        newNode->last = 1;
        newNode->prev = tail_;
        tail_->next = newNode;
        tail_ = newNode;
    }
    size_++;
}

// COMPLETE
void ULListStr::pop_back() {
    if (!tail_) return; // List is empty

    tail_->last--; // Remove last element

    if (tail_->first == tail_->last) { // If node is now empty, delete it
        Item* temp = tail_;
        tail_ = tail_->prev;

        if (tail_) {
            tail_->next = nullptr;
        } else {
            head_ = nullptr; // List is now empty
        }

        delete temp;
    }
    size_--;
}

void ULListStr::push_front(const std::string& val) {
    if (!head_) { // If list is empty, create first node
        head_ = new Item();
        tail_ = head_;
        head_->val[0] = val;
        head_->first = 0;
        head_->last = 1;
    } else if (head_->first > 0) { // Space available before first element
        head_->first--;
        head_->val[head_->first] = val;
    } else { // No space, create new head node
        Item* newNode = new Item();
        newNode->last = ARRSIZE;
        newNode->first = ARRSIZE - 1;
        newNode->val[newNode->first] = val;
        newNode->next = head_;
        head_->prev = newNode;
        head_ = newNode;
    }
    size_++;
}

void ULListStr::pop_front() {
    if (!head_) return; // List is empty

    head_->first++; // Remove first element

    if (head_->first == head_->last) { // If node is now empty, delete it
        Item* temp = head_;
        head_ = head_->next;

        if (head_) {
            head_->prev = nullptr;
        } else {
            tail_ = nullptr; // List is now empty
        }

        delete temp;
    }
    size_--;
}

std::string const& ULListStr::back() const {
  if (!tail_)
  {
    throw std::out_of_range("List is empty");
  }
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  if (!head_)
  {
    throw std::out_of_range("List is empty");
  }
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (loc >= size_) return NULL;

  Item* current = head_;
  size_t index = loc;

  while (current)
  {
    size_t numElements = current->last - current->first;
    if (index < numElements)
    {
      return &current->val[current->first + index];
    }
    index -= numElements;
    current = current->next;
  }
  
  return NULL;
}

// END OF COMPLETE SECTION

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
