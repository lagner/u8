#ifndef U8_H
#define U8_H

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
    ignore_accent_case  = boost::locale::collator_base::primary,
    ignore_case         = boost::locale::collator_base::secondary,
    ignore_punctuation  = boost::locale::collator_base::tertiary,
    representation      = boost::locale::collator_base::quaternary,
    code_points         = boost::locale::collator_base::identical
};

enum class normalize_type {
    nfd     = boost::locale::norm_nfd,
    nfc     = boost::locale::norm_nfc,
    nfkd    = boost::locale::norm_nfkd,
    nfkc    = boost::locale::norm_nfkc
};

/*
 * @method size
 * returns the number of letters in string, not bytes
 */
size_t size(const std::string& str);

/*
 * @method at
 * returns a letter in index position. Counting begins from 0
 */
std::string at(const std::string& str, size_t index);

/*
 * @method to_upper
 * returns new string in the upper case
 */
std::string to_upper(const std::string& str);

/*
 * @method to_lower
 * returns new string in the lower case
 */
std::string to_lower(const std::string& str);

/*
 * @method to_title
 * every word in returned new string were capitalized
 */
std::string to_title(const std::string& str);

/*
 * @method split
 * returns the strings collection created from str
 */
std::vector<std::string> split(const std::string& str, const std::string& devider);

/*
 * @method equals
 * returns true if strings are equal
 */
bool equals(const std::string& x, const std::string& y,
            compare_type type = compare_type::representation);

/*
 * @method normalize
 * returns new normalized string
 */
std::string normalize(const std::string& str, normalize_type type = normalize_type::nfc);

/*
 * @method from_utf_32
 * returns new string using utf-8 charset
 */
std::string from_utf_32(const std::wstring& str);

std::string from_utf_32(const std::u32string& str);

/*
 * @method from_utf_16
 */
std::string from_utf_16(const std::u16string& str);

} /* namespace u8 */

#endif
