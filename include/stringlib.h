/// \author Tim Quelch

#ifndef STRINGLIB_H
#define STRINGLIB_H

#include <string>
#include <string_view>
#include <vector>

namespace string {
    /// Returns a string in all upper case
    /// \param str a string
    /// \returns str converted to upper case
    std::string toUpper(std::string_view str);

    /// Returns a string in all lower case
    /// \param str a string
    /// \returns str converted to lower case
    std::string toLower(std::string_view str);

    /// Removes any trailing or leading white space
    /// \param str a string
    /// \returns str without leading or trailing whitespace
    std::string trimWhitespace(std::string_view str);

    /// Compares two string
    /// \param one a string
    /// \param two another string
    /// \returns TODO
    int compare(std::string_view one, std::string_view two);

    /// Compares two string while ignoring case
    /// \param one a string
    /// \param two another string
    /// \returns TODO
    int compareIgnoreCase(std::string_view one, std::string_view two);

    /// Replace all occurences of a substring with a different substring
    /// \param str a string
    /// \param oldSub the substring to replace
    /// \param newSub the substring to replace oldSub with
    /// \returns str with all occurences of oldSub replaced with newSub
    std::string replace(std::string_view str, std::string_view oldSub, std::string_view newSub);

    /// Check if a string contains a substring
    /// \param str a string
    /// \param match the substring to check
    /// \returns true if str contains match
    bool contains(std::string_view str, std::string_view match);

    /// Check if a string starts a substring
    /// \param str a string
    /// \param prefix the substring to check
    /// \returns true if str starts with match
    bool startsWith(std::string_view str, std::string_view prefix);

    /// Check if a string ends a substring
    /// \param str a string
    /// \param suffix the substring to check
    /// \returns true if str ends with match
    bool endsWith(std::string_view str, std::string_view suffix);

    /// Split a string around a specified substring
    /// \param str a string
    /// \param delim the substring to split str around
    /// \returns the split string
    std::vector<std::string> split(std::string_view str, std::string_view delim);
}

#endif
