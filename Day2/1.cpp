#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int answer(std::string& str) {
    int ans;
    int found;
    int red = 0;
    int green = 0;
    int blue = 0;
    bool check = false;
    size_t endid = str.find(':');
    std::string colour;
    std::string id =  str.substr(5, endid - 5);
    std::stringstream numbers;
    std::string tmp;
    str.replace(0, endid, " ");

    numbers << str;

    while(!numbers.eof()) {
        numbers >> tmp;

        if(std::stringstream(tmp) >> found) {
            if(numbers >> colour) {
                if(colour.substr(0, 3) == "red") {
                    red = found;
                }

                else if(colour.substr(0, 5) == "green") {
                    green = found;
                }

                else if(colour.substr(0, 4) == "blue") {
                    blue = found;
                }

                if(red > 12 || green > 13 || blue > 14) {
                    check = true;
                }

                else if(colour[colour.length() - 1] == ';') {
                    red = 0;
                    green = 0;
                    blue = 0;
                }
            }
        }
    }

    if(!check) {
        ans = stoi(id);
    }

    else {
        ans = 0;
    }

    return ans;
}

int main() {
    std::string line;
    std::ifstream myfile;
    int sum = 0;
    myfile.open("../ok.txt");

    if(myfile.is_open()) {
        while(true) {
            std::getline(myfile, line);
            sum += answer(line);

            if(myfile.eof()) {
                break;
            }
        }
    }

    std::cout << sum;
}

