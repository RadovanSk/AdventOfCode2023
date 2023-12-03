#include <iostream>
#include <fstream>
#include <string>

std::string getnum(std::string str) {
    std::string sum;
    std::string first;
    std::string last;
    std::string words[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine",};
    bool count = false;

    for(int i = 0; i < 9; i++) {
        size_t search = str.find(words[i]);
        if(search < 500) {
            str.replace(search + 1, words[i].length() - 2, std::to_string(i + 1));
            i--;
        }
    }

    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 48 && str[i] <= 57 && !count) {
            count = true;
            first = str[i];
        }

        if(str[i] >= 48 && str[i] <= 57 && count) {
            last = str[i];
        }
    }

    sum = first + last;

    std::cout << str << "\n";

    return sum;
}

int main() {
    std::ifstream myfile;
    myfile.open("../yes.txt");

    std::string num;
    int sum = 0;

    if (myfile.is_open()) {
        while (true) {
            std::getline (myfile, num);
            std::cout << stoi(getnum(num)) << "\n";
            sum += stoi(getnum(num));

            if(myfile.eof()) {
                break;
            }
        }
    }

    std::cout << '\n' << sum;
}