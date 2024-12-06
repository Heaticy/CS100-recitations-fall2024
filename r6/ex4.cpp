#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vs;
    /// do something
    
    for (const std::string &s : vs) 
    {
        for (char c : s)
            if (std::isupper(c))
                std::cout << c;
        std::cout << std::endl;
    }
    return 0;
}