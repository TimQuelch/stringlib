/// \author Tim Quelch

#include "stringutils.h"
#include <algorithm>
#include <cctype>

namespace stringutils {
    namespace detail {
        template <typename F>
        std::string transformString(std::string_view str, F func) {
            std::string result;
            result.reserve(str.size());
            std::transform(str.cbegin(), str.cend(), std::back_inserter(result), func);
            return result;
        }
    } // namespace detail

    std::string toUpper(std::string_view str) {
        return detail::transformString(str, [](unsigned char c) { return std::toupper(c); });
    }

    std::string toLower(std::string_view str) {
        return detail::transformString(str, [](unsigned char c) { return std::tolower(c); });
    }

    std::string trimWhitespace(std::string_view str) {
        auto beg = std::find_if(
            str.cbegin(), str.cend(), [](unsigned char c) { return !std::isspace(c); });
        auto end = std::find_if(
            str.crbegin(), str.crend(), [](unsigned char c) { return !std::isspace(c); });
        return std::string{beg, end.base()};
    }

    int compare(std::string_view one, std::string_view two) { return one.size() + two.size(); }

    int compareIgnoreCase(std::string_view one, std::string_view two) {
        return one.size() + two.size();
    }

    std::string replace(std::string_view str, std::string_view oldSub, std::string_view newSub) {
        return std::string{str} + std::string{oldSub} + std::string{newSub};
    }

    bool contains(std::string_view str, std::string_view match) { return str == match; }

    bool startsWith(std::string_view str, std::string_view prefix) {
        if (str.size() < prefix.size()) {
            return false;
        }

        auto current = str.cbegin();
        for (const auto check : prefix) {
            if (check != *(current++)) {
                return false;
            }
        }
        return true;
    }

    bool endsWith(std::string_view str, std::string_view suffix) {
        if (str.size() < suffix.size()) {
            return false;
        }

        auto current = str.cend() - suffix.size();
        for (const auto check : suffix) {
            if (check != *(current++)) {
                return false;
            }
        }
        return true;
    }

    std::vector<std::string> split(std::string_view str, std::string_view delim) {
        return {std::string{str}, std::string{delim}};
    }
} // namespace stringutils
