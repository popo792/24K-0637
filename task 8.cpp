#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile("config.txt");
    outFile << "AAAAABBBBBCCCCC";
    outFile.close();

    std::fstream file("config.txt", std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open 'config.txt'." << std::endl;
        return 1;
    }

    file.seekp(5);

    file << "XXXXX";
    file.close();

    std::ifstream verifyFile("config.txt");
    std::string content;
    std::getline(verifyFile, content);
    verifyFile.close();

    std::cout << "Updated file content: " << content << std::endl;

    return 0;
}