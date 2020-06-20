#include "transformContainers.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>

std::map<int, std::string> removeDuplicateAndTranformToMap(std::list<std::string> list, std::deque<int> deq){
    std::map<int, std::string> new_map;
    list.sort();
    auto it_list = std::unique(begin(list), end(list));
    list.erase(it_list, end(list));
    std::sort(begin(deq), end(deq));
    auto it_deq = std::unique(begin(deq), end(deq));
    deq.erase(it_deq, end(deq));

    if(deq.size() != list.size()){
        return new_map;
    }

    std::transform(begin(deq), end(deq), begin(list), std::inserter(new_map, new_map.end()), [](auto &deq, auto &list){
        return std::make_pair(deq, list);
    });  
    return new_map;
}