#include "Dictionary.h"
#include <fstream>

bool iequals(const std::string& a, const std::string& b)
{
    return std::equal(a.begin(), a.end(),
                      b.begin(), b.end(),
                      [](char a, char b) {
                          return tolower(a) == tolower(b);
                      });
}

Dictionary::Dictionary()
{
}

Dictionary::~Dictionary()
{
}

int Dictionary::getVocabularySize()
{
    return dictionary.size();
}

bool Dictionary::loadDictionaryFromFile(std::string filePath)
{
    std::ifstream file;
    std::string word;
    file.open(filePath);
    if(file.is_open())
    {
        while (!file.eof())
        {
            file >> word;
            dictionary.push_back(word); 
        }
        file.close();
        return true;
    }
    else 
        return false;
}
bool Dictionary::isWord(std::string word)
{
    bool isWord = false;
    for (auto w: dictionary)
    {
        std::string w2 = w + ".";
        std::string w3 = w + ",";
        std::string w4 = w + "?";
        std::string w5 = w + ";";
        std::string w6 = w + ":";
        if (iequals(word, w) || iequals(word, w2)  || iequals(word, w3)  || iequals(word, w4)  || iequals(word, w5)  || iequals(word, w6))
            isWord = true;
    }
    return isWord;
}