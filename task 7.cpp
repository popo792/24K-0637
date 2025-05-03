#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("sensor_log.txt");

    if (!outFile.is_open()) {
        std::cerr << "Failed to open the file for writing." << std::endl;
        return 1;
    }

    outFile << "Sensor reading 1: 23.5 C\n";
    std::streampos pos1 = outFile.tellp();
    std::cout << "Write position after first line: " << pos1 << std::endl;

    outFile << "Sensor reading 2: 24.1 C\n";
    std::streampos pos2 = outFile.tellp();
    std::cout << "Write position after second line: " << pos2 << std::endl;

    outFile << "Sensor reading 3: 22.8 C\n";
    std::streampos pos3 = outFile.tellp();
    std::cout << "Write position after third line: " << pos3 << std::endl;

    outFile.close();
    return 0;
}