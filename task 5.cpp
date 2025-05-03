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

        if (type == "AutonomousCar" && colonPos != std::string::npos) {
            std::string valueStr = extraData.substr(colonPos + 1);
            float softwareVersion = std::stof(valueStr);
            std::cout << "Software Version (float): " << softwareVersion << std::endl;

        } else if (type == "ElectricVehicle" && colonPos != std::string::npos) {
            std::string valueStr = extraData.substr(colonPos + 1);
            int batteryCapacity = std::stoi(valueStr);
            std::cout << "Battery Capacity (int): " << batteryCapacity << std::endl;

        } else if (type == "HybridTruck") {
            size_t cargoColon = extraData.find(':');
            size_t pipePos = extraData.find('|');
            size_t batteryColon = extraData.rfind(':');

            if (cargoColon != std::string::npos && pipePos != std::string::npos && batteryColon != std::string::npos) {

                std::string cargoStr = extraData.substr(cargoColon + 1, pipePos - cargoColon - 1);
                int cargo = std::stoi(cargoStr);

                std::string batteryStr = extraData.substr(batteryColon + 1);
                int battery = std::stoi(batteryStr);

                std::cout << "Cargo Capacity (int): " << cargo << std::endl;
                std::cout << "Battery Capacity (int): " << battery << std::endl;
            } else {
                std::cout << "Invalid HybridTruck ExtraData format." << std::endl;
            }

        } else {
            std::cout << "Unknown vehicle type: " << type << std::endl;
        }

        std::cout << "---------------------------" << std::endl;
    }

    file.close();
    return 0;
}