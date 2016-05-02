#ifndef BATCHPARSER_STRING_HPP
#define BATCHPARSER_STRING_HPP

#include <string>
#include <cstring>
#include <vector>

using namespace std;


namespace com {
namespace skeggib {
namespace BatchParser {

class String {

private:

	string basic_str;

public:

	String();
	String(const char * c);
	String(const string & str);
	String(const String & str);

	vector<String> split(const string & delimiter);
	vector<String> split(const char * c);

	void trim();

	const char * c_str() const;
	size_t find(const string & str, size_t pos = 0);

	String & operator=(const String & str);
	String & operator=(const char * c);

	String & operator+=(const string & str);

	char operator[](int i);

	bool operator==(const String & str);
	bool operator==(const char * c);

	operator string();

}; // class String

} // namespace BatchParser
} // namespace skeggib
} // namespace com

#endif // BATCHPARSER_STRING_HPP