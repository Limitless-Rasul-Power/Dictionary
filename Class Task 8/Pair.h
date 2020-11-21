#pragma once
#include <string>
class Pair
{

private:
	std::string key;
	std::string value;

public:

	Pair();

	Pair(const Pair& other);

	Pair& operator = (const Pair& other);

	Pair& operator = (const std::string& value);

	explicit inline Pair(const std::string& key);

	Pair(const std::string& key, const std::string& value);

	void Set_key(const std::string& key);
	std::string Get_key() const;

	void Set_value(const std::string& value);
	std::string Get_value() const;

	friend std::ostream& operator << (std::ostream& out, const Pair& pair);

};
