#include "compression.hpp"

#include <algorithm>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(
    const std::array<std::array<uint8_t, width>, height>& bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> compressed;

    uint8_t colour = 0;
    int times = 0;

    for (const auto& line : bitmap) {
        colour = line.front();
        times = 0;
        for (const auto el : line) {
            if (el == colour) {
                ++times;
            } else {
                compressed.push_back(std::make_pair(colour, times));
                times = 1;
                colour = el;
            }
        }
        compressed.push_back(std::make_pair(colour, times));
    }
    return compressed;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& compressed) {
    std::array<std::array<uint8_t, width>, height> decompressed;

    size_t row = 0;
    size_t col = 0;

    for (const auto& [color, count] : compressed) {
        if (row < height) {
            for (size_t i = 0; i < count; i++) {
                decompressed[row][col] = color;
                if (col < width - 1) {
                    col++;
                } else {
                    col = 0;
                    row++;
                }
            }
        } else {
            break;
        }
    }

    return decompressed;
}
