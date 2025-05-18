#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <memory>
#include "name.h"

class Person {
public:
	Person(const std::string& name_str, int height);
	Person(const std::string& name_str, int height, std::shared_ptr<Person> father);
	Person(const Name& name, int height);
	Person(Name name, int height, std::shared_ptr<Person> father);

	std::string ToString() const;

private:
	Name name_;
	int height_;
	std::shared_ptr<Person> father_;
	void UpdateNameFromFather();
};

#endif  // PERSON_H
