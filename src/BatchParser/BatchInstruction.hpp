#ifndef BATCHPARSER_BATCHINSTRUCTION_H
#define BATCHPARSER_BATCHINSTRUCTION_H

#include <string>
#include <vector>

using namespace std;


namespace BatchParser {

class BatchInstruction {

private:

	string text;
	string command;

public:

	BatchInstruction();
	BatchInstruction(string text);

	vector<string> split(string str, string delimiter) const;
	string trim(string str) const;

	string getText() const;
	void setText(string text);

	string getCommand() const;
	void setCommand(string command);

}; // class BatchInstruction

} // namespace BatchParser

#endif // BATCHPARSER_BATCHINSTRUCTION_H
