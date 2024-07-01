#include "Soundex.h"
#include <cctype>
#include <unordered_map>

char getSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexCodes = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };

    c = toupper(c);
    auto it = soundexCodes.find(c);
    return (it != soundexCodes.end()) ? it->second : '0'; // For A, E, I, O, U, H, W, Y
}

// Helper function to pad the Soundex result to 4 characters
std::string padSoundex(const std::string& soundex) {
    std::string paddedSoundex = soundex;
    while (paddedSoundex.length() < 4) {
        paddedSoundex += '0';
    }
    return paddedSoundex;
}

std::string buildInitialSoundex(const std::string& name) {
    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }

    return soundex;
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";
    return padSoundex(buildInitialSoundex(name));
}
