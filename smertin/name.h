#ifndef NAME_H
#define NAME_H

#include <string>
#include <iostream>

class Name {
public:
	Name() = default;
	explicit Name(const std::string& first);
	Name(const std::string& first, const std::string& surname);
	Name(const std::string& first, const std::string& surname, const std::string& patronymic);

	std::string ToString() const;
	void Print() const;

	bool HasSurname() const;
	bool HasPatronymic() const;

	void SetSurname(const std::string& surname);
	void SetPatronymic(const std::string& patronymic);

	const std::string& GetFirstName() const;
	const std::string& GetSurname() const;
	const std::string& GetPatronymic() const;

private:
	std::string first_name_;
	std::string surname_;
	std::string patronymic_;
};

#endif  // NAME_H
