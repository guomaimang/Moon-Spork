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

Course* ReadData() {
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
    //Course *subject = new Course[100]();
    Course *subject = new Course[count]();
    for (int i=0;i<count;i++) {
        string jsonName="./Data/pre-processed/";
        json fileData;
        jsonName+=fileName[i];
        courseJson.open(jsonName,ios::in);
        fileData << courseJson;
        //cout<<fileData<<endl<<endl;
        courseJson.close();
        //Save data to course object
        subject[i].SetCode(fileData["Subject Code"]);
        subject[i].SetID(i);
        subject[i].SetLevel(fileData["Subject Level"]);
        subject[i].SetCredit(fileData["Subject Credit"]);
        subject[i].SetTitle(fileData["Subject Title"]);
        map<string,int> title,content,pre;
        title=fileData.at("Subject Title Words List").get<map<string,int>>();
        subject[i].SetTitleMap(title);
        content=fileData.at("Subject Content").get<map<string,int>>();
        subject[i].SetContent(content);
        pre=fileData.at("Subject Pre-requisite").get<map<string,int>>();
        subject[i].SetPreRequisite(pre);
    }
    return subject;
}

int main() {
    Course *data;
    data=ReadData();
    int a=
    cout<<data[1].GetID();
    for (int i=1;i<10;i++) {
        //cout<<data[i].GetCode()<<endl;
    }
    //delete[] test;
    return 0;
}