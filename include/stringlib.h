/// \author Tim Quelch

#include <string>
#include <string_view>
#include <vector>

namespace string {
    std::string toUpper(std::string str);
    std::string toUpper(std::string&& str);

    std::string toLower(std::string str);
    std::string toLower(std::string&& str);

    std::string trimWhitespace(std::string str);
    std::string trimWhitespace(std::string&& str);

    int compare(std::string_view one, std::string_view two);
    int compareIgnoreCase(std::string_view one, std::string_view two);

    std::string replace(std::string str, std::string_view oldSub, std::string_view newSub);
    std::string replace(std::string&& str, std::string_view oldSub, std::string_view newSub);

    bool contains(std::string_view str, std::string_view match);
    bool startsWith(std::string_view str, std::string_view prefix);
    bool endsWith(std::string_view str, std::string_view suffix);

    std::vector<std::string> split(std::string_view str, std::string_view delim);
}
