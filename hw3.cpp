#include <iostream>
#include <string>
#include <vector>
//using vector to store the lines of input
std::vector<std::string> receiveLines() {
    std::string str;
    std::vector<std::string> Lines;
    while (std::getline(std::cin, str) && !str.empty()) {
        Lines.push_back(str);
    }
    return Lines;
}
//find character of each cases
std::string findCommon(std::string str1, std::string str2) {
    std::string answer = "";
    for(char a : str1) {
        for(char b : str2) {
            if(a == b) {
                answer = answer + a;
                break;
            }
        }
    }
    //return ordered string with bubble sort
    char c;
    for (int i = 0; i < answer.length() - 1; i++) {
        for (int j = 0; j < answer.length() - 1 - i; j++) { 
            if (answer[j] > answer[j + 1]) {
                c = answer[j];
                answer[j] = answer[j + 1];
                answer[j + 1] = c; 
            }
        }
    }
    //erase same part
    for (int i = 0; i < answer.length() - 1; i++) {
        if (answer[i] == answer[i + 1]) {
            answer.erase(i, 1); 
            i--;
        }
    }
    return answer;
}
void commonPermutations() {
    std::vector<std::string> lines = receiveLines();
    std::vector<std::string> results;
    for (size_t i = 0; i < lines.size(); i += 2) {
        std::string a = lines[i];
        std::string b = lines[i + 1];
        results.push_back(findCommon(a, b));
    }
    for (const auto& res : results) {
        std::cout << res << std::endl;
    }
    return;
}

int computDistance(std::string line) {
    int count;
    std::vector<int> result;
    size_t pos = line.find(" ");
    count = std::stoi(line.substr(0, pos));
    line = line.substr(pos + 1);
    while ((pos = line.find(" ")) != std::string::npos) {
        result.push_back(std::stoi(line.substr(0, pos))); 
        line.erase(0, pos + 1); 
    }
    // Capture the last number in `line`
    if (!line.empty()) {
        result.push_back(std::stoi(line));
    }
    std::sort(result.begin(), result.end());
    int position = result[count / 2];
    int totalDistance = 0;
    for (int address : result) {
        totalDistance += std::abs(address - position);
    }

    return totalDistance;
}
void VitosFamily() {
    std::vector<std::string> lines = receiveLines();
    int testCases = std::stoi(lines[0]);
    lines.erase(lines.begin()); 
    for(auto line: lines) {
        auto distance = computDistance(line);
        std::cout << distance << std::endl;
    }
    return;
}
int findMaxIndex(std::vector<int>& inputList, int n) {
    int max = inputList[0];
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {  
        if (inputList[i] > max) {
            max = inputList[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}
std::vector<int> flip(std::vector<int>& inputList, int flipNumber) {
    for (int i = 0; i < flipNumber / 2; ++i) {
        std::swap(inputList[i], inputList[flipNumber - i - 1]);
    }
    return inputList;
}


std::vector<int> parseLine(std::string line) {
    std::vector<int> result;
    size_t pos;
    while ((pos = line.find(" ")) != std::string::npos) {
        result.push_back(std::stoi(line.substr(0, pos))); 
        line.erase(0, pos + 1); 
    }
    // capture the last number in `line`
    if (!line.empty()) {
        result.push_back(std::stoi(line));
    }
    return result;
}
// Function to print a stack of pancakes
void print_list(const std::vector<int>& stack) {
    for (int pancake : stack) {
        std::cout << pancake << " ";
    }
    std::cout << std::endl;
}
std::vector<int> sortPancakes(std::vector<int>& inputList) {
    int n = inputList.size();
    std::vector<int> flips;

    for (int i = n; i > 1; --i) {
        
        int maxIndex = findMaxIndex(inputList, i);
        
        // Flip largest pancake to the top if it's not already there
        if (maxIndex != i - 1) {
            if (maxIndex != 0) {
                flip(inputList, maxIndex + 1);
                flips.push_back(n - maxIndex); 
            }
            // Flip largest pancake to its correct position
            flip(inputList, i);
            flips.push_back(n - (i - 1)); 
        }
    }

    flips.push_back(0); 
    print_list(flips);
    return flips;
}

void StackFlapjacks() {
    std::vector<std::string> pancakeStacks = receiveLines();

    for (const auto& pancakeStack : pancakeStacks) {
        std::vector<int> inputList = parseLine(pancakeStack);
        print_list(inputList);
        sortPancakes(inputList);
    }
    return;
}

