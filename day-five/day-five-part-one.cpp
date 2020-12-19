#include <iostream>
#include <cmath>

int main()
{
    int maxId = -1;
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
        int seatId = vMax * 8 + hMax;
        if (seatId > maxId) {
            maxId = seatId;
        }
    }

    std::cout << maxId << std::endl;
    return 0;
}
