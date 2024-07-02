#include "Soundex.h"
#include <unordered_map>
#include <cctype>

char getSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
    c = std::toupper(c);
    auto it = soundexMap.find(c);
    return (it != soundexMap.end()) ? it->second : '0';
}

bool isValidCode(char code, char prevCode) {
    return code != '0' && code != prevCode;
}

bool isSoundexLengthValid(const std::string& soundex) {
    return soundex.length() < 4;
}

std::pair<std::string, char> addSoundexCode(const std::string& soundex, char code, char prevCode) {
    std::string newSoundex = soundex;
    if (isValidCode(code, prevCode) && isSoundexLengthValid(soundex)) {
        newSoundex += code;
        prevCode = code;
    }
    return {newSoundex, prevCode};
}

std::string updateSoundex(const std::string& soundex, const std::string& name, char prevCode) {
    std::string newSoundex = soundex;
    for (size_t i = 1; i < name.size(); ++i) {
        char code = getSoundexCode(name[i]);
        auto result = addSoundexCode(newSoundex, code, prevCode);
        newSoundex = result.first;
        prevCode = result.second;
    }
    newSoundex.append(4 - newSoundex.size(), '0');
    return newSoundex;
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) {
        return "";
    }
    std::string soundex(1, std::toupper(name[0]));
    char prevCode = getSoundexCode(soundex[0]);
    return updateSoundex(soundex, name, prevCode);
}
