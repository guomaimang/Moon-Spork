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
    /*
    -----ABANDONED CONTENT-----

    //Read file names from a csv file
    ifstream fin("./Data/dictionary.csv",ios::in);
    string line;
    int count=0;
    //Abandon the first row
    getline(fin,line);
    //Read the data and split them seperately
    while (getline(fin,line)) {
        //Split the line with character ','
        istringstream sin(line);
        vector<string> elements;
        string info;
        while (getline(sin,info,',')) {
            elements.push_back(info);
        }
        //write the word and its ID to the dictionary object
        string wordChar=elements[2];
        wordList[count].wordID=stoi(wordChar);
        wordList[count].word=elements[0];
        count++;
    }
    fin.close();
    */

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