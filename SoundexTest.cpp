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

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
    ASSERT_THAT(soundex.encode("Ax"), testing::Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoreNonAlphabetics) {
    ASSERT_THAT(soundex.encode("A#"), testing::Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
    ASSERT_THAT(soundex.encode("Acdl"), testing::Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
    ASSERT_THAT(soundex.encode("Dcdlb").length(), testing::Eq(4u));
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters) {
    ASSERT_THAT(soundex.encode("Baeiouhycdl"), testing::Eq("B234"));
}
