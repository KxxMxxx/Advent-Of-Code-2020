#include <iostream>
#include <cmath>
#include <unordered_set>

int main()
{
    std::unordered_set<int> seatIds;
    std::string line;
    while (std::getline(std::cin, line)) {
        int vMin = 0;
        int vMax = 127;
        int hMin = 0;
        int hMax = 7;
        for (int i = 0; i < 7; i++) {
            int vRange = vMax - vMin + 1;
            if (line[i] == 'F') {
                vMax = vMax - vRange / 2;
            } else {
                vMin = vMin + vRange / 2;
            }
        }

        for (int j = 7; j < 10; j++) {
            int hRange = hMax - hMin + 1;
            if (line[j] == 'L') {
                hMax = hMax - hRange / 2;
            } else {
                hMin = hMin + hRange / 2;
            }
        }
        
        seatIds.emplace(vMax * 8 + hMax);
    }

    for (int i = 1; i < 127; i++) {
        for (int j = 0; j < 8; j++) {
            int seatId = i * 8 + j;
            
            if (!seatIds.count(seatId) && seatIds.count(seatId + 1) && seatIds.count(seatId - 1)) {
                std::cout << seatId << std::endl;
            }
        }
    }
    
    return 0;
}
