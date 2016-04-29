#ifndef BATCHPARSER_BATCHINSTRUCTION_H
#define BATCHPARSER_BATCHINSTRUCTION_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#include "BatchArgument.hpp"


namespace BatchParser {

class BatchInstruction {

private:

	string text;
	string command;
	vector<BatchArgument> arguments;

	void parseText();
	void generateText();

public:

	BatchInstruction();
	BatchInstruction(string text);

	vector<string> split(string str, string delimiter) const;
	string trim(string str) const;

	string getText() const;
	void setText(string text);

	string getCommand() const;
	void setCommand(string command);

	int argumentsCount() const;
	BatchArgument * getArgument(int index);
	void addArgument(BatchArgument & argument);
	void removeArgument(int index);
	void removeArgument(BatchArgument & argument);

}; // class BatchInstruction

} // namespace BatchParser

#endif // BATCHPARSER_BATCHINSTRUCTION_H
