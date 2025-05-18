#include "name.h"

Name::Name(const std::string& first) : first_name_(first) {}

Name::Name(const std::string& first, const std::string& surname)
    : first_name_(first), surname_(surname) {
}

Name::Name(const std::string& first, const std::string& surname, const std::string& patronymic)
    : first_name_(first), surname_(surname), patronymic_(patronymic) {
}

std::string Name::ToString() const {
    std::string result;
    if (!surname_.empty()) result += surname_;
    if (!first_name_.empty()) result += (result.empty() ? "" : " ") + first_name_;
    if (!patronymic_.empty()) result += (result.empty() ? "" : " ") + patronymic_;
    return result;
}

void Name::Print() const {
    std::cout << ToString() << std::endl;
}

bool Name::HasSurname() const {
    return !surname_.empty();
}

bool Name::HasPatronymic() const {
    return !patronymic_.empty();
}

void Name::SetSurname(const std::string& surname) {
    surname_ = surname;
}

void Name::SetPatronymic(const std::string& patronymic) {
    patronymic_ = patronymic;
}

const std::string& Name::GetFirstName() const {
    return first_name_;
}

const std::string& Name::GetSurname() const {
    return surname_;
}

const std::string& Name::GetPatronymic() const {
    return patronymic_;
}
