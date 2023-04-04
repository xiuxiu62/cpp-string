#pragma once

#include <memory>

struct String {
  char *data;
  size_t size;
  size_t capacity;

  String();
  String(const char *str);

  void push(const char value);
  void push_str(const char *value);
  char pop();
  void resize_by(int by);
  void display();
  void debug();
};
