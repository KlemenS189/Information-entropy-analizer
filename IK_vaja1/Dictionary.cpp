#include "Dictionary.h"



Dictionary::Dictionary(std::string ime_input)
{
	name = ime_input;
	num_of_appearences = 1;
}


Dictionary::~Dictionary()
{
}

int Dictionary::check_and_increment(std::string string_to_check) {
	if (string_to_check == name) {
		num_of_appearences = num_of_appearences + 1;
		return 0;
	}
	else {
		return 1;
	}
}

//int Dictionary::check_if_exists(string ) {
//	if ()
//}

int Dictionary::get_appearance_num() {
	return num_of_appearences;
}

std::string Dictionary::getName() {
	return name;
}
int Dictionary::getNum() {
	return num_of_appearences;
}