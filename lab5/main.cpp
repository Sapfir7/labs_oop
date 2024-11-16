#include <iostream>
#include <map>
#include "./src/Aloctr.cpp"
#include "./src/Vector2.cpp"

int main() {
    std::map<int, int, std::less<int>, mai::allocator<std::pair<const int, int>, 10>> custom_map;

    custom_map.insert({0, 1});
    custom_map.insert({1, 2});
    custom_map.insert({2, 3});

    for (const auto& [key, value] : custom_map) {
        std::cout << key << " -> " << value << "\n";
    }

    std::cout << "-----------------------------------------\n";

    MyVector::Vector<int, mai::allocator<int, 10>> custom_vector;
    for (int i = 0; i < 10; ++i) {
        custom_vector.push_back(i);
    }

    for (const auto& value : custom_vector) {
        std::cout << value << "\n";
    }

    return 0;
}
