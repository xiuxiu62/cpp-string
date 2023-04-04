#pragma once

#include <cstddef>
#include <functional>

struct Range {
  size_t start;
  size_t end;
  bool inclusive;

  Range(size_t start, size_t end);
  Range(size_t start, size_t end, bool inclusive);

  void for_each(std::function<void(size_t)>);
};
