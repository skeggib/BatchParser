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
	BatchInstruction(string const text);

	vector<string> split(string const str, string const delimiter) const;
	string trim(string const str) const;

	string getText() const;
	void setText(string const text);

	string getCommand() const;
	void setCommand(string const command);

}; // class BatchInstruction

} // namespace BatchParser

#endif // BATCHPARSER_BATCHINSTRUCTION_H
