#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <u8.h>

using namespace std;

TEST(u8_test, words_equal) {
    ASSERT_TRUE(u8::equals("Hello", "hellO", u8::compare_type::ignore_case));
}

TEST(u8_test, words_tolower) {
    std::string x(u8"привет");
    std::string y(u8::to_lower(u8"ПриВет"));
    ASSERT_EQ(x, y);
}

int main(int argc, char **argv) {
    u8::locale_guard loc("");
    (void)loc;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
