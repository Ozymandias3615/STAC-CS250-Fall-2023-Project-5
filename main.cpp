#include <iostream>
#include <fstream>
#include <unordered_map>
#include <stdexcept>
#include <string>

class Dogs {
private:
    std::unordered_map<std::string, int> countryPopulationMap;
    int totalDogsInWorld;

public:
    Dogs(const std::string& filename) {
        // Read data from the file and populate the hash table
        readDataFromFile(filename);
    }

    // Function to display the total number of dogs in the world
    void displayTotalDogsInWorld() const {
        std::cout << "Total number of dogs in the world: " << totalDogsInWorld << std::endl;
    }

    // Function to get the number of dogs in a specific country
    int getDogsInCountry(const std::string& country) const {
        auto it = countryPopulationMap.find(country);
        if (it != countryPopulationMap.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Country not found");
        }
    }

private:
    // Helper function to read data from the file and populate the hash table
    void readDataFromFile(const std::string& filename) {
        std::ifstream inputFile(filename);

        if (!inputFile.is_open()) {
            throw std::runtime_error("Unable to open the file.");
        }

        std::string line;
        while (std::getline(inputFile, line)) {
            size_t commaPos = line.find(",");
            if (commaPos != std::string::npos) {
                std::string country = line.substr(0, commaPos);
                int population = std::stoi(line.substr(commaPos + 1));
                countryPopulationMap[country] = population;
                totalDogsInWorld += population;
            }
        }

        inputFile.close();
    }
};

int main() {
    try {
        Dogs dogs("dogs_data.txt");  // Replace "dogs_data.txt" with the actual file name

        int choice;
        std::string country;

        do {
            // Display menu
            std::cout << "\n1. Display total number of dogs in the world";
            std::cout << "\n2. Find out how many dogs are in a specific country";
            std::cout << "\n0. Exit";
            std::cout << "\nEnter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    dogs.displayTotalDogsInWorld();
                    break;
                case 2:
                    std::cout << "Enter the country name: ";
                    std::cin >> country;
                    std::cout << "Number of dogs in " << country << ": " << dogs.getDogsInCountry(country) << std::endl;
                    break;
                case 0:
                    std::cout << "Exiting program." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }

        } while (choice != 0);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
