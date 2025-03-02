//
// Created by Marco Massenzio on 2/25/25.
//
module;
#include <iostream>

export module demo;

export namespace demo {
    void emit(const std::string& msg) {
        std::cout << msg << std::endl;
    }
}
