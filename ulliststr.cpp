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
  if (!tail_ || tail_ -> last == ARRSIZE) { // no tail / node is full
    Item* newItem = new Item();
    if (!tail_) {
      head_ = newItem;
      tail_ = newItem;
    } 
    else {
      tail_ -> next = newItem;
      newItem -> prev = tail_;
      tail_ = newItem;
    }
  }
  
  tail_ -> val[tail_ -> last] = val;
  tail_ -> last++;
  size_++;
}

// COMPLETE
void ULListStr::pop_back() {
  if (!tail_) return; // Nothing to remove

  tail_->last--;

  if (tail_->first == tail_->last) // If item is empty, remove it
  {
    Item* temp = tail_;
    if (tail_ == head_) // If only one node exists
    {
      head_ = NULL;
      tail_ = NULL;
    }
    else
    {
      tail_ = tail_->prev;
      tail_->next = NULL;
    }
    delete temp;
  }
  size_--;
}

void ULListStr::push_front(const std::string& val) {
  if (!head_ || head_->first == 0) // No head or first item is full at the front
  {
    Item* newItem = new Item();
    newItem->first = ARRSIZE; // Start from last position
    if (!head_) // First node in list
    {
      head_ = newItem;
      tail_ = newItem;
    }
    else
    {
      newItem->next = head_;
      head_->prev = newItem;
      head_ = newItem;
    }
  }

  head_->first--;
  head_->val[head_->first] = val;
  size_++;
}

void ULListStr::pop_front() {
  if (!head_) return; // Nothing to remove

  head_->first++;

  if (head_->first == head_->last) // If item is empty, remove it
  {
    Item* temp = head_;
    if (head_ == tail_) // If only one node exists
    {
      head_ = NULL;
      tail_ = NULL;
    }
    else
    {
      head_ = head_->next;
      head_->prev = NULL;
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
