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

#include "TestBatchScript.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

void TestBatchScript::test_parse() {
	BatchScript bat_script(this->script);
	
	TEST_ASSERT_MSG(bat_script.getScript() == "\
set REF_FRAME=63\n\
@echo off\n\
set MAYA_VERSION=2015\n\
set MAYA_L=\\yvun0001\\nt02\\V3\\maya_64b.V\%MAYA_VERSION\%R0I1\n\
set MAYA_LOCATION=\%MAYA_L\%\\apl_server\\Maya\%MAYA_VERSION\%\n\
FOR /f \"tokens=*\" %%G IN ('dir /b') DO (\n\
echo %%G\n\
)\n\
set CTLMD_LICENSE_FILE=1828@yvav3260;1828@yvav3270;1828@yvav3330\n",
		"Le script d'entree doit etre le meme que le script de sortie");
}

void TestBatchScript::test_search() {
	BatchScript bat_script(this->script);

	vector<BatchInstruction*> vec = bat_script.search("set MAYA");

	TEST_ASSERT(vec.size() == 3);
	if (vec.size() != 3)
		return;
	TEST_ASSERT(vec[0] == bat_script.getInstruction(2));
	TEST_ASSERT(vec[1] == bat_script.getInstruction(3));
	TEST_ASSERT(vec[2] == bat_script.getInstruction(4));
}

void TestBatchScript::test_getInstruction() {
	BatchScript bat_script(this->script);
	BatchInstruction * inst = bat_script.getInstruction(1);
	inst->getArgument(0)->setValue("on");

	TEST_ASSERT_MSG(bat_script.getInstruction(1)->getText() == "@echo on",
		("Expected : '@echo on', given : '"
		+ bat_script.getInstruction(1)->getText() + "'").c_str());

	TEST_ASSERT(bat_script.getScript() == "\
set REF_FRAME=63\n\
@echo on\n\
set MAYA_VERSION=2015\n\
set MAYA_L=\\yvun0001\\nt02\\V3\\maya_64b.V\%MAYA_VERSION\%R0I1\n\
set MAYA_LOCATION=\%MAYA_L\%\\apl_server\\Maya\%MAYA_VERSION\%\n\
FOR /f \"tokens=*\" %%G IN ('dir /b') DO (\n\
echo %%G\n\
)\n\
set CTLMD_LICENSE_FILE=1828@yvav3260;1828@yvav3270;1828@yvav3330\n");
}

} // namespace BatchParser
} // namespace skeggib
} // namespace com