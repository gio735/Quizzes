// Quiz7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <tuple>
#include <algorithm>
#include "CountryPopulation.h"

void ObjectVersion() 
{
    /*std::vector<CountryPopulation> countries;
    std::tuple<std::string, int, int, int> tempParams;
    std::ifstream myReader("Countries.txt");
    while (myReader >> std::get<0>(tempParams) >> std::get<1>(tempParams) >> std::get<2>(tempParams) >> std::get<3>(tempParams))
    {
        countries.push_back(CountryPopulation(std::get<0>(tempParams), std::get<1>(tempParams), std::get<2>(tempParams), std::get<3>(tempParams)));
    }
    std::vector<std::pair<CountryPopulation, double>> percentages(countries.size());
    for (int i = 0; i < countries.size(); i++)
    {
        auto tempPair = std::make_pair(countries[i], countries[i].GrowthPercentage());
        percentages[i] = tempPair;
    }
    auto compareByGrowth = [](std::pair<CountryPopulation, double> a, std::pair<CountryPopulation, double> b) {return a.second < b.second;};
    auto maxPercentage = *std::ranges::max_element(percentages, compareByGrowth);
    auto minPercentage = *std::ranges::min_element(percentages, compareByGrowth);
    std::ranges::sort(countries, [](CountryPopulation a, CountryPopulation b) {return a.GetPopulationLater() < b.GetPopulationLater();});
    std::cout << "Sorted countries:\n\n";
    for (auto element : countries)
    {
        std::cout << element.Info();
    }
    std::cout << "Smallest population growth:\n\n";
    std::cout << minPercentage.first.Info();
    std::cout << "Highest population growth:\n\n";
    std::cout << maxPercentage.first.Info();*/
}
int main()
{
    std::vector<CountryPopulation> countries;
    std::tuple<std::string, int, int, int> tempParams;
    std::ifstream myReader("Countries.txt");
    while (myReader >> std::get<0>(tempParams) >> std::get<1>(tempParams) >> std::get<2>(tempParams) >> std::get<3>(tempParams))
    {
        countries.push_back(CountryPopulation(std::get<0>(tempParams), std::get<1>(tempParams), std::get<2>(tempParams), std::get<3>(tempParams)));
    }
    std::vector<std::pair<CountryPopulation, double>> percentages;
    for (int i = 0; i < countries.size(); i++)
    {
        auto tempPair = std::make_pair(countries[i], countries[i].GrowthPercentage());
        percentages.push_back(tempPair);
    }
    auto compareByGrowth = [](std::pair<CountryPopulation, double> a, std::pair<CountryPopulation, double> b) {return a.second < b.second;};
    auto maxPercentage = *std::ranges::max_element(percentages, compareByGrowth);
    auto minPercentage = *std::ranges::min_element(percentages, compareByGrowth);
    std::ranges::sort(countries, [](CountryPopulation a, CountryPopulation b) {return a.GetPopulationLater() < b.GetPopulationLater();});
    std::cout << "Sorted countries:\n\n";
    for (auto element : countries)
    {
        std::cout << element.Info();
    }
    std::cout << "Smallest population growth:\n\n";
    std::cout << minPercentage.first.Info();
    std::cout << "Highest population growth:\n\n";
    std::cout << maxPercentage.first.Info();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
