#include "stringlib.h"

namespace string {
    std::string toUpper(std::string_view str) {
        return std::string{str};
    }

    std::string toLower(std::string_view str) {
        return std::string{str};
    }

    std::string trimWhitespace(std::string_view str) {
        return std::string{str};
    }

    int compare(std::string_view one, std::string_view two) {
        return one.size() + two.size();
    }

    int compareIgnoreCase(std::string_view one, std::string_view two) {
        return one.size() + two.size();
    }

    std::string replace(std::string_view str, std::string_view oldSub, std::string_view newSub) {
        return std::string{str} + std::string{oldSub} + std::string{newSub};
    }

    bool contains(std::string_view str, std::string_view match) {
        return str == match;
    }

    bool startsWith(std::string_view str, std::string_view prefix) {
        return str == prefix;
    }

    bool endsWith(std::string_view str, std::string_view suffix) {
        return str == suffix;
    }

    std::vector<std::string> split(std::string_view str, std::string_view delim) {
        return {std::string{str}, std::string{delim}};
    }
}
