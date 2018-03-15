#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE stringlib tests
#include <boost/test/unit_test.hpp>

#include "stringutils.h"

BOOST_AUTO_TEST_CASE(toUpper) {
    auto result = std::string{"ABCDEFG"};
    auto all = std::string{"abcdefg"};
    auto some = std::string{"AbCdeFg"};

    BOOST_TEST(stringutils::toUpper(all) == result);
    BOOST_TEST(stringutils::toUpper(some) == result);
    BOOST_TEST(stringutils::toUpper(result) == result);
    BOOST_TEST(stringutils::toUpper("abcdefg") == result);
    BOOST_TEST(stringutils::toUpper("aBcDefG") == result);
    BOOST_TEST(stringutils::toUpper("ABCDEFG") == result);
}

BOOST_AUTO_TEST_CASE(toLower) {
    auto result = std::string{"abcdefg"};
    auto all = std::string{"ABCDEFG"};
    auto some = std::string{"AbCdeFg"};

    BOOST_TEST(stringutils::toLower(all) == result);
    BOOST_TEST(stringutils::toLower(some) == result);
    BOOST_TEST(stringutils::toLower(result) == result);
    BOOST_TEST(stringutils::toLower("ABCDEFG") == result);
    BOOST_TEST(stringutils::toLower("aBcDefG") == result);
    BOOST_TEST(stringutils::toLower("abcdefg") == result);
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

    BOOST_TEST(stringutils::trimWhitespace(leading1) == result1);
    BOOST_TEST(stringutils::trimWhitespace(leading2) == result1);
    BOOST_TEST(stringutils::trimWhitespace(leading3) == result1);
    BOOST_TEST(stringutils::trimWhitespace(trailing1) == result1);
    BOOST_TEST(stringutils::trimWhitespace(trailing2) == result1);
    BOOST_TEST(stringutils::trimWhitespace(trailing3) == result1);
    BOOST_TEST(stringutils::trimWhitespace(both1) == result1);
    BOOST_TEST(stringutils::trimWhitespace(both2) == result1);
    BOOST_TEST(stringutils::trimWhitespace(both3) == result1);

    auto result2 = std::string{"abc\t def"};
    auto mixed = std::string{"  \t  abc\t def  \t \t\t"};
    BOOST_TEST(stringutils::trimWhitespace(mixed) == result2);
}

BOOST_AUTO_TEST_CASE(contains) {
    auto string = std::string{"abcdefg"};
    auto compare = std::string{"bcd"};
    auto badCompare = std::string{"zdf"};

    BOOST_TEST(stringutils::contains(string, "b") == true);
    BOOST_TEST(stringutils::contains(string, "def") == true);
    BOOST_TEST(stringutils::contains(string, string) == true);
    BOOST_TEST(stringutils::contains(string, compare) == true);
    BOOST_TEST(stringutils::contains(string, badCompare) == false);
    BOOST_TEST(stringutils::contains(string, "ersf") == false);
    BOOST_TEST(stringutils::contains(string, "") == true);
}

BOOST_AUTO_TEST_CASE(startsWith) {
    auto string = std::string{"abcdefg"};
    auto compare = std::string{"abc"};
    auto badCompare = std::string{"zdf"};

    BOOST_TEST(stringutils::startsWith(string, "a") == true);
    BOOST_TEST(stringutils::startsWith(string, "abc") == true);
    BOOST_TEST(stringutils::startsWith(string, string) == true);
    BOOST_TEST(stringutils::startsWith(string, compare) == true);
    BOOST_TEST(stringutils::startsWith(string, badCompare) == false);
    BOOST_TEST(stringutils::startsWith(string, "ersf") == false);
    BOOST_TEST(stringutils::startsWith(string, "efg") == false);
    BOOST_TEST(stringutils::startsWith(string, "bcd") == false);
    BOOST_TEST(stringutils::contains(string, "") == true);
}

BOOST_AUTO_TEST_CASE(endsWith) {
    auto string = std::string{"abcdefg"};
    auto compare = std::string{"efg"};
    auto badCompare = std::string{"abc"};

    BOOST_TEST(stringutils::startsWith(string, "g") == true);
    BOOST_TEST(stringutils::startsWith(string, "defg") == true);
    BOOST_TEST(stringutils::startsWith(string, string) == true);
    BOOST_TEST(stringutils::startsWith(string, compare) == true);
    BOOST_TEST(stringutils::startsWith(string, badCompare) == false);
    BOOST_TEST(stringutils::startsWith(string, "ersf") == false);
    BOOST_TEST(stringutils::startsWith(string, "abc") == false);
    BOOST_TEST(stringutils::startsWith(string, "bcd") == false);
    BOOST_TEST(stringutils::contains(string, "") == true);
}
