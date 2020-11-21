#include <iostream>
#include <assert.h>
#include "Pair.h"

Pair::Pair():key(""), value("")
{}

Pair::Pair(const Pair& other)
{
	Set_key(other.key);
	Set_value(other.value);
}

Pair& Pair::operator = (const Pair& other)
{
	Set_key(other.key);
	Set_value(other.value);
	return *this;
}

Pair& Pair::operator = (const std::string& value)
{
	Set_value(value);
	return *this;
}

inline Pair::Pair(const std::string& key)
{
	Set_key(key);
}

Pair::Pair(const std::string& key, const std::string& value)
	:Pair(key)
{
	Set_value(value);
}

void Pair::Set_key(const std::string& key)
{
	assert(key.empty() == false && "Key is Empty!");
	this->key = key;
}

std::string Pair::Get_key() const
{
	return key;
}

void Pair::Set_value(const std::string& value)
{
	assert(value.empty() == false && "Value is Empty!");
	this->value = value;
}

std::string Pair::Get_value() const
{
	return value;
}

std::ostream& operator << (std::ostream& out, const Pair& pair)
{
	out << "English: " << pair.key << '\n';
	out << "Azerbaijani: " << pair.value << "\n\n";
	return out;
}