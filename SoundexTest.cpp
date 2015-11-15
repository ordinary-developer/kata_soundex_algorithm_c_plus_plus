#include "Soundex.cpp"

#include "gmock/gmock.h"

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    // arrange 
    Soundex soundex;
    // act
    auto encoded = soundex.encode("A");
    // assert
    ASSERT_THAT(encoded, testing::Eq("A000"));
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    // [arrange]
    Soundex soundex;
    // [act]
    auto encoded = soundex.encode("I");
    // [assert]
    ASSERT_THAT(encoded, testing::Eq("I000"));
}


