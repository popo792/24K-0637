#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("large_log.txt");
    outFile << "Line 1: System start\nLine 2: Sensor active\nLine 3: Data received\n";
    outFile.close();

    std::ifstream inFile("large_log.txt");
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    char buffer[11] = {};
    inFile.read(buffer, 10);
    std::cout << "Read data: " << buffer << std::endl;

    std::streampos pos = inFile.tellg();
    std::cout << "Current read position: " << pos << std::endl;

    inFile.close();
    return 0;
}