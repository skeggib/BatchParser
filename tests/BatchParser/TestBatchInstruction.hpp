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
		TEST_ADD(TestBatchInstruction::test_indexOf);
	}

private:

	void test_setText();
	void test_generate();
	void test_has();
	void test_indexOf();

}; // class TestBatchInstruction

} // namespace BatchParser
} // namespace skeggib
} // namespace com