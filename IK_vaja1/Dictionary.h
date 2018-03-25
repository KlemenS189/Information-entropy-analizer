#pragma once
#include <string>

class Dictionary
{
private:
	std::string name;
	int num_of_appearences;
public:
	Dictionary(std::string ime_input);

	~Dictionary();

	int check_and_increment(std::string string_to_check);
	int get_appearance_num();
	std::string getName();
	int getNum();
	//int check_if_exists();
};

