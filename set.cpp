#include "set.h"

void Set::insert(int element) {
    elements[element] = true;
}

void Set::remove(int element) {
    elements.erase(element);
}

bool Set::exists(int element) {
    return elements.count(element) != 0;
}

int Set::size() {
    return elements.size();
}

void Set::print() {
    std::vector<int> keys;
    for (std::map<int, bool>::const_iterator it = elements.begin(); it != elements.end(); ++it) {
        keys.push_back(it->first);
    }
    std::cout << "Set: { ";
    for (int i = 0; i < keys.size(); i++) {
        std::cout << keys[i];
        if (i < keys.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;
}
