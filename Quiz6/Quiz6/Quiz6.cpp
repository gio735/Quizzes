#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> words;
	string word;
	ifstream myReader("text.txt");
	while (myReader >> word) words.push_back(word);
	myReader.close();
	auto isEndOfSentence = [](string word)
	{
		switch (word[word.size() - 1])
		{
		case '.':
		case '!':
		case '?':
			return true;//Word is end of the sentence if it contains one of following symbols. If word has not any of them, it's not regarded as finished sentence even if it's end of the file!
			break;
		}switch (word[word.size() - 1])
		{
		case '.':
		case '!':
		case '?':
			return true;//For cases where sentence ends in quote
			break;
		}
		return false;
	};
	int maxPossibleNumber = 0;
	int minPossibleNumber = 0;
	auto personalNameCounter = [&isEndOfSentence, &maxPossibleNumber, &minPossibleNumber](const string& word, const string& previousWord)
	{
		//It's considered that writer uses perfect grammar, therefore first word of sentence is always capital character,
		//that why there is min and max Possible number, so we need two words to be clear and that why this lambda is not an predicate.

		if (isEndOfSentence(previousWord))
		{
			maxPossibleNumber++;
			return;
		}
		if (word[0] >= 'A' && word[0] <= 'Z' && word != "I")
		{
			maxPossibleNumber++;
			minPossibleNumber++;
			return;
		}
	};
	int sentenceCount = count_if(words.begin(), words.end(), isEndOfSentence);
	int wordCount = words.size();
	personalNameCounter(words[0], "."); // first word is bound to be capital so we give fake previousWord which is identified as end of sentence
	for (int i = 1; i < words.size(); i++)
	{
		personalNameCounter(words[i], words[i - 1]);
	}
	std::cout << "There are:\n" << sentenceCount << " - Sentence(s)\n" << wordCount << " - Word(s)\nPersonal names: " << minPossibleNumber << "-" << maxPossibleNumber;
	return 0;
}
