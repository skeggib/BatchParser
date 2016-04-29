#ifndef BATCHPARSER_HPP
#define BATCHPARSER_HPP

#include <string>
#include <vector>

using namespace std;

#include "BatchInstruction.hpp"


namespace BatchParser {

class BatchScript {

private:

	vector<BatchInstruction> instructions;
	string script;

public:

	BatchScript();
	BatchScript(string & script);

	bool parse();

	int instructionsCount();
	BatchInstruction * getInstruction(int index);

	string getScript();
	void setScript(string & script);

}; // class BatchScript

} // namespace BatchParser

#endif // BATCHPARSER_HPP
