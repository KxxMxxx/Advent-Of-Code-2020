#include <iostream>

int main(int argc, char **argv)
{
    int count = 0;

    std::string input;
    while (std::getline(std::cin, input, ' ')) {
        int dashpos = input.find('-');
        int firstPos = std::stoi(input.substr(0, dashpos)) - 1;
        int secondPos = std::stoi(input.substr(dashpos + 1, input.length() - dashpos)) - 1;

        std::getline(std::cin, input, ' ');
        char policy = input[0];

        std::getline(std::cin, input, '\n');
        int length = input.length() - 1;
        if (firstPos < 0 || secondPos > length) {
            continue;
        } else {
            bool firstPosBool = policy == input[firstPos];
            bool secondPosBool = policy == input[secondPos];
            if (firstPosBool != secondPosBool) {
                count++;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}
