#include "StrHelper.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

vector<string> StrHelper::split(const string & str, const string & delimiter) {
	vector<string> vec;
	int pos = 0;
	string str2 = str;

	do {

		pos = str2.find(delimiter);
		
		if (pos == string::npos)
			vec.push_back(str2);
		else
			vec.push_back(str2.substr(0, pos));
		
		str2 = str2.substr(
			pos + delimiter.size(),
			str2.size() - pos - 1);

	} while (pos != string::npos);

	return vec;
}

string StrHelper::trim(const string & str) {
	string trimed = str;
	char c;

	c = trimed[0];
	while ((c == ' ' || c == '\t' || c == '\n')) {
		trimed = trimed.substr(1, trimed.size() - 1);
		c = trimed[0];
	}

	c = trimed[trimed.size() - 1];
	while ((c == ' ' || c == '\t' || c == '\n')) {
		trimed = trimed.substr(0, trimed.size() - 1);
		c = trimed[trimed.size() - 1];
	}

	return trimed;
}

} // BatchParser
} // skeggib
} // com