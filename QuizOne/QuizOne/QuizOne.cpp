

#include <iostream>
using namespace std;

void CharTakerAndSwapper()
{
    string tester = "";
    char first = ' ';
    char second = ' ';
    cout << "Give first symbol (if it's multiple first two will be taken)\n";
    cin >> tester;
    if (tester.size() == 1)
    {
        first = tester[0];
        cout << "\nGive second symbol (if it's multiple first will be taken)\n";
        cin >> tester;
        second = tester[0];
    }
    else
    {
        first = tester[0];
        second = tester[1];
    }
    
    cout << "Before swap:\n\nFirst -> " << first << "\nSecond -> " << second;
    swap(first, second);
    cout << "\n\nAfter swap:\n\nFirst -> " << first << "\nSecond -> " << second;
}

void PrinterOfValueOfTens()
{
    string checker = "";
    
    while (true) 
    {
        cout << "Give any numbet with two or more digit\n";
        bool failed = false;
        cin >> checker;
        int checkerSize = checker.size();
        if(checkerSize == 1)
        {
            cout << "Insufficient size of number (at least two digits)\n";
        }
        else if (checkerSize == 2) 
        {
            if (checker[0] == '-') 
            {
                continue;
            }
            else
            {
                for (char character : checker)
                {
                    if(!isdigit(character))
                    {
                        failed = true;
                        break;
                    }
                }
                if(failed || checker[0] == '0')
                {
                    cout << "That not actual number...\n";
                }
                else
                {
                    cout << "Value of tens is " << checker[checkerSize - 2];
                }
            }
        }
        else
        {
            if (checker[0] == '-')
            {
                for (int i = 1; i < checkerSize; i++)
                {
                    if (!isdigit(checker[i]))
                    {
                        failed = true;
                        break;
                    }
                }
                if (failed || checker[1] == '0')
                {
                    cout << "That not actual number...\n";
                }
                else
                {
                    cout << "Value of tens is " << checker[checkerSize - 2] << "\n";
                    return;
                }
            }
            else
            {
                for (char character : checker)
                {
                    if (!isdigit(character))
                    {
                        failed = true;
                        break;
                    }
                }
                if (failed || checker[0] == '0')
                {
                    cout << "That not actual number...\n";
                }
                else
                {
                    cout << "Value of tens in this number is " << checker[checkerSize - 2];
                    return;
                }
            }
        }
    }
}

int main()
{
    CharTakerAndSwapper();
    PrinterOfValueOfTens();
    return 0;
}


