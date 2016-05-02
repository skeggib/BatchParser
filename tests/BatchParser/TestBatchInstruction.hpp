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

	void test_setText() {
		BatchInstruction inst;

		/* --- */

		inst.setText("  \tset var=5\n");
		TEST_ASSERT(inst.getText() == "set var=5");
		TEST_ASSERT(inst.getCommand() == "set");
		TEST_ASSERT(inst.argumentsCount() == 1);
		if (inst.argumentsCount() < 1)
			return;
		TEST_ASSERT(inst.getArgument(0)->getName() == "");
		TEST_ASSERT(inst.getArgument(0)->getValue() == "var=5");

		/* --- */

		inst.setText(
			"blender file.blend -v -d \"/home/skeggib/\" --no-console");
		TEST_ASSERT(inst.getText() == 
			"blender file.blend -v -d \"/home/skeggib/\" --no-console");
		TEST_ASSERT(inst.getCommand() == "blender");
		TEST_ASSERT(inst.argumentsCount() == 4);
		if (inst.argumentsCount() < 4)
			return;

		TEST_ASSERT(inst.getArgument(0)->getName() == "");
		TEST_ASSERT(inst.getArgument(0)->getValue() == "file.blend");

		TEST_ASSERT(inst.getArgument(1)->getName() == "-v");
		TEST_ASSERT(inst.getArgument(1)->getValue() == "");

		TEST_ASSERT(inst.getArgument(2)->getName() == "-d");
		TEST_ASSERT(inst.getArgument(2)->getValue() == "\"/home/skeggib/\"");

		TEST_ASSERT(inst.getArgument(3)->getName() == "--no-console");
		TEST_ASSERT(inst.getArgument(3)->getValue() == "");

		/* --- */

		inst.setText("set /A DECAL_FRAME=\%CALC_IMAGE\%-\%REF_FRAME\%");
		if (inst.argumentsCount() < 1)
			return;

		TEST_ASSERT(inst.getArgument(0)->getName() == "/A");
		TEST_ASSERT(inst.getArgument(0)->getValue() == 
			"DECAL_FRAME=\%CALC_IMAGE\%-\%REF_FRAME\%");
	}

	void test_generate() {
		BatchInstruction inst;

		inst.setCommand("find");

		BatchArgument arg1;
		arg1.setValue("/home/skeggib/");
		inst.addArgument(arg1);

		BatchArgument arg2;
		arg2.setName("-p");
		arg2.setValue("option");
		inst.addArgument(arg2);

		TEST_ASSERT(inst.getText() == 
			"find \"/home/skeggib/\" -p option");
	}

	void test_has() {
		BatchInstruction inst(
			"blender file.blend -v -d \"/home/skeggib/\" --no-console");
		TEST_ASSERT(inst.has("azerty") == false);
		TEST_ASSERT(inst.has("file.blend -v -d") == true);
	}

}; // class TestBatchInstruction

} // namespace BatchParser
} // namespace skeggib
} // namespace com