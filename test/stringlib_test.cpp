#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE stringlib tests
#include <boost/test/unit_test.hpp>

#include "stringlib.h"

BOOST_AUTO_TEST_CASE(toUpper) {
    auto result = std::string{"ABCDEFG"};
    auto all = std::string{"abcdefg"};
    auto some = std::string{"AbCdeFg"};

    BOOST_TEST(string::toUpper(all) == result);
    BOOST_TEST(string::toUpper(some) == result);
    BOOST_TEST(string::toUpper(result) == result);
    BOOST_TEST(string::toUpper("abcdefg") == result);
    BOOST_TEST(string::toUpper("aBcDefG") == result);
    BOOST_TEST(string::toUpper("ABCDEFG") == result);
}

BOOST_AUTO_TEST_CASE(toLower) {
    auto result = std::string{"abcdefg"};
    auto all = std::string{"ABCDEFG"};
    auto some = std::string{"AbCdeFg"};

    BOOST_TEST(string::toLower(all) == result);
    BOOST_TEST(string::toLower(some) == result);
    BOOST_TEST(string::toLower(result) == result);
    BOOST_TEST(string::toLower("ABCDEFG") == result);
    BOOST_TEST(string::toLower("aBcDefG") == result);
    BOOST_TEST(string::toLower("abcdefg") == result);
}

BOOST_AUTO_TEST_CASE(trimWhitespace) {
    auto result1 = std::string{"abc"};

    auto leading1 = std::string{" abc"};
    auto leading2 = std::string{"   abc"};
    auto leading3 = std::string{" \t  abc"};
    auto trailing1 = std::string{"abc "};
    auto trailing2 = std::string{"abc   "};
    auto trailing3 = std::string{"abc \t  "};
    auto both1 = std::string{" \t abc "};
    auto both2 = std::string{" \t abc   "};
    auto both3 = std::string{" \t abc \t  "};

    BOOST_TEST(string::trimWhitespace(leading1) == result1);
    BOOST_TEST(string::trimWhitespace(leading2) == result1);
    BOOST_TEST(string::trimWhitespace(leading3) == result1);
    BOOST_TEST(string::trimWhitespace(trailing1) == result1);
    BOOST_TEST(string::trimWhitespace(trailing2) == result1);
    BOOST_TEST(string::trimWhitespace(trailing3) == result1);
    BOOST_TEST(string::trimWhitespace(both1) == result1);
    BOOST_TEST(string::trimWhitespace(both2) == result1);
    BOOST_TEST(string::trimWhitespace(both3) == result1);

    auto result2 = std::string{"abc\t def"};
    auto mixed = std::string{"  \t  abc\t def  \t \t\t"};
    BOOST_TEST(string::trimWhitespace(mixed) == result2);
}

BOOST_AUTO_TEST_CASE(contains) {
    auto string = std::string{"abcdefg"};
    auto compare = std::string{"bcd"};
    auto badCompare = std::string{"zdf"};

    BOOST_TEST(string::contains(string, "b") == true);
    BOOST_TEST(string::contains(string, "def") == true);
    BOOST_TEST(string::contains(string, string) == true);
    BOOST_TEST(string::contains(string, compare) == true);
    BOOST_TEST(string::contains(string, badCompare) == false);
    BOOST_TEST(string::contains(string, "ersf") == false);
}
