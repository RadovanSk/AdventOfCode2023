#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int answer(std::string& str) {
    int found;
    int red = 0;
    int green = 0;
    int blue = 0;
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
                    if(red < found) {
                        red = found;
                    }
                }

                else if(colour.substr(0, 5) == "green") {
                    if(green < found) {
                        green = found;
                    }
                }

                else if(colour.substr(0, 4) == "blue") {
                    if(blue < found) {
                        blue = found;
                    }
                }
            }
        }
    }

    return red * green * blue;
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