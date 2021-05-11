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
#include "search.cpp"
#include "DisplayResult4.cpp"
#include "input.cpp"
//Setting the namespaces
using json = nlohmann::json;
using namespace std;
int main() {
    DisplayResult(search(InputCleaning(InitialInput())));
    cout<<"Press ENTER to exit";
    cin.get();
    cin.get();
    return 0;
    
}