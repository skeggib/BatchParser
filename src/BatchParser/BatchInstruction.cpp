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

string BatchInstruction::trim(string const str) const {
	/*string trimed = text;
	char c = trimed[0];

	while (c == ' ' || c == '\t' || c == '\n') {
		trimed = trimed.substr(1, trimed.size() - 1);
	}*/
}

} // namespace BatchParser
