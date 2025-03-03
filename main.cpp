#include <format>

import demo;

int main() {
  auto lang = "C++";
  auto s = std::format("Hello and welcome to {}", lang);
  demo::emit(std::format("Hello and welcome to {}", lang));

  for (int i = 1; i <= 5; i++) {
    demo::emit(std::format("i = {}", i));
  }

  return 0;
}
