#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
//Use this header written by Yunfei to call "Dictionary" class
#include "dictionary.h"
//Use this MIT license third-party header to process json files
#include "../ThirdPartyHeaders/json.hpp"
//Setting the namespaces
using json = nlohmann::json;
using namespace std;

//This function constructs a 'Dictionary' instance to store words list
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

//This function constructs a map to find word id by word
map<string,int> WordToID(Dictionary *words) {
    int i=0;
    map<string,int> hashTable;
    while (words[i].wordID!=-1){
        hashTable[words[i].word]=words[i].wordID;
        i++;
    }
    return hashTable;
}
/* Test Function
int main() {
    Dictionary *dict=LoadDictionary();
    map<string,int> wordHashTable=WordToID(dict);
    vector<string> testWords={"expected","value","principles","testforfailtofindtheword"};
    map<string,int> ::iterator object;;
    for (std::vector<string>::iterator it = testWords.begin(); it != testWords.end(); ++it) {
        object=wordHashTable.find(*it);
        if (object!=wordHashTable.end()) {
        cout << "The ID of "<<object->first << " is "<<object->second<<endl;
        }
        else {
            cout << "Cannot find the ID of "<<*it<<endl;
        }
        
    }
    return 0;
}
*/