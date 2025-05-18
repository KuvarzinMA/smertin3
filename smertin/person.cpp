#include "person.h"

Person::Person(const std::string& name_str, int height)
    : name_(Name(name_str)), height_(height) {
}

Person::Person(const std::string& name_str, int height, std::shared_ptr<Person> father)
    : name_(Name(name_str)), height_(height), father_(std::move(father)) {
    UpdateNameFromFather();
}

Person::Person(const Name& name, int height)
    : name_(name), height_(height) {
}

Person::Person(Name name, int height, std::shared_ptr<Person> father)
    : name_(name), height_(height), father_(std::move(father)) {
    UpdateNameFromFather();
}

void Person::UpdateNameFromFather() {
    if (father_) {
        if (!name_.HasSurname() && father_->name_.HasSurname()) {
            name_.SetSurname(father_->name_.GetSurname());
        }
        if (!name_.HasPatronymic() && !father_->name_.GetFirstName().empty()) {
            name_.SetPatronymic(father_->name_.GetFirstName() + "ович");
        }
    }
}

std::string Person::ToString() const {
    return name_.ToString() + ", рост " + std::to_string(height_);
}
