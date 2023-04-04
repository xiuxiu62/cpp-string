#include "string.h"
#include "range.h"
#include <functional>
#include <iostream>
#include <string.h>

template <typename T> inline void panic(T message) {
  std::cerr << "Panic: " << message << std::endl;
  exit(1);
}

int round_up_by(int value, int by);

String::String() {
  size_t capacity = 64;
  // this->data = std::malloc(capacity * sizeof(char));
  this->data = new char[capacity];
  *this->data = 0;

  this->size = 0;
  this->capacity = capacity;
}

String::String(const char *str) {
  size_t len = strlen(str);
  size_t capacity = round_up_by(len, 64);
  if (len % 64 == 0)
    capacity += 64;

  // this->data = std::malloc(capacity * sizeof(char));
  char *buffer = new char[capacity];
  memcpy(buffer, str, len);
  this->data = buffer;
  this->data[len] = 0;

  this->size = len;
  this->capacity = capacity;
}

void String::push(const char value) {
  // resize if necessary
  if (this->size + 1 >= this->capacity)
    this->resize_by(64);

  this->data[this->size] = value;
  this->data[this->size + 1] = 0;

  this->size += 1;
}

void String::push_str(const char *value) {
  int len = strlen(value);

  // resize if necessary
  int overflow = this->size + len - this->capacity;
  if (overflow > 0)
    this->resize_by(round_up_by(overflow, 64));
  else if (overflow == 0)
    this->resize_by(64);

  memcpy((void *)(this->data + this->size), value, len);
  this->data[this->size + len] = 0;

  this->size += len;
}

char String::pop() {
  if (this->size == 0)
    panic("attempted to remove item from empty String");

  char *addr = this->data + this->size - 1;
  char c = *addr;

  *addr = 0;
  this->size -= 1;

  return c;
}

void String::resize_by(int by) {
  size_t offset = this->capacity;
  this->capacity += by;
  this->data = static_cast<char *>(
      realloc(static_cast<void *>(this->data), this->capacity));
}

void String::display() { std::cout << this->data << std::endl; }

void String::debug() {
  std::cout << std::endl << "data: " << this->data << std::endl;
  std::cout << "size: " << this->size << std::endl;
  std::cout << "capacity: " << this->capacity << std::endl;
}

int round_up_by(int value, int by) {
  return value % by == 0 ? value : value / by * by + by;
}

// int main() {
//   String *temp = new String();

//   temp->push_str("hello ");
//   temp->push_str("world");
//   temp->push('!');
//   temp->push('!');
//   temp->pop();

//   temp->debug();

//   delete temp;

//   return 0;
// }
