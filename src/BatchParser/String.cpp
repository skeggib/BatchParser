#include "String.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

String::String() {
	this->basic_str = "";
}

String::String(const char * c) {
	this->basic_str = c;
}

String::String(const string & str) {
	this->basic_str = str;
}

String::String(const String & str) {
	this->basic_str = str.basic_str;
}

vector<String> String::split(const string & delimiter) {
	this->split(delimiter.c_str());
}

vector<String> String::split(const char * delimiter) {
	vector<String> vec;
	int pos = 0;
	string str = this->basic_str;

	do {

		pos = str.find(delimiter);
		
		if (pos == string::npos)
			vec.push_back(str);
		else
			vec.push_back(String(str.substr(0, pos)));
		
		str = str.substr(
			pos + strlen(delimiter),
			str.size() - pos - 1);

	} while (pos != string::npos);

	return vec;
}

void String::trim() {
	string trimed = this->basic_str;
	char c;

	c = trimed[0];
	while ((c == ' ' || c == '\t' || c == '\n')) {
		trimed = trimed.substr(1, trimed.size() - 1);
		c = trimed[0];
	}

	c = trimed[trimed.size() - 1];
	while ((c == ' ' || c == '\t' || c == '\n')) {
		trimed = trimed.substr(0, trimed.size() - 1);
		c = trimed[trimed.size() - 1];
	}

	this->basic_str = trimed;
}

const char * String::c_str() const {
	return this->basic_str.c_str();
}

size_t String::find(const string & str, size_t pos) {
	return this->basic_str.find(str, pos);
}

String & String::operator=(const String & str) {
	this->basic_str = str.basic_str;
	return *this;
}

String & String::operator=(const char * c) {
	this->basic_str = c;
	return *this;
}

String & String::operator+=(const string & str) {
	this->basic_str += str;
	return *this;
}

char String::operator[](int i) {
	return this->basic_str[i];
}

bool String::operator==(const String & str) {
	return this->basic_str == str.basic_str;
}

bool String::operator==(const char * c) {
	return strcmp(this->basic_str.c_str(), c) == 0;
}

String::operator string() {
	return this->basic_str;
}

} // BatchParser
} // skeggib
} // com