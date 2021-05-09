/*
PLEASE START AT HERE
MAIN PROGRAM
*/
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
//Use this MIT license third-party header to process json files
#include "../ThirdPartyHeaders/json.hpp"
//Use this header written by Yunfei to call Course objects
#include "course.h"
#include "dictionary.h"
//Setting the namespaces
using json = nlohmann::json;
using namespace std;
int main() {
    Course *subjectInfo;
    subjectInfo=ReadData(); //Load subject information
    Dictionary *dict=LoadDictionary();
    map<string,int> wordHashTable=WordToID(dict); //Load word dictionary
    
}