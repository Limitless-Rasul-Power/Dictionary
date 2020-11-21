#pragma once
#include "Pair.h"

template<typename T1, typename T2>
class Dictionary
{

private:

public:

};

template<>
class Dictionary<std::string, std::string>
{

private:
	Pair* words;
	unsigned short number_of_words;

public:

	Dictionary();

	explicit inline Dictionary(const short& number_of_words);

	Dictionary(Pair* const& words, const short& number_of_words);

	void Set_number_of_words(const short& number_of_words);
	unsigned short Get_number_of_words() const;

	void Set_words(Pair* const& words);
	Pair* Get_words() const;

	void Add_new_key(const Pair& key);


	Pair& operator[] (const std::string& key);

	inline ~Dictionary();

	friend std::ostream& operator << (std::ostream& out, const Dictionary<std::string, std::string>& dictionary);
};