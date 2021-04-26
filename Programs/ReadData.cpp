/*
This function is used for read data from .json file in the "Data" folder.
It can read the files and process it in memory for future use.
*/
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include "../ThirdPartyHeaders/json.hpp"
#include "course.h"
using json = nlohmann::json;
using namespace std;

void ReadData() {
    cout<<123;
    cout<<456;
    ifstream names("./Data/fileNames.csv",ios::in);
    string fileName[100];
    int count=0;
    if (!names) cout<<"Error\n";
    getline(names,fileName[count]);
    while (fileName[count]!="") {
        //cout<<fileName[count];
        count++;
        getline(names,fileName[count]);
    }
    ifstream courseJson;
    Course *subject[100];
    for (int i=0;i<count;i++) {
        string jsonName="./Data/pre-processed/";
        json fileData;
        jsonName+=fileName[i];
        courseJson.open(jsonName,ios::in);
        fileData << courseJson;
        //cout<<fileData<<endl<<endl;
        courseJson.close();
        //Save data to course object
        //subject[i]->SetCode(fileData["Subject Code"]);
        subject[i]->SetID(i);
        //subject[i]->SetLevel(fileData["Subject Level"]);
        //subject[i]->SetCredit(fileData["Subject Level"]);
        //subject[i]->SetTitle(fileData["Subject Title"]);
        subject[i]->SetTitleMap(fileData["Subject Title Words List"]);
        cout<<fileData["Subject Title Words List"];
    }
}

int main() {
    ReadData();
    return 0;
}