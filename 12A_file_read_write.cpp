#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outputFile("data.txt"); 

    if (outputFile.is_open()) {
        outputFile << "Hello, this is some data written to a text file!\n";
        outputFile << "More data on the next line.\n";
        outputFile << "And even more data on another line.\n";

        outputFile.close();
        std::cout << "Data has been written to data.txt successfully.\n";
    } else {
        std::cerr << "Error: Unable to open file for writing.\n";
        return 1; 
    }

    std::ifstream inputFile("data.txt"); 

    if (inputFile.is_open()) {
        std::string line;
        std::cout << "Data read from data.txt:\n";
        while (std::getline(inputFile, line)) {
            std::cout << line << '\n'; 
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file for reading.\n";
        return 1; 
    }

    return 0;
}

