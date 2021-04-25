#include <iostream>
#include <fstream>
#include "ThirdPartyHeaders/json.hpp"
using namespace std;
using json = nlohmann::json; 
int main() {
    json testObj;
    ifstream in("./Data/pre-processed/COMP1001.json");
    testObj << in;
    cout<<testObj["Subject Code"];
    return 0;

}