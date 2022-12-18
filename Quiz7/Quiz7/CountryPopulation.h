#pragma once
#include <iostream>
#include <string>

class CountryPopulation
{
public:
	std::string GetName() { return Name; }
	int GetPopulationEarly() { return PopulationEarly; }
	int GetPopulationLater() { return PopulationLater; }
	int GetGrowth() { return Growth; }

	CountryPopulation(std::string name, int populationEarly, int populationLater, int growth)//only constructor with data because in this case we don't want manual inputs
	{
		Name = name;
		PopulationEarly = populationEarly;
		PopulationLater = populationLater;
		Growth = growth;
	}
	std::string Info()
	{
		return "Name: " + Name +
			"\nPopulation 1973: " + std::to_string(PopulationEarly) +
			"\nPopulation 2023: " + std::to_string(PopulationLater) +
			"\nGrowth: " + std::to_string(Growth) + "\n\n";
	}
	double GrowthPercentage()
	{
		double ratio = (double)PopulationLater / PopulationEarly;
		double percentage = (ratio - 1) * 100;
		return percentage;
	}
private:
	std::string Name;
	int PopulationEarly;
	int PopulationLater;
	int Growth;
};

