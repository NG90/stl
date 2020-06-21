#include "transform.hpp"

#include <algorithm>
#include <iostream>

std::map<int, std::string> removeDuplicateAndTranformToMap(
    std::list<std::string> uniqueList,
    std::deque<int> uniqueDeque) {
    uniqueList.sort();
    uniqueList.erase(std::unique(uniqueList.begin(), uniqueList.end()), uniqueList.end());

    std::sort(uniqueDeque.begin(), uniqueDeque.end());
    uniqueDeque.erase(std::unique(uniqueDeque.begin(), uniqueDeque.end()), uniqueDeque.end());

    std::map<int, std::string> result{};

    if (uniqueDeque.size() != uniqueList.size()) {
        return result;
    }

    std::transform(uniqueDeque.begin(),
                   uniqueDeque.end(),
                   uniqueList.begin(),
                   std::inserter(result, result.end()),
                   [](const auto& deqEl, const auto listEl) {
                       return std::make_pair(deqEl, listEl);
                   });
    return result;
}
