#include <iostream>

int main(int argc, char **argv)
{
    std::string line;
    int count;
    int pos = 3;

    std::getline(std::cin, line);   // skip first line
    int length = line.length();
    while (std::getline(std::cin, line)) {
        if (line[pos % length] == '#') {
            count++;
        }
        pos += 3;
    }

    std::cout << count << std::endl;
    return 0;
}
