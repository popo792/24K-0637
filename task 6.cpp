#include <iostream>
#include <fstream>
#include <cstring>

struct InventoryItem {
    int itemID;
    char itemName[20];
};

int main() {
    InventoryItem itemOut;
    itemOut.itemID = 123;
    std::strncpy(itemOut.itemName, "Hammer", sizeof(itemOut.itemName));
    itemOut.itemName[sizeof(itemOut.itemName) - 1] = '\0';

    std::ofstream outFile("inventory.dat", std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening file for writing.\n";
        return 1;
    }
    outFile.write(reinterpret_cast<char*>(&itemOut), sizeof(InventoryItem));
    outFile.close();

    InventoryItem itemIn;
    std::ifstream inFile("inventory.dat", std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file for reading.\n";
        return 1;
    }
    inFile.read(reinterpret_cast<char*>(&itemIn), sizeof(InventoryItem));
    inFile.close();

    std::cout << "Loaded Item ID: " << itemIn.itemID << std::endl;
    std::cout << "Loaded Item Name: " << itemIn.itemName << std::endl;

    return 0;
}