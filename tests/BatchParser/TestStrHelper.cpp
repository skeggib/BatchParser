#include "TestStrHelper.hpp"


namespace com {
namespace skeggib {
namespace BatchParser {

void TestString::test_split() {
	string str;
	vector<string> vec;

	str = "Chaine";
	vec = StrHelper::split(str, " ");
	TEST_ASSERT_MSG(vec[0] == "Chaine", 	vec[0].c_str());

	str = "Chaine a decouper";
	vec = StrHelper::split(str, " ");
	TEST_ASSERT_MSG(vec[0] == "Chaine", 	vec[0].c_str());
	TEST_ASSERT_MSG(vec[1] == "a", 			vec[1].c_str());
	TEST_ASSERT_MSG(vec[2] == "decouper", 	vec[2].c_str());

	str = "Cha25ine a25 decoup25er";
	vec = StrHelper::split(str, "25");
	TEST_ASSERT_MSG(vec[0] == "Cha", 		vec[0].c_str());
	TEST_ASSERT_MSG(vec[1] == "ine a", 		vec[1].c_str());
	TEST_ASSERT_MSG(vec[2] == " decoup", 	vec[2].c_str());
	TEST_ASSERT_MSG(vec[3] == "er", 		vec[3].c_str());
}

void TestString::test_trim() {
	string str;

	str = " \t";
	str = StrHelper::trim(str);
	TEST_ASSERT_MSG(str == "",			str.c_str());

	str = "Chaine";
	str = StrHelper::trim(str);
	TEST_ASSERT_MSG(str == "Chaine",		str.c_str());

	str = "  \t \n   Chaine    \n   \t";
	str = StrHelper::trim(str);
	TEST_ASSERT_MSG(str == "Chaine",		str.c_str());
}

} // namespace BatchParser
} // namespace skeggib
} // namespace com