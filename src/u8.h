#pragma once
#include <string>
#include <vector>
#include <locale>
#include <boost/locale.hpp>

namespace u8 {

struct locale_guard {
    locale_guard(const std::string& loc = "en_US.UTF-8");
    ~locale_guard();
private:
    std::locale loc_;
};

enum class compare_type {
    ignore_accent_case = boost::locale::collator_base::primary,
    ignore_case,
    ignore_punctuation,
    representation,
    code_points
};

/*
 * @method size
 * returns the size of string in terms of user readable letters
 */
size_t size(const std::string& str);

/*
 * @method at
 * returns a letter in index position
 */
std::string at(const std::string& str, size_t index);

/*
 * @method to_upper
 * returns new string in the uppercase
 */
std::string to_upper(const std::string& str);

/*
 * @method to_lower
 * returns new string in the lower case
 */
std::string to_lower(const std::string& str);

/*
 * @method to_title
 */
std::string to_title(const std::string& str);

/*
 * @method split
 * returns the number of strings from devided str
 */
std::vector<std::string> split(const std::string& str, const std::string& devider);

/*
 * @method equals
 * returns true if strings are equal
 */
bool equals(const std::string& x, const std::string& y,
            compare_type type = compare_type::representation);

} /* namespace u8 */
