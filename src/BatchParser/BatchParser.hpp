#ifndef BATCHPARSER_HPP
#define BATCHPARSER_HPP

#include <string>
#include <vector>

using namespace std;

#include "BatchInstruction.hpp"


namespace BatchParser {

class BatchParser {

private:

	vector<BatchInstruction> instructions;
	string script;

public:

	BatchParser();
	BatchParser(string & script);

	bool parse();

	int instructionsCount();
	BatchInstruction* getInstruction(int index);

	string getScript();
	void setScript(string & script);

}; // class BatchParser

} // namespace BatchParser

#endif // BATCHPARSER_HPP
