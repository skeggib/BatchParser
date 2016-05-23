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

#include "TestStrHelper.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

void TestString::test_split() {
	string str;
	vector<string> vec;

	str = "Chaine";
	vec = StrHelper::split(str, " ");
	TEST_ASSERT_MSG(vec[0] == "Chaine", 	vec[0].c_str());

	str = "Chaine a decouper";
	vec = StrHelper::split(str, " ");
	TEST_ASSERT_MSG(vec[0] == "Chaine", 	vec[0].c_str());
	TEST_ASSERT_MSG(vec[1] == "a", 			vec[1].c_str());
	TEST_ASSERT_MSG(vec[2] == "decouper", 	vec[2].c_str());

	str = "Cha25ine a25 decoup25er";
	vec = StrHelper::split(str, "25");
	TEST_ASSERT_MSG(vec[0] == "Cha", 		vec[0].c_str());
	TEST_ASSERT_MSG(vec[1] == "ine a", 		vec[1].c_str());
	TEST_ASSERT_MSG(vec[2] == " decoup", 	vec[2].c_str());
	TEST_ASSERT_MSG(vec[3] == "er", 		vec[3].c_str());
}

void TestString::test_trim() {
	string str;

	str = " \t";
	str = StrHelper::trim(str);
	TEST_ASSERT_MSG(str == "",			str.c_str());

	str = "Chaine";
	str = StrHelper::trim(str);
	TEST_ASSERT_MSG(str == "Chaine",		str.c_str());

	str = "  \t \n   Chaine    \n   \t";
	str = StrHelper::trim(str);
	TEST_ASSERT_MSG(str == "Chaine",		str.c_str());
}

} // namespace BatchParser
} // namespace skeggib
} // namespace com