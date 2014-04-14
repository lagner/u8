#include <cassert>
#include <iostream>
#include <iterator>
#include <boost/locale.hpp>
#include <boost/algorithm/string.hpp>
#include "u8.h"

using namespace std;
using namespace boost::locale::boundary;

typedef std::string::const_iterator CIter;

namespace u8 {

locale_guard::locale_guard(const std::string& loc) {
    using namespace boost::locale;
    generator gen;
    std::locale new_loc = gen(loc);
    loc_ = std::locale::global(new_loc);
    std::cin.imbue(new_loc);
    std::cout.imbue(new_loc);
}

locale_guard::~locale_guard() {
    std::locale::global(loc_);
    std::cin.imbue(loc_);
    std::cout.imbue(loc_);
}

// ---------------------------------------------------------------------------------------------------

size_t size(const string& str) {
    segment_index<std::string::const_iterator> map(character, str.begin(), str.end());
    return std::distance(map.begin(), map.end());
}

string at(const string &str, size_t index) {
    segment_index<CIter> map(character, str.begin(), str.end());
    segment_index<CIter>::iterator it = map.begin();
    std::advance(it, index);
    return it->str();
}

string to_upper(const string& str) {
    cout << boost::algorithm::to_upper_copy(str) << endl;
    return boost::locale::to_upper(str);
}

string to_lower(const string& str) {
    return boost::locale::to_lower(str);
}

string to_title(const string& str) {
    return boost::locale::to_title(str);
}

std::vector<std::string> split(const string& str, const string& devider) {
    return std::vector<std::string> { str, devider };
}

bool equals(const string& x, const string& y, compare_type type) {
    using namespace boost::locale;
    using lt = boost::locale::collator_base::level_type;

    bool res = (0 == use_facet<collator<char>>(std::locale()).compare(static_cast<lt>(type), x, y));
    return res;
}

string normalize(const string& str) {
    return boost::locale::normalize(str, boost::locale::norm_nfkc);
}

} /* namespace u8 */
