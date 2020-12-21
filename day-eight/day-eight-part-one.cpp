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
    while (!calledInstructions.count(i)) {
        
        calledInstructions.insert(i);
        
        if (instructions[i].first == "acc") {
            acc += instructions[i].second;
            i++;
        } else if (instructions[i].first == "jmp") {
            i += instructions[i].second;
        } else {
            i++;
        }
        i = i % numInstructions;
    }

    std::cout << acc << std::endl;
}
