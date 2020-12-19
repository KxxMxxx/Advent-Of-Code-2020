#include <iostream>

int main(int argc, char **argv)
{
    std::string line;
    int countOne;
    int countTwo;
    int countThree;
    int countFour;
    int countFive;

    int posOne = 1;
    int posTwo = 3;
    int posThree = 5;
    int posFour = 7;
    int posFive = 1;
    bool skip = false;

    std::getline(std::cin, line);   // skip first line
    int length = line.length();
    while (std::getline(std::cin, line)) {
        if (line[posOne % length] == '#') {
            countOne++;
        }
        if (line[posTwo % length] == '#') {
            countTwo++;
        }
        if (line[posThree % length] == '#') {
            countThree++;
        }
        if (line[posFour % length] == '#') {
            countFour++;
        }
        if (line[posFive % length] == '#' && !skip) {
            countFive++;
        }

        posOne += 1;
        posTwo += 3;
        posThree += 5;
        posFour += 7;
        posFive += 1;
        skip = !skip;
    }

    std::cout << (long) countOne * countTwo * countThree * countFour * countFive << std::endl;
    return 0;
}