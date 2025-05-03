#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream file("vehicles.txt");

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file 'vehicles.txt'." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        std::istringstream ss(line);
        std::string type, id, name, yearStr, extraData, certification;

        std::getline(ss, type, ',');
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, yearStr, ',');
        std::getline(ss, extraData, ',');
        std::getline(ss, certification, ',');

        int year = std::stoi(yearStr);

        std::cout << "Vehicle Year (int): " << year << std::endl;

        std::cout << "Type: " << type << "\n"
                  << "ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "ExtraData: " << extraData << "\n"
                  << "Certification: " << certification << "\n"
                  << "---------------------------" << std::endl;
    }

    file.close();
    return 0;
}