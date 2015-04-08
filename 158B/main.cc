#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

#include <cstdlib>

int main() {
    std::string number;
    std::getline(std::cin, number);
    int n = atoi(number.c_str());

    std::string line;
    std::getline(std::cin, line);

    std::stringstream ss;
    ss << line;

    std::string segment;
    std::map<int, int> groups;

    groups[1] = 0;
    groups[2] = 0;
    groups[3] = 0;
    groups[4] = 0;

    int count = 0;
    while (std::getline(ss, segment, ' ')) { 
        int x = atoi(segment.c_str());
        groups[x]++;
    }

    // 2,2
    // 3,1
    // 2,1,1
    // 1,1,1,1

    // scheduling problem
    // we need to fit this things into a box

    // all fours go on their own
    count += groups[4];

    // 2s can go with 2s
    count += groups[2] / 2;
    groups[2] = groups[2] % 2;

    // match 3 with 1s
    int min = std::min(groups[3], groups[1]);

    count += min;
    groups[3] -= min;
    groups[1] -= min;
    
    if (groups[3] > 0) {
        // add the 3s
        count += groups[3];

        // can't fix the 2s with 1s
        count += groups[2];
    } else if (groups[1] > 0) {

        // 2 1 1
        if (groups[2] == 1) {
            if (groups[1] >= 2) {
                groups[1] -= 2;
            } else {
                groups[1] = 0;
            }
            count++;
        }

        // 1 1 1 1
        count += groups[1] / 4;
        if (groups[1] % 4 != 0) {
            count++;
        }
    } else {
        if (groups[2] == 1) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}

