#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string word;
    std::cin >> word;

    std::string result = word;

    for(int i = 1; i < word.length()-1; ++i) {
        for(int j = i+1; j < word.length(); ++j) {
            std::string firstPart = word.substr(0, i);
            std::string secondPart = word.substr(i, j-i);
            std::string thirdPart = word.substr(j);

            std::reverse(firstPart.begin(), firstPart.end());
            std::reverse(secondPart.begin(), secondPart.end());
            std::reverse(thirdPart.begin(), thirdPart.end());

            std::string newWord = firstPart + secondPart + thirdPart;
            result = std::min(result, newWord);
        }
    }

    std::cout << result;
    return 0;
}
