#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    /// do something
    for (int i =0; i != 4; ++i)
        v.push_back(i);
    
    while (!v.empty() && v.back() % 2 == 0)
        v.pop_back();

    return 0;
}