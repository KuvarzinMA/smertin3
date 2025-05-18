#ifndef CAT_H
#define CAT_H

#include <string>

class Cat {
public:
	explicit Cat(const std::string& name);
	void Meow() const;
	void Meow(int count) const;
	std::string ToString() const;

private:
	std::string name_;
};

#endif  // CAT_H
