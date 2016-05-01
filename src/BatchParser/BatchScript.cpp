#include "BatchScript.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

BatchScript::BatchScript() {
	
}

BatchScript::BatchScript(const string & script) : BatchScript() {
	this->setScript(script);
}

void BatchScript::parse(const string & script) {
	
}

int BatchScript::instructionsCount() {
	return this->instructions.size();
}

BatchInstruction* BatchScript::getInstruction(int index) {
	return &this->instructions[index];
}

string BatchScript::getScript() {
	return "";
}

void BatchScript::setScript(const string & script) {
	this->parse(script);
}

} // namespace BatchParser
} // namespace skeggib
} // namespace com
