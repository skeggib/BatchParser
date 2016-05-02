#include "../cpptest/cpptest-suite.h"
#include "../cpptest/cpptest-textoutput.h"

#include "BatchParser/TestString.hpp"
#include "BatchParser/TestBatchScript.hpp"
#include "BatchParser/TestBatchInstruction.hpp"

using namespace com::skeggib::BatchParser;

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

	ts.add(auto_ptr<Test::Suite>(new TestString()));
	ts.add(auto_ptr<Test::Suite>(new TestBatchInstruction()));
	ts.add(auto_ptr<Test::Suite>(new TestBatchScript()));

	Test::TextOutput output(Test::TextOutput::Verbose);
	return ts.run(output);
}