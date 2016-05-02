#pragma once

#include "../../cpptest/cpptest-suite.h"
#include "../../cpptest/cpptest-assert.h"

#include "../../src/BatchParser/BatchScript.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

class TestBatchScript : public Test::Suite {

public:

	TestBatchScript() {
		TEST_ADD(TestBatchScript::test_parse);
	}

private:

	void test_parse();

}; // class TestBatchScript

} // namespace BatchParser
} // namespace skeggib
} // namespace com