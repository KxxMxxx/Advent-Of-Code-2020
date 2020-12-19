#include <iostream>

int main()
{
    int count = 0;
    std::string line;
    std::string answer = "abcdefghijklmnopqrstuvwxyz";
    while (true) {
        if (!std::getline(std::cin, line)) {
            count += answer.size();
            break;
        } else {
            if (line.empty()) {
                count += answer.size();
                answer = "abcdefghijklmnopqrstuvwxyz";
            } else {
                std::string temp;
                std::sort(line.begin(), line.end());
                std::sort(answer.begin(), answer.end());
                
                std::set_intersection(line.begin(), line.end(), answer.begin(), answer.end(), std::back_inserter(temp));
                answer = temp;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}