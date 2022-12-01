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
        }switch (word[word.size() - 2])
        {
        case '.':
        case '!':
        case '?':
            return true;//For cases where sentence ends in quote
            break;
        }
        return false;
    };
    auto isPersonalPronoun = [&isEndOfSentence](string word)
    {
        string personalPronouns[] = { "I", "me", "Me", "you", "You", "he", "He", "him", "Him", "she", "She", "her", "Her", "it", "It", "we", "We", "us", "Us", "they", "They", "them", "Them" };
        //going through all pronouns until one of them is found and then checked if it's actual pronoun or substring of other world while also considering it as end of the sentence.
        //Note: In case of wrong reference (personal pronouns) actual targets can be used in array. If that the case, please make sure to add both cases as std::string.find() is key sensitive.
        for (auto pronoun : personalPronouns)
        {
            if (word.find(pronoun) != std::string::npos)
            {
                if (word.size() > pronoun.size())

                {
                    if (isEndOfSentence(word))
                    {
                        if (word.size() == pronoun.size() + 1)
                        {
                            return true;
                        }
                        else if (word.size() == pronoun.size() + 2 && word[word.size() - 2] == '?' || word.size() == pronoun.size() + 2 && word[word.size() - 2] == '!') //check for "?!" and "!?"
                        {
                            return true;
                        }
                        else if (word.size() == pronoun.size() + 2 && word[word.size() - 2] == '.' && word[word.size() - 1] == '"' || word.size() == pronoun.size() + 2 && word[word.size() - 2] == '?' && word[word.size() - 1] == '"' || word.size() == pronoun.size() + 2 && word[word.size() - 2] == '!' && word[word.size() - 1] == '"')//checks if personal pronoun seems longer due to quote
                        {
                            return true;
                        }
                        else if (word.size() == pronoun.size() + 3 && word[word.size() - 3] == '.' || word.size() == pronoun.size() + 4 && word[word.size() - 4] == '.') //checks for "..." and same sign, but in quote
                        {
                            return true;
                        }
                    }
                }
                else return true;
            }
        }
        return false;
    };
    int sentenceCount = count_if(words.begin(), words.end(), isEndOfSentence);
    int wordCount = words.size();
    int personalPronounCount = count_if(words.begin(), words.end(), isPersonalPronoun);
    cout << "There are:\n" << sentenceCount << " - Sentence(s)\n" << wordCount << " - Word(s)\n" << personalPronounCount << " - Personal pronouns";
    return 0;
}
