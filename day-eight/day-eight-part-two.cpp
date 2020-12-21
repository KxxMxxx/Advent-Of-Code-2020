#include <iostream>
#include <vector>
#include <unordered_set>

int main()
{
    int acc = 0;
    std::vector<std::pair<std::string, int>> instructions;
    std::unordered_set<int> calledInstructions;

    std::string firstInput;
    std::string secInput;
    while (std::getline(std::cin, firstInput, ' ')) {
        std::getline(std::cin,secInput);
        instructions.emplace_back(firstInput, std::stoi(secInput));
    }

    int numInstructions = instructions.size();

    int i = 0;
    while (true) {
        calledInstructions.insert(i);

        if (instructions[i].first == "acc") {
            acc += instructions[i].second;
            i++;
        } else {
            std::unordered_set<int> temp = calledInstructions;
            int tempAcc = acc;
            
            int j = i;
            if (instructions[i].first == "jmp") {
                i += instructions[i].second;
                j++;
            } else {
                i++;
                j += instructions[j].second;
            }

            while (!temp.count(j) && j < numInstructions) {
                temp.insert(j);
                if (instructions[j].first == "acc") {
                    tempAcc += instructions[j].second;
                    j++;
                } else if (instructions[j].first == "jmp") {
                    j+= instructions[j].second;
                } else {
                    j++;
                }
            }
            if (j >= numInstructions) {
                std::cout << tempAcc << std::endl;
                break;
            }
        }
    }
}
