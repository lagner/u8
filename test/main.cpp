#include <iostream>
#include <string>
#include <u8.h>
#include <gtest/gtest.h>

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
    auto cs = u8::normalize(x, u8::normalize_type::nfc);
    ASSERT_EQ(cs.size(), 7);
    auto ds = u8::normalize(x, u8::normalize_type::nfd);
    ASSERT_EQ(ds.size(), 8);
}

TEST(u8_test, split) {
    std::string x(u8" pos is specified, the position pos, ignoring before pos");
    auto res = u8::split(x, ",");
    ASSERT_EQ(res.size(), 3);
    ASSERT_EQ(res.front(), u8" pos is specified");
    ASSERT_EQ(res.back(), u8" ignoring before pos");

    res = u8::split(x, " ");
    ASSERT_EQ(res.size(), 9);

    res = u8::split(x, "specified");
    ASSERT_EQ(res.size(), 2);
}

TEST(u8_test, at) {
    std::string x(u8"façade");
    ASSERT_EQ(u8::at(x, 0), u8"f");
    ASSERT_EQ(u8::at(x, 2), u8"ç");

    std::string y(u8"ПриВет");
    ASSERT_EQ(u8::at(y, 0), u8"П");
    ASSERT_EQ(u8::at(y, 2), u8"и");
}

TEST(u8_test, converter) {
    std::u32string s32(U"ПриВет");
    auto res = u8::from_utf_32(s32);
    ASSERT_TRUE(u8::equals(res, u8"ПриВет"));

    std::u16string s16(u"ПриВет");
    res = u8::from_utf_16(s16);
    ASSERT_TRUE(u8::equals(res, u8"ПриВет"));
}

int main(int argc, char **argv) {
    u8::locale_guard loc("");
    (void)loc;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
