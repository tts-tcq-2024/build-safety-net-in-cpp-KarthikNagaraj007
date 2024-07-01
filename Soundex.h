#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

std::string generateSoundex(const std::string& name);
std::string padSoundex(const std::string& soundex);
std::string buildInitialSoundex(const std::string& name);

#endif // SOUNDEX_H
