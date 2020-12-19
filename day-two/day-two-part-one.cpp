#include <iostream>

int main(int argc, char **argv)
{
    int count = 0;

    std::string input;
    while (std::getline(std::cin, input, ' ')) {
        int dashpos = input.find('-');
        int min = std::stoi(input.substr(0, dashpos));
        int max = std::stoi(input.substr(dashpos + 1, input.length() - dashpos));

        std::getline(std::cin, input, ' ');
        char policy = input[0];

        std::getline(std::cin, input, '\n');
        int numOccurrence = 0;
        for (auto character: input) {
            if (character == policy) {
                numOccurrence++;
            }
        }

        if (numOccurrence >= min && numOccurrence <= max) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
