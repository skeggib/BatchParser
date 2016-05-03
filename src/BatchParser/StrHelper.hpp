#ifndef BATCHPARSER_STRING_HPP
#define BATCHPARSER_STRING_HPP

#include <string>
#include <cstring>
#include <vector>

using namespace std;


namespace com {
namespace skeggib {
namespace BatchParser {

class StrHelper {

private:

	StrHelper();

public:

	static vector<string> split(const string & str, const string & delimiter);
	static string trim(const string & str);

}; // class StrHelper

} // namespace BatchParser
} // namespace skeggib
} // namespace com

#endif // BATCHPARSER_STRING_HPP