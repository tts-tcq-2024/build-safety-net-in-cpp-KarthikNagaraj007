#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, GeneratesCorrectSoundexForEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, PadsSoundexToFourCharacters) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("I"), "I000");
}

TEST(SoundexTest, GeneratesCorrectSoundexForValidName) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
    EXPECT_EQ(generateSoundex("Rubin"), "R150");
}

TEST(SoundexTest, IgnoresNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("R2obert"), "R163");
    EXPECT_EQ(generateSoundex("R!upert"), "R163");
    EXPECT_EQ(generateSoundex("Ru#bin"), "R150");
}

TEST(SoundexTest, GeneratesSameSoundexForSimilarNames) {
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Ashcroft"), "A261");
}

TEST(SoundexTest, HandlesUpperAndLowerCaseCharacters) {
    EXPECT_EQ(generateSoundex("Robert"), generateSoundex("robert"));
    EXPECT_EQ(generateSoundex("Rupert"), generateSoundex("RUPERT"));
    EXPECT_EQ(generateSoundex("Rubin"), generateSoundex("RuBiN"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
