#include "city.h"
#include <sstream>

City::City(const std::string& name) : name_(name) {}

void City::AddPath(City* destination, int cost) {
    paths_.emplace_back(destination, cost);
}

std::string City::ToString() const {
    std::ostringstream oss;
    oss << name_ << " — пути:";
    for (const auto& path : paths_) {
        oss << " " << path.first->name_ << ":" << path.second;
    }
    return oss.str();
}
