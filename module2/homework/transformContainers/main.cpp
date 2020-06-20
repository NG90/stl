#include "transformContainers.hpp"
#include <iostream>


int main(){
    auto list = std::list<std::string> {"hej", "hi", "bonzur", "jaotao", "bymcycy", "hej"};
    auto deq = std::deque<int> {1, 2, 3, 4, 5};
    auto rezult = removeDuplicateAndTranformToMap(list, deq);
    for(auto el : rezult){
        std::cout << el.first << " " << el.second << std::endl;
    }
    return 0;
}