#pragma once

#include "../../cpptest/cpptest-suite.h"
#include "../../cpptest/cpptest-assert.h"

#include "../../src/BatchParser/BatchScript.hpp"

namespace BatchParser {

class TestBatchScript : public Test::Suite {

public:

	TestBatchScript() {
		TEST_ADD(TestBatchScript::test_parse);
	}

private:

	void test_parse() {
		string script = "\
set REF_FRAME=63\n\
@echo off\n\
set MAYA_VERSION=2015\n\
set MAYA_L=\\yvun0001\nt02\\V3\\maya_64b.V\%MAYA_VERSION\%R0I1\n\
set MAYA_LOCATION=\%MAYA_L\%\apl_server\\Maya\%MAYA_VERSION\%\n\
\n\
FOR /f \"tokens=*\" %%G IN ('dir /b') DO (\n\
 echo %%G\n\
)\n\
\n\
set CTLMD_LICENSE_FILE=1828@yvav3260;1828@yvav3270;1828@yvav3330\n\
";

		BatchScript bat_script(script);
		cout << bat_script.getScript() << endl;
	}

}; // class TestBatchScript

} // namespace BatchParser