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

	void parse(const string & script);

public:

	BatchScript();
	BatchScript(const string & script);

	int instructionsCount();
	BatchInstruction * getInstruction(int index);

	string getScript();
	void setScript(const string & script);

}; // class BatchScript

} // namespace BatchParser

#endif // BATCHPARSER_HPP
