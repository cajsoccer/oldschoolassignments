#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <vector>
#include <string>

class Dictionary
{
private: 
    std::vector <std::string> dictionary;
public:
    Dictionary();
    ~Dictionary();
    int getVocabularySize();
    bool loadDictionaryFromFile(std::string filePath);
    bool isWord(std::string word);
};

#endif // DICTIONARY_H
