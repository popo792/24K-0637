#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile("data_records.txt");
    outFile << "Record 1\n";
    outFile << "Record 2\n";
    outFile << "Record 3\n";
    outFile << "Record 4\n";
    outFile.close();

    std::streampos offset = 9 + 9;

    std::ifstream inFile("data_records.txt");
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    inFile.seekg(offset, std::ios::beg);
    std::string line;
    std::getline(inFile, line);

    std::cout << "Third record: " << line << std::endl;

    inFile.close();
    return 0;
}