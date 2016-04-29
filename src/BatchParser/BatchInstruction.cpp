#include "BatchInstruction.hpp"

namespace BatchParser {

BatchInstruction::BatchInstruction() {
	this->text = "";
	this->command = "";
}

BatchInstruction::BatchInstruction(string const text)
	: BatchInstruction() {

	/*this->setText(text);
	string command = this->split(this->trim(text), " ")[0];
	this->setCommand(command);*/
}

vector<string> BatchInstruction::split(string str, string delimiter) const {
	vector<string> vec;
	int pos = 0;

	do {

		pos = str.find(delimiter);
		
		if (pos == string::npos)
			vec.push_back(str);
		else
			vec.push_back(str.substr(0, pos));
		
		str = str.substr(
			pos + delimiter.size(),
			str.size() - pos - 1);

	} while (pos != string::npos);

	return vec;
}

string BatchInstruction::trim(string str) const {
	/*string trimed = text;
	char c = trimed[0];

	while (c == ' ' || c == '\t' || c == '\n') {
		trimed = trimed.substr(1, trimed.size() - 1);
	}*/
}

} // namespace BatchParser
