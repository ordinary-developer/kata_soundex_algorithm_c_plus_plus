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

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
    // ARRANGE - ACT - ASSERT
    ASSERT_THAT(soundex.encode("Dcdlb").length(), testing::Eq(4u));
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters) {
    // ARRANGE - ACT - ASSERT
    ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHyYcdl"), testing::Eq("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {
    // ARRANGE - ACT - ASSERT
    ASSERT_THAT(soundex.encodedDigit('b'), 
            testing::Eq(soundex.encodedDigit('f')));
    ASSERT_THAT(soundex.encodedDigit('c'),
            testing::Eq(soundex.encodedDigit('g')));
    ASSERT_THAT(soundex.encodedDigit('d'),
            testing::Eq(soundex.encodedDigit('t')));

    ASSERT_THAT(soundex.encode("Abfcgdt"), testing::Eq("A123"));
}

TEST_F(SoundexEncoding, UppercasesFirstLetter) {
    // ARRANGE - ACT - ASSERT
    ASSERT_THAT(soundex.encode("abcd"), testing::StartsWith("A"));
}



