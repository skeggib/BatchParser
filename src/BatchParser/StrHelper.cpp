/*
Copyright (c) 2016, Klasa Sebastien
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
*  Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
*  Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
*  Neither the name of Klasa Sebastien nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY KLASA SEBASTIEN ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL KLASA SEBASTIEN BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

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