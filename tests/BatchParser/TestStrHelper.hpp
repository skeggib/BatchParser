#pragma once

#include "../../cpptest/cpptest-suite.h"
#include "../../cpptest/cpptest-assert.h"

#include "../../src/BatchParser/StrHelper.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

class TestString : public Test::Suite {

public:

	TestString() {
		TEST_ADD(TestString::test_split);
		TEST_ADD(TestString::test_trim);
	}

private:

	void test_split();
	void test_trim();

}; // class TestString

} // namespace BatchParsers
} // namespace skeggib
} // namespace com