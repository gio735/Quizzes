/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;
const double PI = acos(-1);
void PrintVector(const vector<double> target, const int perLine);
void GetCircleStats(const double radius, double& area, double& perimeter);

int main()
{
    vector<double> radiuses;
    ifstream myReader ("Radiuses.txt");
    double radius;
    while(myReader >> radius)
    {
        radiuses.push_back(radius);
    }
    vector<double> areas(radiuses.size());
    vector<double> perimeters(radiuses.size());
    for(int i = 0; i < radiuses.size(); i++)
    {
        GetCircleStats(radiuses[i], areas[i], perimeters[i]);
    }
    cout << "Radiuses:\n";
    PrintVector(radiuses, 5);
    cout << "Areas:\n";
    PrintVector(areas, 5);
    cout << "Perimeters:\n";
    PrintVector(perimeters, 5);
    
    double averageArea = accumulate (areas.begin(), areas.end(), 0.0) / areas.size();
    cout << "Average area: " << averageArea << "\n";
    auto moreThanHundred = [](double radius) {return radius > 100;};
    int moreThanHundredCount = 0;
    for(auto item : perimeters)
    {
        if(moreThanHundred(item)) moreThanHundredCount++;
    }
    cout << "There are " << moreThanHundredCount << " circles with perimeter more than 100";
}

void PrintVector(const vector<double> target, const int perLine)
{
    int i = 0;
    for(auto item : target)
    {
        if(i != 0 && i % perLine == 0) cout << "\n";
        i++;
        cout.width(5);
        cout << item << ", ";
    }
    cout << "\n";
}
void GetCircleStats(const double radius, double& area, double& perimeter)
{
    area = PI * radius * radius;
    perimeter = 2 * PI * radius;
}