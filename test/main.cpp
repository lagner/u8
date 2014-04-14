#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include <u8.h>

using namespace std;

TEST(u8_test, equals) {
    ASSERT_TRUE(u8::equals("Façade", "facade", u8::compare_type::ignore_accent_case));
    ASSERT_TRUE(u8::equals("Hello", "hellO", u8::compare_type::ignore_case));
    ASSERT_TRUE(u8::equals("grüßEN", "GRÜßEN", u8::compare_type::ignore_case));

    // is it right?
    ASSERT_FALSE(u8::equals("grüßEN", "GRÜSSEN", u8::compare_type::ignore_case));
    ASSERT_FALSE(u8::equals("façade", "facade", u8::compare_type::ignore_case));
}

TEST(u8_test, to_lower) {
    std::string x(u8"привет");
    std::string y(u8::to_lower(u8"ПриВет"));
    ASSERT_EQ(x, y);
}

TEST(u8_test, normalize) {
    std::string x(u8"façade");
    std::string y(u8"facade");
    ASSERT_EQ(u8::normalize(x), y);
}

int main(int argc, char **argv) {
    u8::locale_guard loc("");
    (void)loc;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
