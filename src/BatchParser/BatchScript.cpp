#include "BatchScript.hpp"


namespace BatchParser {

BatchParser::BatchParser() {
	this->script = "";
}

BatchParser::BatchParser(string & script) : BatchParser() {
	this->setScript(script);
}

bool BatchParser::parse() {
	
}

int BatchParser::instructionsCount() {
	return this->instructions.size();
}

BatchInstruction* BatchParser::getInstruction(int index) {
	return &this->instructions[index];
}

string BatchParser::getScript() {
	return this->script;
}

void BatchParser::setScript(string & script) {
	this->script = script;
}

} // namespace BatchParser
