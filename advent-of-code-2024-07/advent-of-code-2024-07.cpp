// advent-of-code-2024-07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

bool isValid(std::string line, long long int test, long long int res) {
    if (line=="")
    {
        if (res==test)
        {
            return true;
        }
        return false;
    } 
    long long int nextInt= stoll(line.substr(0, line.find(' ')));
    if (line.find(' ')!= std::string::npos)
    {
        line = line.substr(line.find(' ') + 1);
    }
    else {
        line = "";
    }
    return isValid(line, test * nextInt, res) || isValid(line, test + nextInt, res);
}

int main()
{
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cout << "failed to open" << std::endl;
        return 1;
    }
    long long int s = 0;
    std::string line;
    while (getline(file, line)) {
        long long int res = stoll(line.substr(0, line.find(':')));
        line = line.substr(line.find(' ') + 1);
        long long int test = stoll(line.substr(0, line.find(' ')));
        line = line.substr(line.find(' ') + 1);
        if (isValid(line, test, res)) {
            s += res;
        }
    }
    std::cout << s;
}

