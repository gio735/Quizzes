#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//Note: Our company is very very very very very very very very strict regarding income file format, so no, it's not possibly containing typo
enum Month 
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};
struct Income
{
    int Day;
    Month Month;
    int Year;
    __int64 Income;
};
void EnsureIsCreated();
vector<string> Split(string target)
{
    vector<string> words;
    string currentWord;
    bool added = false;
    for (char character : target)
    {
        added = false;
        if (character == ' ') 
        {
            words.push_back(currentWord);
            currentWord = "";
            continue;
        }
        currentWord += character;
    }
    if (!added) 
    {
        words.push_back(currentWord);
    }
    return words;
}
Income CreateModel(string data) 
{
    auto incomeData = Split(data);
    Income income;
    income.Day = stoi(incomeData[0]);
    income.Month = static_cast<Month>(stoi(incomeData[1]));
    income.Year = stoi(incomeData[2]);
    income.Income = stod(incomeData[3]);
    return income;
}
bool IsOver(Income income, double limit) 
{
    return income.Income > limit;
}
vector<Income> FilterByIncome(vector<Income> incomes, bool filter(Income, double), double limit)
{
    vector<Income> newVector;
    for (auto income : incomes)
    {
        if (filter(income, limit))
        {
            newVector.push_back(income);
        }
    }
    return newVector;
}
_int64 FullIncome(vector<Income> incomes)
{
    __int64 result = 0;
    for (auto income : incomes)
    {
        result += income.Income;
    }
    return result;
}
Income MostProfitableIn(vector<Income> incomes)
{
    Income emptyCheck;
    emptyCheck.Day = -1;
    emptyCheck.Year = -1;
    if (incomes.size() == 0) return emptyCheck;
    Income max = incomes[0];
    for (auto income : incomes)
    {
        if (income.Income > max.Income)
        {
            max = income;
        }
    }
    return max;
}
vector<Income> IncomesInTimeSpan(vector<Income> incomes, Month start, Month end)
{
    vector<Income> newIncomes;
    for (auto income : incomes)
    {
        if (income.Month >= start && income.Month <= end)
        {
            newIncomes.push_back(income);
        }
    }
    return newIncomes;
}
int main()
{
    EnsureIsCreated();
    vector<Income> incomeData;
    ifstream myReader("income.txt");
    string data;
    while (getline(myReader, data)) 
    {
        incomeData.push_back(CreateModel(data));
    }
    myReader.close();
    auto maxOfYear = MostProfitableIn(incomeData);
    auto springIncomes = IncomesInTimeSpan(incomeData, March, May);
    auto maxOfSpring = MostProfitableIn(springIncomes);
    double incomeOfYear = FullIncome(incomeData);
    double averagePerDay = incomeOfYear / 365;
    int countOfBetterDays = FilterByIncome(incomeData, IsOver, averagePerDay).size();
    cout << "The most profitable day of the year: " << maxOfYear.Day << "/" << maxOfYear.Month << "/" << maxOfYear.Year << "  " << maxOfYear.Income <<"$" <<
        "\nThe most profitabe day of the spring: " << maxOfSpring.Day << "/" << maxOfSpring.Month << "/" << maxOfSpring.Year << "  " << maxOfSpring.Income <<"$" <<
        "\nTotal income of the year: " << incomeOfYear << "$" <<
        "\nAverage income of the year: " << averagePerDay << "$" <<
        "\nDays with more than average income: " << countOfBetterDays;

}

void EnsureIsCreated()
{
    ofstream MyFile("income.txt");
    for (int i = 1; i <= 31; i++) 
    {
        MyFile << i << " " << static_cast<int>(January) << " " << "2022 " << rand() << endl;
    }
    for (int i = 1; i <= 28; i++)
    {
        MyFile << i << " " << static_cast<int>(February) << " " << "2022 " << rand() << endl;
    }
    for (int i = 1; i <= 31; i++)
    {
        MyFile << i << " " << static_cast<int>(March) << " " << "2022 " << rand() << endl;
    }
    for (int i = 1; i <= 30; i++)
    {
        MyFile << i << " " << static_cast<int>(April) << " " << "2022 " << rand() << endl;
    }
    for (int i = 1; i <= 31; i++)
    {
        MyFile << i << " " << static_cast<int>(May) << " " << "2022 " << rand() << endl;
    }
    for (int i = 1; i <= 30; i++)
    {
        MyFile << i << " " << static_cast<int>(June) << " " << "2022 " << rand() << endl;
    }
    for (int i = 1; i <= 31; i++)
    {
        MyFile << i << " " << static_cast<int>(July) << " " << "2022 " << rand() << endl;
    }
    for (int i = 1; i <= 31; i++)
    {
        MyFile << i << " " << static_cast<int>(August) << " " << "2022 " << rand() << endl;
    }
    for (int i = 1; i <= 30; i++)
    {
        MyFile << i << " " << static_cast<int>(September) << " " << "2022 " << rand() << endl;
    }
    for (int i = 1; i <= 31; i++)
    {
        MyFile << i << " " << static_cast<int>(October) << " " << "2022 " << rand() << endl;
    }
    for (int i = 1; i <= 30; i++)
    {
        MyFile << i << " " << static_cast<int>(November) << " " << "2022 " << rand() << endl;
    }
    for (int i = 1; i <= 30; i++)
    {
        MyFile << i << " " << static_cast<int>(December) << " " << "2022 " << rand() << endl;
    }
    MyFile << 31 << " " << static_cast<int>(December) << " " << "2022 " << rand();
}
