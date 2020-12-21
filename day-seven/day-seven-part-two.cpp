#include <iostream>
#include <regex>
#include <set>
#include <unordered_map>

int DFSCount(std::string);

static std::unordered_map<std::string, std::set<std::pair<int, std::string>>> adjList;
static std::unordered_map<std::string, int> memMap;

int main()
{
    std::string line;
    while (std::getline(std::cin, line)) {
        std::smatch match;
        
        std::regex_search(line, match, std::regex("(\\b\\w*\\s\\w+\\b)\\sbags\\scontain"));
        std::string mainBag = match.str(1);

        std::set<std::pair<int, std::string>> subBags;
        while (std::regex_search(line, match, std::regex("(?:(\\s\\d\\s)(\\w*\\s\\w+)(?:\\sbag[s]*)[,|\\.])"))) {
            subBags.emplace(std::stoi(match.str(1)), match.str(2));
            line = match.suffix();
        }

        if (!subBags.empty()) {
            for (std::pair<int, std::string> bag: subBags) {
                adjList[mainBag].insert(bag);
            }
        }
    }

    std::cout << DFSCount("shiny gold") << std::endl;
    return 0;
}

int DFSCount(std::string vertex)
{
    if (!adjList.count(vertex)) {
        return 0;
    } else {
        int count = 0;
        std::set<std::pair<int, std::string>> neighbours = adjList[vertex];
        for (std::pair<int, std::string> neighbour: neighbours) {
            if (!memMap.count(neighbour.second)) {
                memMap[neighbour.second] = DFSCount(neighbour.second);
            }
            count += neighbour.first + neighbour.first * memMap[neighbour.second];
        }
        return count;
    }
}
