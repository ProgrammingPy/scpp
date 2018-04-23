#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <list>
#include "textutils.h"

using namespace testing;
using namespace std;

//upper() test
TEST(TextUtils, upper)
{
	std::string s("abc");	
	TextUtils t = TextUtils(s);
    EXPECT_STREQ(t.upper().c_str(), "ABC");
	std::string s1("ThiS Is a case words");
	TextUtils t1 = TextUtils(s1);
    EXPECT_STREQ(t1.upper().c_str(), "THIS IS A CASE WORDS");
}

//lower() test
TEST(TextUtils, lower)
{
	std::string s("ABC");
	TextUtils t = TextUtils(s);
    EXPECT_STREQ(t.lower().c_str(), "abc");
	std::string s1("ThiS a LoweR cASE");
	TextUtils t1 = TextUtils(s1);
    EXPECT_STREQ(t1.lower().c_str(), "this a lower case");
}

TEST(TextUtils, lstrip)
{
	std::string s("  sample string test");
	TextUtils t = TextUtils(s);
	EXPECT_STREQ(t.lstrip().c_str(), "sample string test");

	std::string s1(" \r\n\tsample");
	TextUtils t1 = TextUtils(s1);
	EXPECT_STREQ(t1.lstrip().c_str(), "sample");
	EXPECT_EQ(t1.lstrip().size(), 6);
}

TEST(TextUtils, rstrip)
{
	std::string s("sample string  ");
	TextUtils t = TextUtils(s);
	EXPECT_STREQ(t.rstrip().c_str(), "sample string");

	std::string s1(" sample\r\n \t");
	TextUtils t1 = TextUtils(s1);
	EXPECT_STREQ(t1.rstrip().c_str(), " sample");
	EXPECT_EQ(t1.rstrip().size(), 7);
}

TEST(TextUtils, strip)
{
	std::string s(" sample ");
	TextUtils t = TextUtils(s);
	EXPECT_STREQ(t.strip().c_str(), "sample");
	EXPECT_EQ(t.strip().size(), 6);
	std::string s1("------sample--------");
	TextUtils t1 = TextUtils(s1);
	EXPECT_STREQ(t1.strip("-").c_str(), "sample");
	EXPECT_EQ(t1.strip("-").size(), 6);
}

#if 0
TEST(TextUtils, split1)
{
	std::string s("this is a sample string");
	std::vector<string> v;
	v = TextUtils::split(s);

	#ifdef TEXTUTILS_DEBUG
	for (auto e: v) {
		std::cout << e << std::endl;
	}
	#endif
	EXPECT_EQ(v.size(), 5);
	EXPECT_STREQ(v[0].c_str(), "this");
	EXPECT_STREQ(v[1].c_str(), "is");
	EXPECT_STREQ(v[2].c_str(), "a");
	EXPECT_STREQ(v[3].c_str(), "sample");
	EXPECT_STREQ(v[4].c_str(), "string");

	std::vector<string> v1;
	v1 = TextUtils::split(s, " ", 1);
	EXPECT_EQ(v1.size(), 1);
	EXPECT_STREQ(v1[0].c_str(), "this");

	std::vector<string> v2;
	v2 = TextUtils::split(s, " ", 2);
	EXPECT_EQ(v2.size(), 2);
	EXPECT_STREQ(v2[0].c_str(), "this");
	EXPECT_STREQ(v2[1].c_str(), "is");

	std::vector<string> v3;
	v3 = TextUtils::split(s, " ", 3);
	EXPECT_EQ(v3.size(), 3);
	EXPECT_STREQ(v3[0].c_str(), "this");
	EXPECT_STREQ(v3[1].c_str(), "is");
	EXPECT_STREQ(v3[2].c_str(), "a");
}


TEST(TextUtils, split2)
{
	std::string s("11:22:33:44:55:66");
	std::vector<string> v;
	v = TextUtils::split(s, ":");
	EXPECT_EQ(v.size(), 6);
	EXPECT_STREQ(v[0].c_str(), "11");
	EXPECT_STREQ(v[1].c_str(), "22");
	EXPECT_STREQ(v[2].c_str(), "33");
	EXPECT_STREQ(v[3].c_str(), "44");
	EXPECT_STREQ(v[4].c_str(), "55");
	EXPECT_STREQ(v[5].c_str(), "66");
}

TEST(TextUtils, split3)
{
	std::string s("the first line\r\n"
				"the second line\r"
				"the third line\n"
				"the last line\n\n");
	std::vector<string> v;
	v = TextUtils::split(s, "\r\n");
	EXPECT_EQ(v.size(), 4);
	EXPECT_STREQ(v[0].c_str(), "the first line");
	EXPECT_STREQ(v[1].c_str(), "the second line");
	EXPECT_STREQ(v[2].c_str(), "the third line");
	EXPECT_STREQ(v[3].c_str(), "the last line");
}

TEST(TextUtils, contains)
{
	std::string s("one");
	std::vector<std::string> v = { "zero", "one", "two", "three", "four"};
	EXPECT_TRUE(TextUtils::contains(s, v));

	std::list<std::string> slist = { "zero", "one", "two", "three", "four"};
	EXPECT_TRUE(TextUtils::contains(s, slist));
}


TEST(TextUtils, contains1)
{
	std::string s("one");
	std::vector<std::string> v = { "zero", "OnE", "two", "THree", "FOUr"};
	EXPECT_TRUE(TextUtils::contains(s, v, true));

	std::list<std::string> slist = { "zero", "OnE", "two", "THree", "FOUr"};
	EXPECT_TRUE(TextUtils::contains(s, slist, true));

	std::string s1("TWO");
	v = { "zero", "OnE", "two", "THree", "FOUr"};
	EXPECT_TRUE(TextUtils::contains(s1, v, true));

	slist = { "zero", "OnE", "two", "THree", "FOUr"};
	EXPECT_TRUE(TextUtils::contains(s1, slist, true));

	std::string s2("thrEE");
	v = { "zero", "OnE", "two", "THree", "FOUr"};
	EXPECT_TRUE(TextUtils::contains(s2, v, true));

	slist = { "zero", "OnE", "two", "THree", "FOUr"};
	EXPECT_TRUE(TextUtils::contains(s2, slist, true));
}
#endif
