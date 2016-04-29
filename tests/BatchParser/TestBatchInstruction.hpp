#pragma once

#include "../../cpptest/cpptest-suite.h"
#include "../../cpptest/cpptest-assert.h"

#include "../../src/BatchParser/BatchInstruction.hpp"

namespace BatchParser {

class TestBatchInstruction : public Test::Suite {

public:

	TestBatchInstruction() {
		TEST_ADD(TestBatchInstruction::test_split);
	}

private:

	void test_split() {
		TEST_FAIL("fail");
	}

}; // class TestBatchInstruction

} // namespace BatchParser