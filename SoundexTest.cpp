#include "Soundex.cpp"

#include "gmock/gmock.h"

class SoundexEncoding: public testing::Test {
    public:
        Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    // arrange - act - assert
    ASSERT_THAT(soundex.encode("A"), testing::Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    // [arrange] - [act] - [assert]
    ASSERT_THAT(soundex.encode("I"), testing::Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
    // [ARRANGE] - [ACT] - [ASSERT]
    ASSERT_THAT(soundex.encode("Ax"), testing::Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
    // arrange - act - assert
    ASSERT_THAT(soundex.encode("A#"), testing::Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
    // ARRANGE - ACT - ASSERT
    ASSERT_THAT(soundex.encode("Acdl"), testing::Eq("A234"));
}

