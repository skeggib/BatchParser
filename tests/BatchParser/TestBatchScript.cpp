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

} // namespace BatchParser
} // namespace skeggib
} // namespace com