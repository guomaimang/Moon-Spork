#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <set>
#include <vector>
//Use this header written by Yunfei to call "Dictionary" class
#include "dictionary.h"
//Use this MIT license third-party header to process json files
#include "../ThirdPartyHeaders/json.hpp"
//Setting the namespaces
using json = nlohmann::json;
using namespace std;

Dictionary* LoadDictionary() {
    Dictionary *wordList = new Dictionary[5000]();

    //Read the json to get where the word has appeared
    json appearList;
    ifstream shown("./Data/wordShownDocument.json",ios::in);
    appearList << shown;
    shown.close();
    for (int i=0;i<appearList.size();i++) {
        wordList[i].appearTitle=appearList[to_string(i)]["Shown in title"].get<set<int>>();
        wordList[i].appearDoc=appearList[to_string(i)]["Shown in content"].get<set<int>>();
        wordList[i].word=appearList[to_string(i)]["Word"];
        wordList[i].wordID=appearList[to_string(i)]["Word ID"];
    }

    return wordList;
}

int main() {
    Dictionary *dict=LoadDictionary();
    return 0;
}