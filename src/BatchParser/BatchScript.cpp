#include "BatchScript.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

BatchScript::BatchScript() {

}

BatchScript::BatchScript(string script) : BatchScript() {
	this->setScript(script);
}

void BatchScript::parse(string script) {
	string str(script);
	vector<string> vec = StrHelper::split(str, "\n");
	vector<string>::iterator it = vec.begin();

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

vector<BatchInstruction*> BatchScript::search(string str) {
	vector<BatchInstruction*> vec;

	for (int i = 0; i < this->instructions.size(); i++) {
		if (this->instructions[i].has(str))
			vec.push_back(&this->instructions[i]);
	}

	return vec;
}

int BatchScript::instructionsCount() {
	return this->instructions.size();
}

BatchInstruction* BatchScript::getInstruction(int index) {
	return &(this->instructions[index]);
}

string BatchScript::getScript() {
	string str = "";

	for (int i = 0; i < this->instructions.size(); i++) {
		str += this->instructions[i].getText() + "\n";
	}

	return str;
}

void BatchScript::setScript(string script) {
	this->parse(script);
}

} // namespace BatchParser
} // namespace skeggib
} // namespace com
