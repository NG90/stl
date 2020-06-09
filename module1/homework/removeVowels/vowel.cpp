#include "vowel.hpp"

#include <algorithm>

std::vector<std::string> removeVowels(std::vector<std::string>& str) {
    constexpr size_t numOfVowels = 12;
    constexpr std::array<unsigned char, numOfVowels> vowels = {
        'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};
    for (auto& elStr : str) {
        for (const auto el : vowels) {
            elStr.erase(std::remove(elStr.begin(), elStr.end(), el), elStr.end());
        }
    }
    return str;
}
