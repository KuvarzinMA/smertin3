#ifndef CITY_H
#define CITY_H

#include <string>
#include <vector>
#include <utility>

class City {
public:
	explicit City(const std::string& name);
	void AddPath(City* destination, int cost);
	std::string ToString() const;

private:
	std::string name_;
	std::vector<std::pair<City*, int>> paths_;
};

#endif  // CITY_H
