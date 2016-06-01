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

#include "TestBatchInstruction.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

void TestBatchInstruction::test_setText() {
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
		"blender file.blend -v -d \"/home/skeggib folder/\" --no-console");
	TEST_ASSERT(inst.getText() == 
		"blender file.blend -v -d \"/home/skeggib folder/\" --no-console");
	TEST_ASSERT(inst.getCommand() == "blender");
	TEST_ASSERT(inst.argumentsCount() == 4);
	if (inst.argumentsCount() < 4)
		return;

	TEST_ASSERT_MSG(inst.getArgument(0)->getName() == "",
		("Expected: '' Given: '" + inst.getArgument(0)->getName() + "'").c_str());
	TEST_ASSERT_MSG(inst.getArgument(0)->getValue() == "file.blend",
		("Expected: 'file.blend' Given: '" + inst.getArgument(0)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(1)->getName() == "-v",
		("Expected: '-v' Given: '" + inst.getArgument(1)->getName() + "'").c_str());
	TEST_ASSERT_MSG(inst.getArgument(1)->getValue() == "",
		("Expected: '' Given: '" + inst.getArgument(1)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(2)->getName() == "-d",
		("Expected: '-d' Given: '" + inst.getArgument(2)->getName() + "'").c_str());
	TEST_ASSERT_MSG(inst.getArgument(2)->getValue() == "\"/home/skeggib folder/\"",
		("Expected: '\"/home/skeggib folder/\"' Given: '" + inst.getArgument(2)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(3)->getName() == "--no-console",
		("Expected: '--no-console' Given: '" + inst.getArgument(3)->getName() + "'").c_str());
	TEST_ASSERT_MSG(inst.getArgument(3)->getValue() == "",
		("Expected: '' Given: '" + inst.getArgument(3)->getValue() + "'").c_str());

	/* --- */

	inst.setText("set /A DECAL_FRAME=\%CALC_IMAGE\%-\%REF_FRAME\%");
	if (inst.argumentsCount() < 1)
		return;

	TEST_ASSERT(inst.getArgument(0)->getName() == "/A");
	TEST_ASSERT(inst.getArgument(0)->getValue() == 
		"DECAL_FRAME=\%CALC_IMAGE\%-\%REF_FRAME\%");
}

void TestBatchInstruction::test_generate() {
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

void TestBatchInstruction::test_has() {
	BatchInstruction inst(
		"blender file.blend -v -d \"/home/skeggib/\" --no-console");
	TEST_ASSERT(inst.has("azerty") == false);
	TEST_ASSERT(inst.has("file.blend -v -d") == true);
}

void TestBatchInstruction::test_indexOf() {
	BatchInstruction inst(
		"blender file.blend -v -d \"/home/skeggib/\" --no-console");
	BatchArgument * arg = inst.getArgumentByName("-v");
	TEST_ASSERT(inst.indexOf(arg) == 1);
	arg = inst.getArgumentByName("-d");
	TEST_ASSERT(inst.indexOf(arg) == 2);
}

} // namespace BatchParser
} // namespace skeggib
} // namespace com