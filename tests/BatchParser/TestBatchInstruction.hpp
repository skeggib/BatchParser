#pragma once

#include "../../cpptest/cpptest-suite.h"
#include "../../cpptest/cpptest-assert.h"

#include "../../src/BatchParser/BatchInstruction.hpp"

#include <string>
#include <vector>

using namespace std;


namespace BatchParser {

class TestBatchInstruction : public Test::Suite {

public:

	TestBatchInstruction() {
		TEST_ADD(TestBatchInstruction::test_split);
		TEST_ADD(TestBatchInstruction::test_trim);
	}

private:

	void test_split() {
		BatchInstruction instruction;
		string str;
		vector<string> vec;

		str = "Chaine";
		vec = instruction.split(str, " ");
		TEST_ASSERT_MSG(vec[0] == "Chaine", 	vec[0].c_str());

		str = "Chaine a decouper";
		vec = instruction.split(str, " ");
		TEST_ASSERT_MSG(vec[0] == "Chaine", 	vec[0].c_str());
		TEST_ASSERT_MSG(vec[1] == "a", 			vec[1].c_str());
		TEST_ASSERT_MSG(vec[2] == "decouper", 	vec[2].c_str());

		str = "Cha25ine a25 decoup25er";
		vec = instruction.split(str, "25");
		TEST_ASSERT_MSG(vec[0] == "Cha", 		vec[0].c_str());
		TEST_ASSERT_MSG(vec[1] == "ine a", 		vec[1].c_str());
		TEST_ASSERT_MSG(vec[2] == " decoup", 	vec[2].c_str());
		TEST_ASSERT_MSG(vec[3] == "er", 		vec[3].c_str());
	}

	void test_trim() {
		BatchInstruction instruction;
		string str;
		string trimed;

		str = " \t";
		trimed = instruction.trim(str);
		TEST_ASSERT_MSG(trimed == "",			trimed.c_str());

		str = "Chaine";
		trimed = instruction.trim(str);
		TEST_ASSERT_MSG(trimed == "Chaine",		trimed.c_str());

		str = "  \t \n   Chaine    \n   \t";
		trimed = instruction.trim(str);
		TEST_ASSERT_MSG(trimed == "Chaine",		trimed.c_str());
	}

}; // class TestBatchInstruction

} // namespace BatchParser