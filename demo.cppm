//
// Created by Marco Massenzio on 2/25/25.
//
module;

#include <iostream>

export module demo;

export namespace demo {

    template<typename T>
    concept Printable = requires(T t) {
      std::cout << t;
    };

    void emit() {
      std::cout << std::endl;
    }

    template<Printable T, Printable... Tail>
    void emit(const T &head, Tail... tail) {
      std::cout << head;
      emit(tail...);
    }

} // namespace demo
