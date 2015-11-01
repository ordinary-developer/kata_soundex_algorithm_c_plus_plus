#include "Soundex.cpp"

#include "gmock/gmock.h"

class SoundexEncoding: public testing::Test {
    public:
        Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    auto encoded = soundex.encode("A");
    ASSERT_THAT(encoded, testing::Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureTreeDigits) {
    auto encoded = soundex.encode("I");
    ASSERT_THAT(encoded, testing::Eq("I000"));
}

