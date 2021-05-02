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
    //Read file names from a csv file
    ifstream fin("./Data/dictionary.csv",ios::in);
    string line;
    int count=0;
    Dictionary *wordList = new Dictionary[5000]();
    //Abandon the first row
    getline(fin,line);
    //Read the data and split them seperately
    while (getline(fin,line)) {
        //cout<<line<<endl;
        istringstream sin(line);
        vector<string> elements;
        string info;
        while (getline(sin,info,',')) {
            elements.push_back(info);
        }
        string wordChar=elements[2];
        wordList[count].wordID=stoi(wordChar);
        wordList[count].word=elements[0];
        count++;
    }
    fin.close();

    json appearList;
    ifstream shown("./Data/wordShownDocument.json",ios::in);
    appearList << shown;
    shown.close();
    for (int i=0;i<count;i++) {
        wordList[i].appearTitle=appearList[to_string(i)]["Shown in title"].get<set<int>>();
        wordList[i].appearDoc=appearList[to_string(i)]["Shown in content"].get<set<int>>();
    }

    return wordList;
}

int main() {
    Dictionary *dict=LoadDictionary();
    return 0;
}