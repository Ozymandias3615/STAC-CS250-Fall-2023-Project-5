#include "Dogs.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

using namespace std;

Dogs::Dogs(const string& filename)
{
    // attempts to open file
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error. Could not open the file." << endl;
        exit(1);
    }

    string country;
    int population;

    while (inputFile >> country >> population) {
        countryPopulation[country] = population;
        m_dogPopulation += population;
    }

    inputFile.close();
}

int Dogs::getCountryPopulation(const string& country) {
    // Check if the country is in the map
    auto it = countryPopulation.find(country);
    if (it != countryPopulation.end()){
        cout << it->first;
        }
    else {
        throw runtime_error("Country not found.");
    }
}

int Dogs::getDogPopulation()
{
    return m_dogPopulation;
}

// menu to display options
void Dogs::menu() {
    int choice = 0;
    string country;
    int population;

    while (choice != 3) {
        try {
            cout << "Countries and Dogs" << endl;
            cout << "1. See the total number of dogs in the world" << endl;
            cout << "2. Enter a country name to see the country's dog population" << endl;
            cout << "3. Exit the program" << endl;
            cout << "Enter a number: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "The total population of dogs in the world is " << getDogPopulation() << endl;
                    break;

                case 2:
                    cout << "Enter a country name: ";
                    cin.ignore();  // Clear the newline character from the buffer
                    getline(cin, country);  // Use getline to read the entire line

                    try {
                        cout << "Number of dogs in " << country << ": " << getCountryPopulation(country) << endl;
                    } catch (const exception& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;

                case 3:
                    break;

                default:
                    cout << "Invalid number. Please try again." << endl;
            }
        } catch (const exception& e) {
            cerr << "An error occurred: " << e.what() << endl;
            exit(1);
        }
    }
}
