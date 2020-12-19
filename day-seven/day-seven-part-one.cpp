#include <iostream>
#include <regex>
#include <queue>
#include <unordered_set>
#include <unordered_map>

int BFSCount(std::unordered_map<std::string, std::unordered_set<std::string>>, std::string);

int main()
{
    std::string line;
    std::unordered_map<std::string, std::unordered_set<std::string>> adjList;
    while (std::getline(std::cin, line)) {
        std::smatch match;
        
        std::regex_search(line, match, std::regex("(\\b\\w*\\s\\w+\\b)\\sbags\\scontain"));
        std::string mainBag = match.str(1);

        std::unordered_set<std::string> subBags;
        while (std::regex_search(line, match, std::regex("(?:(?:\\s\\d\\s)(\\w*\\s\\w+)(?:\\sbag[s]*)[,|\\.])"))) {
            subBags.insert(match.str(1));
            line = match.suffix();
        }

        if (!subBags.empty()) {
            for (std::string bag: subBags) {
                if (adjList.count(bag)) {
                    adjList.at(bag).insert(mainBag);
                } else {
                    adjList.emplace(bag, std::unordered_set<std::string>{mainBag});
                }
            }
        }
    }
    std::cout << BFSCount(adjList, "shiny gold") << std::endl;
    return 0;
}

int BFSCount(std::unordered_map<std::string, std::unordered_set<std::string>> adjList, std::string root) {
    int count = 0;
    std::unordered_set<std::string> visited;
    std::queue<std::string> queue;

    visited.emplace(root);
    queue.push(root);
    while (!queue.empty()) {
        std::string vertex = queue.front();
        queue.pop();

        if (adjList.count(vertex)) {
            std::unordered_set<std::string> neighbours = adjList.at(vertex);
            for (std::string neighbour: neighbours) {
                if (!visited.count(neighbour)) {
                    visited.emplace(neighbour);
                    queue.push(neighbour);
                    count++;
                }
            }
        }
    }
    return count;
}
