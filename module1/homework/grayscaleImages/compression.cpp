#include "compression.hpp"

#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressedBitmap{};

    for (const auto& el : bitmap) {
        compressedBitmap.push_back(std::make_pair(*begin(el), 1));
        for (auto iter = std::next(begin(el)); iter != end(el); ++iter) {
            if (*iter == compressedBitmap.back().first) {
                compressedBitmap.back().second++;
            } else {
                compressedBitmap.push_back(std::make_pair(*iter, 1));
            }
        }
    }
    return compressedBitmap;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(
    const std::vector<std::pair<uint8_t, uint8_t>>&) {
    std::array<std::array<uint8_t, width>, height> decompressedBitmap{};

    return decompressedBitmap;
}
