#include "range.h"

Range::Range(size_t start, size_t end) : start(start), end(end) {
  this->inclusive = false;
};

Range::Range(size_t start, size_t end, bool inclusive)
    : start(start), end(end), inclusive(inclusive){};

void Range::for_each(std::function<void(size_t)> f) {
  size_t end = this->inclusive ? this->end + 1 : this->end;
  for (size_t i = this->start; i < end; i++)
    f(i);
}
