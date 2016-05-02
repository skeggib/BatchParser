#pragma once

#include "../../cpptest/cpptest-suite.h"
#include "../../cpptest/cpptest-assert.h"

#include "../../src/BatchParser/BatchInstruction.hpp"
#include "../../src/BatchParser/BatchArgument.hpp"

#include <string>
#include <vector>

using namespace std;


namespace com {
namespace skeggib {
namespace BatchParser {

class TestBatchInstruction : public Test::Suite {

public:

	TestBatchInstruction() {
		TEST_ADD(TestBatchInstruction::test_setText);
		TEST_ADD(TestBatchInstruction::test_generate);
		TEST_ADD(TestBatchInstruction::test_has);
	}

private:

	void test_setText();
	void test_generate();
	void test_has();

}; // class TestBatchInstruction

} // namespace BatchParser
} // namespace skeggib
} // namespace com