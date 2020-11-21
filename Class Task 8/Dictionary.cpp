#include "Dictionary.h"
#include <assert.h>

Dictionary<std::string, std::string>::Dictionary() :words(nullptr), number_of_words(0)
{}

inline Dictionary<std::string, std::string>::Dictionary(const short& number_of_words)
{
	Set_number_of_words(number_of_words);
}

Dictionary<std::string, std::string>::Dictionary(Pair* const& words, const short& number_of_words)
	:Dictionary(number_of_words)
{
	Set_words(words);
}

void Dictionary<std::string, std::string>::Set_number_of_words(const short& number_of_words)
{
	assert(number_of_words > 0 && "Number is 0!");
	this->number_of_words = number_of_words;
}

unsigned short Dictionary<std::string, std::string>::Get_number_of_words() const
{
	return number_of_words;
}

void Dictionary<std::string, std::string>::Set_words(Pair* const& words)
{
	assert(words && "Words are Nullptr!");
	this->words = new Pair[Get_number_of_words()]{};

	for (unsigned short i = 0; i < Get_number_of_words(); i++)
		this->words[i] = words[i];
}

void Dictionary<std::string, std::string>::Add_new_key(const Pair& key)
{
	auto temp = new Pair[Get_number_of_words() + 1];

	for (unsigned short i = 0; i < Get_number_of_words(); i++)
		temp[i] = this->words[i];

	temp[Get_number_of_words()] = key;

	delete[] this->words;
	this->words = temp;
	temp = nullptr;
	Set_number_of_words(++this->number_of_words);
}

Pair* Dictionary<std::string, std::string>::Get_words() const
{
	return words;
}

Pair& Dictionary<std::string, std::string>::operator[] (const std::string& key)
{
	for (unsigned short i = 0; i < Get_number_of_words(); i++)
		if (this->words[i].Get_key() == key)
			return this->words[i];

	Pair is_not_here(key, "n");
	Add_new_key(is_not_here);
	return this->words[Get_number_of_words() - 1];
}

inline Dictionary<std::string, std::string>::~Dictionary()
{
	delete[] this->words;
}

std::ostream& operator << (std::ostream& out, const Dictionary<std::string, std::string>& dictionary)
{
	for (unsigned short i = 0; i < dictionary.Get_number_of_words(); i++)
		out << dictionary.words[i];

	return out;
}