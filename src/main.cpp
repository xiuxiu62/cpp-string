#include "string.h"
#include <memory>

int main() {
  std::unique_ptr<String> temp_1 = std::make_unique<String>();
  std::unique_ptr<String> temp_2 = std::make_unique<String>("asdfasdf");

  temp_1->push_str("hello ");
  temp_1->push_str("world");
  temp_1->push('!');
  temp_1->push('!');
  temp_1->pop();

  temp_2->push_str(
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

  temp_1->debug();
  temp_2->debug();

  return 0;
}
