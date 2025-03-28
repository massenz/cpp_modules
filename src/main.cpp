#include <fstream>
#include <string>

import demo;

using namespace std::literals;
using namespace demo;

int main() {
  const auto lang = "C++"s;
  constexpr auto version = 20;

  // Here we can use values of different types, and the variadic
  // template will take care of the rest.
  emit("Hello and welcome to ", lang, version, " modules"s);

  for (int i = 1; i <= 5; i++) {
    emit("i = ", i);
  }

  // Using emit to write out to a file instead of the console.
  std::ofstream outFile("output.txt");
  emit(outFile, "Writing to a file:\n", "Using modules: ", "demo"s);

  return 0;
}
