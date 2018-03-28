/// \author Tim Quelch

#include "stringutils.h"
#include <algorithm>
#include <cctype>
#include <functional>

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

    bool contains(std::string_view str, std::string_view match) {
        const auto res =
            std::search(str.cbegin(),
                        str.cend(),
                        std::boyer_moore_horspool_searcher(match.cbegin(), match.cend()));
        return res != str.cend();
    }

    bool startsWith(std::string_view str, std::string_view prefix) {
        if (str.size() < prefix.size()) {
            return false;
        }
        return std::string_view{str.cbegin(), prefix.size()} == prefix;
    }

    bool endsWith(std::string_view str, std::string_view suffix) {
        if (str.size() < suffix.size()) {
            return false;
        }
        return std::string_view{str.cend() - suffix.size(), suffix.size()} == suffix;
    }

    std::vector<std::string> split(std::string_view str, std::string_view delim) {
        std::vector<std::string> result;

        const auto searcher = std::boyer_moore_horspool_searcher(delim.cbegin(), delim.cend());

        auto current = str.cbegin();
        const auto end = str.cend();

        while (current < end) {
            const auto match = std::search(current, str.cend(), searcher);
            result.push_back({current, match});
            current = match + delim.size();
        }

        return result;
    }
} // namespace stringutils
