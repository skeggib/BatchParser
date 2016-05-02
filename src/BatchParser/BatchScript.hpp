#ifndef BATCHPARSER_BATCHSCRIPT_HPP
#define BATCHPARSER_BATCHSCRIPT_HPP

#include <string>
#include <vector>

using namespace std;

#include "BatchInstruction.hpp"


namespace com {
namespace skeggib {
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
} // namespace skeggib
} // namespace com

#endif // BATCHPARSER_BATCHSCRIPT_HPP
