#ifndef BATCHPARSER_BATCHARGUMENT_H
#define BATCHPARSER_BATCHARGUMENT_H

#include <string>

using namespace std;


namespace BatchParser {

class BatchArgument {

private:

	string name;
	string value;

public:

	BatchArgument();
	BatchArgument(string name, string value);

	string getName();
	void setName(string name);

	string getValue();
	void setValue(string value);

	bool equals(BatchArgument arg);

}; // class BatchArgument

} // namespace BatchParser

#endif // BATCHPARSER_BATCHARGUMENT_H