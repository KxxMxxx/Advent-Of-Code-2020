#include <iostream>
#include<unordered_set>

int main(int argc, char **argv)
{
    std::unordered_set<int> store;
    std::string line;
    while (std::getline(std::cin, line)) {
        int num = std::stoi(line);
        store.insert(num);
    }

    for (const int& num1: store) {
        for (const int&num2: store) {
            if (num1 != num2) {
                int remainder = 2020 - num1 - num2;
                if (store.find(remainder) != store.end()) {
                    std::cout << (num1 * num2 * remainder) << std::endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
