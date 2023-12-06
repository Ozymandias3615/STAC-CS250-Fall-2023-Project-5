#ifndef DOGS_H
#define DOGS_H
#include <string>
#include <unordered_map>

using namespace std;

class Dogs {
public:
    Dogs(const string& filename);

    int getDogPopulation();
    int countryDogPopulation();
    int getCountryPopulation(const string& country);
    void menu();

private:
    int m_dogPopulation;
    unordered_map<string, int> countryPopulation; // Uncommented the member variable
};

#endif // DOGS_H

