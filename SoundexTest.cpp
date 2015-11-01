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
    ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHyYcdl"), testing::Eq("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {
    ASSERT_THAT(soundex.encodedDigit('b'), 
                testing::Eq(soundex.encodedDigit('f')));
    ASSERT_THAT(soundex.encodedDigit('c'), 
                testing::Eq(soundex.encodedDigit('g')));
    ASSERT_THAT(soundex.encodedDigit('d'), 
                testing::Eq(soundex.encodedDigit('t')));

    ASSERT_THAT(soundex.encode("Abfcgdt"), testing::Eq("A123"));
}

TEST_F(SoundexEncoding, UppercasesFirstLetter) {
    ASSERT_THAT(soundex.encode("abcd"), testing::StartsWith("A"));
}
