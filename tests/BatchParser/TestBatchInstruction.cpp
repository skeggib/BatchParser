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
"bsub \
-a lspasswd \
-q mygale \
-n 1,16 \
-w \"ended(289318)\" \
-R \"span[hosts=1] select[  mem > 6000 && ( parc_style == dedie || parc_style == presentation || parc_style == utilisateur || parc_style == holobench )]\"  \
-J \"CreativityInMotion_X74_PFF_Urban_Epsilon_1_car_night_J613542_Mon_14_Mar_2016_17_49_27_cam02_1\"[512-532] \
-o \"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Log\\LSF_log.txt\" \
\"\\\"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Maya_batch_Urban_Epsilon_1_car_night_J613542_Mon_14_Mar_2016_17_49_27_cam02_1.bat\"\\\"  \
> \
\"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Log\\currentJobIdStruct.txt\"");
	
	TEST_ASSERT_MSG(inst.getText() == 
"bsub \
-a lspasswd \
-q mygale \
-n 1,16 \
-w \"ended(289318)\" \
-R \"span[hosts=1] select[ mem > 6000 && ( parc_style == dedie || parc_style == presentation || parc_style == utilisateur || parc_style == holobench )]\" \
-J \"CreativityInMotion_X74_PFF_Urban_Epsilon_1_car_night_J613542_Mon_14_Mar_2016_17_49_27_cam02_1\"[512-532] \
-o \"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Log\\LSF_log.txt\" \
\"\\\"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Maya_batch_Urban_Epsilon_1_car_night_J613542_Mon_14_Mar_2016_17_49_27_cam02_1.bat\"\\\" \
> \
\"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Log\\currentJobIdStruct.txt\"",
(
"Expected: 'bsub \
-a lspasswd \
-q mygale \
-n 1,16 \
-w \"ended(289318)\" \
-R \"span[hosts=1] select[ mem > 6000 && ( parc_style == dedie || parc_style == presentation || parc_style == utilisateur || parc_style == holobench )]\" \
-J \"CreativityInMotion_X74_PFF_Urban_Epsilon_1_car_night_J613542_Mon_14_Mar_2016_17_49_27_cam02_1\"[512-532] \
-o \"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Log\\LSF_log.txt\" \
\"\\\"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Maya_batch_Urban_Epsilon_1_car_night_J613542_Mon_14_Mar_2016_17_49_27_cam02_1.bat\"\\\" \
> \
\"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Log\\currentJobIdStruct.txt\"' \
Given: '" + inst.getText() + "'"
).c_str());

	TEST_ASSERT(inst.getCommand() == "bsub");
	TEST_ASSERT(inst.argumentsCount() == 10);
	if (inst.argumentsCount() < 10)
		return;

	TEST_ASSERT_MSG(inst.getArgument(0)->getValue() == "lspasswd",
		("Expected: 'lspasswd' Given: '" + inst.getArgument(0)->getValue() + "'").c_str());
	
	TEST_ASSERT_MSG(inst.getArgument(1)->getValue() == "mygale",
		("Expected: 'mygale' Given: '" + inst.getArgument(1)->getValue() + "'").c_str());
	
	TEST_ASSERT_MSG(inst.getArgument(2)->getValue() == "1,16",
		("Expected: '1,16' Given: '" + inst.getArgument(2)->getValue() + "'").c_str());
	
	TEST_ASSERT_MSG(inst.getArgument(3)->getValue() == "\"ended(289318)\"",
		("Expected: '\"ended(289318)\" ' Given: '" + inst.getArgument(3)->getValue() + "'").c_str());
	
	TEST_ASSERT_MSG(inst.getArgument(4)->getValue() == "\"span[hosts=1] select[ mem > 6000 && ( parc_style == dedie || parc_style == presentation || parc_style == utilisateur || parc_style == holobench )]\"",
		("Expected: '\"span[hosts=1] select[  mem > 6000 && ( parc_style == dedie || parc_style == presentation || parc_style == utilisateur || parc_style == holobench )]\"' Given: '" + inst.getArgument(4)->getValue() + "'").c_str());
	
	TEST_ASSERT_MSG(inst.getArgument(5)->getValue() == "\"CreativityInMotion_X74_PFF_Urban_Epsilon_1_car_night_J613542_Mon_14_Mar_2016_17_49_27_cam02_1\"[512-532]",
		("Expected: '\"CreativityInMotion_X74_PFF_Urban_Epsilon_1_car_night_J613542_Mon_14_Mar_2016_17_49_27_cam02_1\"[512-532]' Given: '" + inst.getArgument(5)->getValue() + "'").c_str());
	
	TEST_ASSERT_MSG(inst.getArgument(6)->getValue() == "\"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Log\\LSF_log.txt\"",
		("Expected: '\"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Log\\LSF_log.txt\"' Given: '" + inst.getArgument(6)->getValue() + "'").c_str());
	
	TEST_ASSERT_MSG(inst.getArgument(7)->getValue() == "\"\\\"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Maya_batch_Urban_Epsilon_1_car_night_J613542_Mon_14_Mar_2016_17_49_27_cam02_1.bat\"\\\"",
		("Expected: '\"\\\"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Maya_batch_Urban_Epsilon_1_car_night_J613542_Mon_14_Mar_2016_17_49_27_cam02_1.bat\"\\\"' Given: '" + inst.getArgument(7)->getValue() + "'").c_str());
	
	TEST_ASSERT_MSG(inst.getArgument(8)->getValue() == ">",
		("Expected: '>' Given: '" + inst.getArgument(8)->getValue() + "'").c_str());
	
	TEST_ASSERT_MSG(inst.getArgument(9)->getValue() == "\"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Log\\currentJobIdStruct.txt\"",
		("Expected: '\"\\\\yvun0002\\mgsvv090\\u468135\\TestVerifRendu\\Log\\currentJobIdStruct.txt\"' Given: '" + inst.getArgument(9)->getValue() + "'").c_str());

	/* --- */

	inst.setText("\
\"\%MAYA_LOCATION\%\\bin\\render.exe\" \
-r file \
-mr:art \
-s \%CALC_IMAGE\% \
-e \%CALC_IMAGE\% \
-rd \"\\\\yvun0002\\mgsvv090\\j613542\\CreativityInMotion\\la ferte\\Ville\\images\" \
-fnc 3 \
-pad 1 \
-cam WheelerExt_01_FollowCam \
-alpha 0 \
-depth 0 \
-im ville \
-of jpg \
\"\\\\yvun0002\\mgsvv090\\j613542\\CreativityInMotion\\la ferte\\Ville\\Pour-Maya\\LFV-Ville.mb\" \
>> \
\"\\\\yvun0002\\mgsvv090\\j613542\\mygale\\TEMP\\LF_ville_02\\appli\"\\\%LSB_JOBID\%_\%CALC_IMAGE\%_\%COMPUTERNAME\%_LF_ville_02.txt"
);

	TEST_ASSERT(inst.getCommand() == "\"\%MAYA_LOCATION\%\\bin\\render.exe\"");
	TEST_ASSERT(inst.argumentsCount() == 15);
	if (inst.argumentsCount() < 15)
		return;

	TEST_ASSERT_MSG(inst.getArgument(0)->getValue() == "file",
		("Expected: 'file' Given: '" + inst.getArgument(0)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(1)->getName() == "-mr:art",
		("Expected: '-mr:art' Given: '" + inst.getArgument(1)->getName() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(2)->getValue() == "\%CALC_IMAGE\%",
		("Expected: '\%CALC_IMAGE\%' Given: '" + inst.getArgument(2)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(3)->getValue() == "\%CALC_IMAGE\%",
		("Expected: '\%CALC_IMAGE\%' Given: '" + inst.getArgument(3)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(4)->getValue() == "\"\\\\yvun0002\\mgsvv090\\j613542\\CreativityInMotion\\la ferte\\Ville\\images\"",
		("Expected: '\"\\\\yvun0002\\mgsvv090\\j613542\\CreativityInMotion\\la ferte\\Ville\\images\"' Given: '" + inst.getArgument(4)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(5)->getValue() == "3",
		("Expected: '3' Given: '" + inst.getArgument(5)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(6)->getValue() == "1",
		("Expected: '1' Given: '" + inst.getArgument(6)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(7)->getValue() == "WheelerExt_01_FollowCam",
		("Expected: 'WheelerExt_01_FollowCam' Given: '" + inst.getArgument(7)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(8)->getValue() == "0",
		("Expected: '0' Given: '" + inst.getArgument(8)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(9)->getValue() == "0",
		("Expected: '0' Given: '" + inst.getArgument(9)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(10)->getValue() == "ville",
		("Expected: 'ville' Given: '" + inst.getArgument(10)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(11)->getValue() == "jpg",
		("Expected: 'jpg' Given: '" + inst.getArgument(11)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(12)->getValue() == "\"\\\\yvun0002\\mgsvv090\\j613542\\CreativityInMotion\\la ferte\\Ville\\Pour-Maya\\LFV-Ville.mb\"",
		("Expected: '\"\\\\yvun0002\\mgsvv090\\j613542\\CreativityInMotion\\la ferte\\Ville\\Pour-Maya\\LFV-Ville.mb\"' Given: '" + inst.getArgument(11)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(13)->getValue() == ">>",
		("Expected: '>>' Given: '" + inst.getArgument(12)->getValue() + "'").c_str());

	TEST_ASSERT_MSG(inst.getArgument(14)->getValue() == "\"\\\\yvun0002\\mgsvv090\\j613542\\mygale\\TEMP\\LF_ville_02\\appli\"\\\%LSB_JOBID\%_\%CALC_IMAGE\%_\%COMPUTERNAME\%_LF_ville_02.txt",
		("Expected: '\"\\\\yvun0002\\mgsvv090\\j613542\\mygale\\TEMP\\LF_ville_02\\appli\"\\\%LSB_JOBID\%_\%CALC_IMAGE\%_\%COMPUTERNAME\%_LF_ville_02.txt' Given: '" + inst.getArgument(13)->getValue() + "'").c_str());

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