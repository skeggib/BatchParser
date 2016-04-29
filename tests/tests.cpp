#include "../cpptest/cpptest-suite.h"
#include "../cpptest/cpptest-textoutput.h"

#include "BatchParser/TestBatchParser.hpp"
#include "BatchParser/TestBatchInstruction.hpp"

using namespace BatchParser;

bool runTests();

int main(int argc, char const *argv[])
{
	bool result = runTests();

	if (result)
		return 0;
	return 1;
}

bool runTests() {
	Test::Suite ts;

	ts.add(auto_ptr<Test::Suite>(new TestBatchParser()));
	ts.add(auto_ptr<Test::Suite>(new TestBatchInstruction()));

	Test::TextOutput output(Test::TextOutput::Verbose);
	return ts.run(output);
}