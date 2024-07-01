#include "Soundex.h"
#include <cctype>
#include <unordered_map>

const std::unordered_map<char, char> soundexTable = {
    {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
    {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, 
    {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
    {'D', '3'}, {'T', '3'},
    {'L', '4'},
    {'M', '5'}, {'N', '5'},
    {'R', '6'}
};

char getSoundexCode(char c) {
    c = toupper(c);
    auto it = soundexTable.find(c);
    return (it != soundexTable.end()) ? it->second : '0';
}

std::string getInitialSoundex(const std::string& name) {
    if (name.empty()) return "";
    return std::string(1, toupper(name[0]));
}

std::string padSoundex(std::string soundex) {
    while (soundex.length() < 4) {
        soundex += '0';
    }
    return soundex;
}

std::string generateSoundex(const std::string& name) {
    std::string soundex = getInitialSoundex(name);
    if (soundex.empty()) return soundex;

    char prevCode = getSoundexCode(soundex[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }

    return padSoundex(soundex);
}
