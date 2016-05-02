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
	String str(script);
	vector<String> vec = str.split("\n");
	vector<String>::iterator it = vec.begin();

	while (it != vec.end()) {
		if (*it == "")
			vec.erase(it);
		else
			it++;
	}

	for (int i = 0; i < vec.size(); i++) {
		this->instructions.push_back(BatchInstruction(vec[i]));
	}
}

int BatchScript::instructionsCount() {
	return this->instructions.size();
}

BatchInstruction* BatchScript::getInstruction(int index) {
	return &this->instructions[index];
}

string BatchScript::getScript() {
	String str = "";

	for (int i = 0; i < this->instructions.size(); i++) {
		str += this->instructions[i].getText() + "\n";
	}

	return str;
}

void BatchScript::setScript(const string & script) {
	this->parse(script);
}

} // namespace BatchParser
} // namespace skeggib
} // namespace com
