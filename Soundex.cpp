#include "Soundex.h"
#include <cctype>
#include <unordered_map>

// Function to initialize the Soundex code map
std::unordered_map<char, char> initializeSoundexMap() {
    return {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
}

char getSoundexCode(char c, const std::unordered_map<char, char>& soundexMap) {
    c = toupper(c);
    auto it = soundexMap.find(c);
    return it != soundexMap.end() ? it->second : '0'; // For A, E, I, O, U, H, W, Y
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    static const auto soundexMap = initializeSoundexMap();
    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0], soundexMap);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i], soundexMap);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }

    while (soundex.length() < 4) {
        soundex += '0';
    }

    return soundex;
}

