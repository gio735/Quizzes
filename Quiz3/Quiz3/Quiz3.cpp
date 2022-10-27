#include <vector>
#include <iostream>

using namespace std;

int main()
{
	cout << "Please give real number or type \'+\' to get results\n";
	char chars[] = "";
	vector<double> numbers;
	vector<double> roots;
	while (true) 
	{
		cin >> chars;
		if (chars[0] == '+') break;
		numbers.push_back(atof(chars));
	}
	chars[0] = '0';
	cout << "Your inputs: ";
	for (double number : numbers) //prints out numbers while loading vector of roots at same time.
	{
		roots.push_back(sqrt(abs(number)));
		cout << number << " ";
	}
	cout << endl << "Roots of their modules: ";

	for (double root : roots)
	{
		cout << root << " ";
	}

	cout << endl << "Reference of first vector >> " << &numbers << "size: " << (sizeof(vector<double>) + sizeof(double)*numbers.size()) << " bits";
	cout << endl << "Reference of second vector >> " << &roots << "size: " << (sizeof(vector<double>) + sizeof(double) * roots.size()) << " bits";
	switch (numbers.size())
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		cout << "\n\nVector is too small!";
		break;
	default:
		cout << "\n\nApparantly I have no idea what size of vector is, but well, even if it was one element smaller my answer might have changed... So strange!";
	}
}

