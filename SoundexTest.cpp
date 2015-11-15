#include "Soundex.cpp"

#include "gmock/gmock.h"

class SoundexEncoding: public testing::Test {
    public:
        Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    // arrange - act
    auto encoded = soundex.encode("A");
    // assert
    ASSERT_THAT(encoded, testing::Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    // [arrange - act]
    auto encoded = soundex.encode("I");
    // [assert]
    ASSERT_THAT(encoded, testing::Eq("I000"));
}


