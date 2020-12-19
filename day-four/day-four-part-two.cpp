#include <iostream>
#include <regex>
#include <unordered_map>

bool isValid(const std::unordered_map<std::string, std::string>&);
void split(const std::string&, std::unordered_map<std::string, std::string>&);

int main(int argc, char **argv)
{
    std::string line;
    int count;
    std::unordered_map<std::string, std::string> tokens;
    
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

bool isValid(const std::unordered_map<std::string, std::string>& tokens)
{
    if (tokens.size() >= 7 && tokens.size() <= 8) {
        if (tokens.count("byr") && tokens.count("iyr") && tokens.count("eyr") && tokens.count("hgt") && 
            tokens.count("hcl") && tokens.count("ecl") && tokens.count("pid")) {
            
            bool birth = std::regex_match(tokens.at("byr"), std::regex("^19[2-9][0-9]|200[0-2]$"));
            bool issue = std::regex_match(tokens.at("iyr"), std::regex("^201[0-9]|2020$"));
            bool expire = std::regex_match(tokens.at("eyr"), std::regex("^202[0-9]|2030$"));
            bool height = std::regex_match(tokens.at("hgt"), std::regex("^((1[5-8][0-9]|19[0-3])cm)|((59|6[0-9]|7[0-6])in)$"));
            bool hair = std::regex_match(tokens.at("hcl"), std::regex("^#[0-9a-f]{6}$"));
            bool eye = std::regex_match(tokens.at("ecl"), std::regex("^(amb|blu|brn|gry|grn|hzl|oth){1}$"));
            bool passport = std::regex_match(tokens.at("pid"), std::regex("^[0-9]{9}$"));
            
            return birth && issue && expire && height && hair && eye && passport;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void split(const std::string& str, std::unordered_map<std::string, std::string>& tokens)
{
    int pos;
    int startPos = 0;
    int length = str.length();

    while (startPos < length + 1) {
        pos = str.find_first_of(' ', startPos);
        if (pos == std::string::npos) pos = length;

        int nextPos = startPos + 4;
        
        tokens.emplace(std::string(str.data() + startPos, 3), std::string(str.data() + nextPos, pos - nextPos));
        startPos = pos + 1;
    }
}
