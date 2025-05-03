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

        std::cout << "ID: " << id << "\nType: " << type << "\nYear: " << year << std::endl;

        size_t colonPos = extraData.find(':');
        if (colonPos != std::string::npos) {
            std::string valueStr = extraData.substr(colonPos + 1);

            if (type == "AutonomousCar") {
                float softwareVersion = std::stof(valueStr);
                std::cout << "Software Version (float): " << softwareVersion << std::endl;
            } else if (type == "ElectricVehicle") {
                int batteryCapacity = std::stoi(valueStr);
                std::cout << "Battery Capacity (int): " << batteryCapacity << std::endl;
            }
        } else {
            std::cout << "No valid ExtraData format found." << std::endl;
        }

        std::cout << "---------------------------" << std::endl;
    }

    file.close();
    return 0;
}