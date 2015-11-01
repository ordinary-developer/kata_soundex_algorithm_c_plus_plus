#include "Soundex.cpp"

#include "gmock/gmock.h"

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    Soundex soundex;
    auto encoded = soundex.encode("A");
    ASSERT_THAT(encoded, testing::Eq("A"));
}

