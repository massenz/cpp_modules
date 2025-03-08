//
// Created by Marco Massenzio on 2/25/25.
//
module;

#include <iostream>

export module demo;

export namespace demo {
  template<typename T>
  concept Printable = requires(T t)
  {
    std::cout << t;
  };

  /**
   * Once we have printed all arguments, we just emit a newline.
   */
  void emit(std::ostream &out) {
    out << std::endl;
  }

  /**
   * Writes out an arbitrary number of arguments to the output stream.
   * Uses "tail recursion" to print each argument in the list.
   */
  template<Printable T, Printable... Tail>
  void emit(std::ostream &out, const T &first, Tail... tail) {
    out << first;
    emit(out, tail...);
  }

  /**
   * If the output stream is not specified, we simply emit to console.
   */
  template<Printable T, Printable... Tail>
  void emit(const T &head, Tail... tail) {
    emit(std::cout, head, tail...);
  }

} // namespace demo
