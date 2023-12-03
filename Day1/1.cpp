#include <iostream>
#include <fstream>
#include <string>

std::string getnum(std::string str) {
    std::string sum;
    std::string first;
    std::string last;
    int count = 0;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 48 && str[i] <= 57 && count == 0) {
            count++;
            first = str[i];
        }

        if(str[i] >= 48 && str[i] <= 57 && count == 1) {
            last = str[i];
        }
    }
    sum = first + last;

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
            sum += stoi(getnum(num));

            if(myfile.eof()) {
                break;
            }
        }
    }

    std::cout << '\n' << sum;
}
