#include "cat.h"
#include <iostream>

Cat::Cat(const std::string& name) : name_(name) {}

void Cat::Meow() const {
    std::cout << name_ << ": мяу!" << std::endl;
}

void Cat::Meow(int count) const {
    std::cout << name_ << ": ";
    for (int i = 0; i < count; ++i) {
        std::cout << "мяу";
        if (i < count - 1) std::cout << "-";
    }
    std::cout << "!" << std::endl;
}

std::string Cat::ToString() const {
    return "кот: " + name_;
}
