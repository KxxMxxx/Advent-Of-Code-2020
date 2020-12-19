#include <iostream>
#include <unordered_set>

int main()
{
    int count = 0;
    std::string line;
    std::unordered_set<char> answers;
    while (true) {
        if (!std::getline(std::cin, line)) {
            count += answers.size();
            break;
        } else {
            if (line.empty()) {
                count += answers.size();
                answers.clear();
            } else {
                for (char& ans: line) {
                    answers.emplace(ans);
                }
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}