
#include <iostream>
#include <vector>
using namespace std;

void MinInteger(int a, int b)
{
    cout << "Minimal between " << a << " and " << b << " is " << min(a, b) << "\n\n";
}
char max(vector<char> characters)
{
    char max = characters[0];
    for (char character : characters)
    {
        if (character > max)
        {
            max = character;
        }
    }
    return max;
}
void MaxBetweenThreeChar()
{
    vector<char> characters;
    string input;
    cout << "Give first character\n";
    cin >> input;
    characters.push_back(input[0]);
    cout << "Give second character\n";
    cin >> input;
    characters.push_back(input[0]);
    cout << "Give third character\n";
    cin >> input;
    characters.push_back(input[0]);
    cout << "Max value belongs to character \'" << max(characters) << "\'\n";
}
int main()
{
    MinInteger(6, 4);
    MaxBetweenThreeChar();
}
