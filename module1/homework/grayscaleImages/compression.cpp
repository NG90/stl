#include "compression.hpp"

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;
    for (const auto& line : bitmap) {
        for (auto it = line.cbegin(); it != line.cend(); ++it) {
            auto it2 = it;
            while (it2 != line.cend()) {
                int i = 1;
                if (*it2 == *(it2 + i++)) {
                    std::advance(it2, 1);
                } else if (*it2 != *(it2 + i)) {
                    break;
                }
            }
        }
    }
}
