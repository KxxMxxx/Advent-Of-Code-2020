#include <iostream>
#include <unordered_set>

bool isValid(const std::unordered_set<std::string>&);
void split(const std::string&, std::unordered_set<std::string>&);

int main(int argc, char **argv)
{
    std::string line;
    int count;
    std::unordered_set<std::string> tokens;
    
    while (true) {
        if (!std::getline(std::cin, line)) {
            if (isValid(tokens)) count++;
            break;
        } else {
            if (line.empty()) {
                if (isValid(tokens)) count++;
                tokens.clear();
            } else {
                split(line, tokens);
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}

bool isValid(const std::unordered_set<std::string>& tokens)
{
    if (tokens.size() >= 7 && tokens.size() <= 8) {
        return tokens.count("byr") && tokens.count("iyr") && tokens.count("eyr") && tokens.count("hgt") && 
            tokens.count("hcl") && tokens.count("ecl") && tokens.count("pid");
    } else {
        return false;
    }
}

void split(const std::string& str, std::unordered_set<std::string>& tokens)
{
    int pos;
    int startPos = 0;
    int length = str.length();

    while (startPos < length + 1) {
        pos = str.find_first_of(' ', startPos);
        if (pos == std::string::npos) pos = length;

        tokens.emplace(str.data() + startPos, 3);
        startPos = pos + 1;
    }
}
