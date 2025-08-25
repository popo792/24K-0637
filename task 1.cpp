#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("vehicles.txt");

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file 'vehicles.txt'." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Skip empty lines
        if (line.empty()) continue;

        if (line[0] == '#') continue;

        // Print the valid line
        std::cout << line << std::endl;
    }

    file.close();
    return 0;
}