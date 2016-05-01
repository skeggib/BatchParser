#include "BatchArgument.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

BatchArgument::BatchArgument() {
	this->name = "";
	this->value = "";
}

BatchArgument::BatchArgument(string name, string value) 
	: BatchArgument() {

	this->setName(name);
	this->setValue(value);
}

string BatchArgument::getName() {
	return this->name;
}

void BatchArgument::setName(string name) {
	this->name = name;
}

string BatchArgument::getValue() {
	return this->value;
}

void BatchArgument::setValue(string value) {
	this->value = value;
}

bool BatchArgument::equals(BatchArgument arg) {
	if (this->getName() != arg.getName())
		return false;
	if (this->getValue() != arg.getValue())
		return false;

	return true;
}

} // namespace BatchParser
} // namespace skeggib
} // namespace com